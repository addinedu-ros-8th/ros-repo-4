#include <rclcpp/rclcpp.hpp>
#include <opencv2/opencv.hpp>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <cstring>
#include <unordered_map>

#include <chrono>

class UdpImageSubscriber : public rclcpp::Node {
public:
  UdpImageSubscriber() : Node("udp_image_subscriber") {
    sockfd_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd_ < 0) {
      RCLCPP_ERROR(this->get_logger(), "Failed to create socket");
      rclcpp::shutdown();

      return;
    }

    server_addr_.sin_family = AF_INET;
    server_addr_.sin_addr.s_addr = INADDR_ANY;
    server_addr_.sin_port = htons(14555); 

    // 소켓 바인딩
    if (bind(sockfd_, (struct sockaddr*)&server_addr_, sizeof(server_addr_)) < 0) {
      RCLCPP_ERROR(this->get_logger(), "Failed to bind socket");
      close(sockfd_);
      rclcpp::shutdown();
      
      return;
    }
    
    // 스레드 
    receiver_thread_ = std::thread(&UdpImageSubscriber::receive_loop, this);
    RCLCPP_INFO(this->get_logger(), "UDP Node Start");
  }

  ~UdpImageSubscriber() {
    running_ = false;
    if (receiver_thread_.joinable()) {
      receiver_thread_.join();
    }
    if (sockfd_ >= 0) {
      close(sockfd_);
    }
    cv::destroyAllWindows();
  }

private:
  void receive_loop() {
    const size_t chunk_size = 10240;
    const size_t header_size = 15; 
    // header(1) + robot_id(1) + camera_id(1) + frame_num(4) + total_chunks(2) + chunk_idx(2) + chunk_data_size(4)
    std::vector<uint8_t> buffer(chunk_size + header_size);
    
    // 프레임별 청크
    std::unordered_map<uint32_t, std::vector<std::vector<uint8_t>>> frame_chunks;
    std::unordered_map<uint32_t, uint16_t> total_chunks_map;

    while (running_ && rclcpp::ok()) {
      // UDP 수신
      ssize_t received = recvfrom(sockfd_, buffer.data(), buffer.size(), 0, nullptr, nullptr);
      //RCLCPP_INFO(this->get_logger(), "Received %zu bytes", received);
      //RCLCPP_INFO(this->get_logger(), "buffer[11-14] hex: %X %X %X %X", buffer[11], buffer[12], buffer[13], buffer[14]);

      if (received < 0) {
        RCLCPP_ERROR(this->get_logger(), "Failed to receive data");
        continue;
      }

      if (buffer[0] != 0xAA) {
        RCLCPP_WARN(this->get_logger(), "Invalid header received");
        continue;
      }

      uint8_t robot_id = buffer[1];
      uint8_t camera_id = buffer[2];
      uint32_t frame_num = *reinterpret_cast<uint32_t*>(&buffer[3]);
      uint16_t total_chunks = *reinterpret_cast<uint16_t*>(&buffer[7]);
      uint16_t chunk_idx = *reinterpret_cast<uint16_t*>(&buffer[9]);
      uint32_t chunk_data_size = *reinterpret_cast<uint32_t*>(&buffer[11]);


      if (chunk_data_size > chunk_size) {
        RCLCPP_WARN(this->get_logger(), "Invalid chunk size: %u", chunk_data_size);
        continue;
      }

      // 청크 데이터 복사
      std::vector<uint8_t> chunk_data(buffer.begin() + header_size, buffer.begin() + header_size + chunk_data_size);
      
      // 프레임 청크 저장
      if (frame_chunks.find(frame_num) == frame_chunks.end()) {
        frame_chunks[frame_num] = std::vector<std::vector<uint8_t>>(total_chunks);
        total_chunks_map[frame_num] = total_chunks;
      }
      frame_chunks[frame_num][chunk_idx] = chunk_data;

      // 모든청크 확인
      bool all_received = true;
      for (const auto& chunk : frame_chunks[frame_num]) {
        if (chunk.empty()) {
          all_received = false;
          break;
        }
      }

      if (all_received) {
        // 이미지 데이터 조립
        std::vector<uint8_t> image_data;
        for (const auto& chunk : frame_chunks[frame_num]) {
          image_data.insert(image_data.end(), chunk.begin(), chunk.end());
        }

        // OpenCV 이미지 디코딩
        cv::Mat image = cv::imdecode(image_data, cv::IMREAD_COLOR);
        if (!image.empty()) {
          cv::imshow("Cccccccamera", image);
          cv::waitKey(1);
        } else {
          RCLCPP_WARN(this->get_logger(), "Failed to decode image for frame %u", frame_num);
        }

        frame_chunks.erase(frame_num);
        total_chunks_map.erase(frame_num);
      }
    }
  }

  int sockfd_ = -1;
  struct sockaddr_in server_addr_;
  std::thread receiver_thread_;
  bool running_ = true;
};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<UdpImageSubscriber>();
  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}

