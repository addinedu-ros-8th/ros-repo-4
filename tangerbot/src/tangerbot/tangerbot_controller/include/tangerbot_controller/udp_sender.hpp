// udp_sender.hpp
#pragma once

#include <opencv2/opencv.hpp>
#include <arpa/inet.h>
#include <cstdint>
#include <string>

#pragma pack(push,1)
struct PacketHeader {
    uint8_t  magic;        // 시작 마커(0xAA)
    uint8_t  robot_id;     // 로봇 식별자
    uint8_t  camera_id;    // 카메라 (0: left, 1: right)
    uint32_t frame_id;     // 프레임 번호
    uint16_t total_chunks; // 전체 청크 수
    uint16_t chunk_id;     // 현재 청크 번호(0~total_chunks-1)
    uint32_t chunk_size;   // 이 청크의 데이터 크기(byte)
};
#pragma pack(pop)

class UDPSender {
public:
    UDPSender(const std::string& remote_ip, uint16_t remote_port, uint8_t robot_id);
    ~UDPSender();

    void run(int left_cam_idx, int right_cam_idx);

private:
    void initSocket();

    int sockfd_;
    struct sockaddr_in dest_addr_;
    uint8_t robot_id_;
    uint32_t frame_counter_;
    static constexpr size_t MAX_UDP_PAYLOAD = 10240;
};
