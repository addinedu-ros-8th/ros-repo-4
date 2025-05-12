#pragma once
#include <cstdio> 
#include <atomic>
#include <array>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

namespace shm {
    constexpr const char* NAME = "/stereo_shm";
    constexpr size_t MAX_IMG  = 1 << 20;  // 1MB per image

    // 공유 메모리에 들어갈 구조체 (좌/우 각각)
    struct Slot {
        std::atomic<uint32_t> frame_id {0};  // 프레임 번호 (데이터 변경 감지용)
        std::atomic<uint32_t> size {0};      // 데이터 크기 (바이트)
        alignas(64) std::array<uint8_t, MAX_IMG> data;  // cpu 캐시라인 최적화를 위한 정렬
    };

    // 전체 공유 세그먼트 구조체
    struct Segment {
        Slot cam[2];  // cam[0]: left, cam[1]: right
    };

    // 공유 메모리 열기 (생성 또는 연결)
    inline Segment* open(bool create) {
        int fd = shm_open(NAME, create ? (O_CREAT | O_RDWR) : O_RDWR, 0666);
        if (fd == -1) {
            perror("shm_open failed");
            return nullptr;
        }
        if (create) {
            if (ftruncate(fd, sizeof(Segment)) == -1) {
                perror("ftruncate failed");
                close(fd); // 수정: 파일 디스크립터 닫기
                return nullptr;
            }
        }
        Segment* ptr = static_cast<Segment*>(mmap(nullptr, sizeof(Segment),
            PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
        close(fd); // 수정: 파일 디스크립터 닫기
        if (ptr == MAP_FAILED) {
            perror("mmap failed");
            return nullptr;
        }
        return ptr;
    }

    // 수정: 공유 메모리 해제 함수 추가
    inline void close(Segment* ptr) {
        if (ptr && ptr != MAP_FAILED) {
            if (munmap(ptr, sizeof(Segment)) == -1) {
                perror("munmap failed");
            }
        }
    }
}
