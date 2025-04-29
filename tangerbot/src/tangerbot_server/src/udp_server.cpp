// udp_server.cpp
#include "tangerbot_server/udp_server.h"

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>

UDPServer::UDPServer(const std::string ADDR, const int PORT) {
    this->ADDR = ADDR;
    this->PORT = PORT;
    sock = socket(AF_INET, SOCK_DGRAM, 0);
}

UDPServer::~UDPServer() {
    close(sock);
}

void UDPServer::start() {
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (sockaddr*)&server_addr, sizeof(server_addr));

    std::cout << "Starting UDP sever...\n";
    
    std::thread t(&UDPServer::listen_loop, this);
    t.join();
}

void UDPServer::listen_loop() {
    using namespace std;
    char buffer[65535];
    sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);
    while (true) {
        ssize_t received = recvfrom(sock, buffer, sizeof(buffer) - 1, 0,
                                    (sockaddr*)&client_addr, &client_len);
        if (received >= 6) {
            uint8_t header = buffer[0];
            uint8_t robot_id = buffer[1];
            uint8_t chunks = buffer[2];
            uint16_t frame_num;
            memcpy(&frame_num, buffer + 3, 2);
            uint8_t chunk_idx = buffer[5];
            
            cout << (int)chunk_idx << endl;
        }
    }
}


int main() {
    UDPServer udp_server = UDPServer("127.0.0.1", 8080);
    udp_server.start();
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
