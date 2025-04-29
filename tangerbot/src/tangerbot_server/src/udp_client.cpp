// udp_client.cpp
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

const int PORT = 8080;

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);  // 로컬 호스트로 전송

    char buffer[1024];
    buffer[0] = 0xAA;
    buffer[1] = 1;
    buffer[2] = 12;
    uint16_t frame_num = 12;
    memcpy(buffer + 3, &frame_num, 2);
    buffer[5] = 1;
    sendto(sock, buffer, 6, 0,
           (sockaddr*)&server_addr, sizeof(server_addr));

    std::cout << "메시지 전송 완료\n";

    close(sock);
    return 0;
}
