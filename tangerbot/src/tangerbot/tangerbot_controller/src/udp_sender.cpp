// udp_sender.cpp
#include "tangerbot_controller/udp_sender.hpp"
#include <unistd.h>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

UDPSender::UDPSender(const std::string& remote_ip, uint16_t remote_port, uint8_t robot_id)
: sockfd_(-1), robot_id_(robot_id), frame_counter_(0) {
    std::memset(&dest_addr_, 0, sizeof(dest_addr_));
    dest_addr_.sin_family = AF_INET;
    dest_addr_.sin_port = htons(remote_port);
    inet_pton(AF_INET, remote_ip.c_str(), &dest_addr_.sin_addr);
    initSocket();
}

UDPSender::~UDPSender() {
    if (sockfd_ >= 0) close(sockfd_);
}

void UDPSender::initSocket() {
    sockfd_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd_ < 0) {
        std::cerr << "Socket creation failed\n";
        std::exit(EXIT_FAILURE);
    }
}

void UDPSender::run(int left_cam_idx, int right_cam_idx) {
    cv::VideoCapture capL(left_cam_idx), capR(right_cam_idx);
    if (!capL.isOpened() || !capR.isOpened()) {
        std::cerr << "Failed to open cameras\n";
        return;
    }
    // 드라이버 버퍼에 지연된 프레임이 쌓이지 않도록 최소 크기로 설정
    capL.set(cv::CAP_PROP_BUFFERSIZE, 1);
    capR.set(cv::CAP_PROP_BUFFERSIZE, 1);

    cv::Mat frameL, frameR;
    std::vector<uchar> bufL, bufR;

    while (true) {
        capL.grab();
        capR.grab();
        capL.retrieve(frameL);
        capR.retrieve(frameR);
        if (frameL.empty() || frameR.empty()) break;

        // JPEG 인코딩
        cv::imencode(".jpg", frameL, bufL);
        cv::imencode(".jpg", frameR, bufR);

        uint32_t fid = frame_counter_++;

        // 좌/우 각각 청크 분할 및 전송
        for (int cam_id = 0; cam_id < 2; cam_id++) {
            auto& buf = (cam_id == 0 ? bufL : bufR);
            size_t bytes_left = buf.size();
            size_t offset = 0;
            size_t max_chunk = MAX_UDP_PAYLOAD - sizeof(PacketHeader);
            uint16_t total_chunks = static_cast<uint16_t>((bytes_left + max_chunk - 1) / max_chunk);

            for (uint16_t chunk_id = 0; chunk_id < total_chunks; chunk_id++) {
                size_t chunk_size = std::min(max_chunk, bytes_left);

                PacketHeader header;
                header.magic        = 0xAA;
                header.robot_id     = robot_id_;
                header.camera_id    = static_cast<uint8_t>(cam_id);
                header.frame_id     = fid;
                header.total_chunks = total_chunks;
                header.chunk_id     = chunk_id;
                header.chunk_size   = static_cast<uint32_t>(chunk_size);

                std::vector<uint8_t> packet(sizeof(header) + chunk_size);
                std::memcpy(packet.data(), &header, sizeof(header));
                std::memcpy(packet.data() + sizeof(header), buf.data() + offset, chunk_size);

                if (sendto(sockfd_, packet.data(), packet.size(), 0,
                    reinterpret_cast<sockaddr*>(&dest_addr_), sizeof(dest_addr_)) < 0) {
                    std::cerr << "sendto failed\n";
                }

                offset += chunk_size;
                bytes_left -= chunk_size;
            }
        }
    }
}

int main(int argc, char** argv) {
    std::string ip = "192.168.0.3";
    uint16_t port = 14555;
    uint8_t rid = 1;
    int left_idx = 0;
    int right_idx = 1;

    if (argc >= 6) {
        ip = argv[1];
        port = static_cast<uint16_t>(std::stoi(argv[2]));
        rid = static_cast<uint8_t>(std::stoi(argv[3]));
        left_idx = std::stoi(argv[4]);
        right_idx = std::stoi(argv[5]);
    } else {
        std::cout << "[INFO] Using default args: "
                  << ip << " " << port << " " << static_cast<int>(rid)
                  << " " << left_idx << " " << right_idx << std::endl;
    }

    UDPSender sender(ip, port, rid);
    sender.run(left_idx, right_idx);
    return 0;
}
