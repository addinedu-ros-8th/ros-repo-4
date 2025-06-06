#pragma once
#include <cstdint>
#include <cstdio>
#include <atomic>
#include <array>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

namespace shm {
    // Shared memory name and size
    constexpr const char* NAME = "/stereo_shm";
    constexpr size_t MAX_IMG = 1 << 20;  // 1MB per image

    // UDP packet header for frame chunking
#pragma pack(push, 1)
    struct PacketHeader {
        uint8_t  magic;         // magic value to validate packet
        uint8_t  robot_id;      // robot identifier
        uint8_t  camera_id;     // camera index (0 or 1)
        uint32_t frame_id;      // frame sequence number
        uint16_t total_chunks;  // total chunks for this frame
        uint16_t chunk_id;      // current chunk index
        uint32_t chunk_size;    // payload size in this chunk
    };
#pragma pack(pop)

    // Network constants for UDP reception
    constexpr int PORT = 14555;
    constexpr size_t MAX_PACKET = 10240;
    constexpr uint8_t MAGIC_VALUE = 0xAA;

    // Shared memory
    struct Slot {
        std::atomic<uint32_t> frame_id{0};  // frame number (for change detection)
        std::atomic<uint32_t> size{0};      // data size in bytes
        alignas(64) std::array<uint8_t, MAX_IMG> data;  // aligned buffer
    };

    // shared segment 메모리 
    struct Segment {
        Slot cam[3][3];  
        // 로봇 3대
        // cam[0]:left, cam[1]:right, cam[2]:picamera
    };

    // Open or create shared memory
    inline Segment* open(bool create) {
        int fd = shm_open(NAME, create ? (O_CREAT | O_RDWR) : O_RDWR, 0666);
        if (fd == -1) {
            perror("shm_open failed");
            return nullptr;
        }
        if (create) {
            if (ftruncate(fd, sizeof(Segment)) == -1) {
                perror("ftruncate failed");
                close(fd);
                return nullptr;
            }
        }
        void* addr = mmap(nullptr, sizeof(Segment), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        close(fd);
        if (addr == MAP_FAILED) {
            perror("mmap failed");
            return nullptr;
        }
        return reinterpret_cast<Segment*>(addr);
    }

    // Close shared memory segment
    inline void close(Segment* ptr) {
        if (ptr && ptr != MAP_FAILED) {
            if (munmap(ptr, sizeof(Segment)) == -1) {
                perror("munmap failed");
            }
        }
    }
}  // namespace shm
