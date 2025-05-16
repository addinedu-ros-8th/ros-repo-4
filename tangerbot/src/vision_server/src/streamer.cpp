#include <arpa/inet.h>
#include <thread>
#include <atomic>
#include <vector>
#include <unordered_map>
#include <unistd.h>
#include <csignal>

#include <opencv2/opencv.hpp>

#include <rclcpp/rclcpp.hpp>
#include "vision_server/shared_memory.hpp"

using shm::PacketHeader;
using namespace shm;

class UdpShmBridge : public rclcpp::Node {
public:
	UdpShmBridge()
	: Node("udp_shm_bridge"), running_(true)
	{
		// 파라미터 선언/획득
		declare_parameter<int>("port", 14555);
		port_ = this->get_parameter("port").as_int();

		// shared memory 열기
		shm_ptr_ = shm::open(true);
		if (!shm_ptr_) {
			RCLCPP_FATAL(get_logger(), "Failed to open shared memory");
			rclcpp::shutdown();
			return;
		}

		// UDP 소켓 초기화
		sockfd_ = socket(AF_INET, SOCK_DGRAM, 0);
		if (sockfd_ < 0) {
			RCLCPP_FATAL(get_logger(), "socket() failed");
			cleanup();
			rclcpp::shutdown();
			return;
		}
		server_addr_.sin_family = AF_INET;
		server_addr_.sin_addr.s_addr = INADDR_ANY;
		server_addr_.sin_port = htons(port_);

		if (bind(sockfd_, (sockaddr*)&server_addr_, sizeof(server_addr_)) < 0) {
			RCLCPP_FATAL(get_logger(), "bind() failed");
			cleanup();
			rclcpp::shutdown();
			return;
		}

		// UDP 전송 소켓 초기화

		dest_sockfd_ = socket(AF_INET, SOCK_DGRAM, 0);
		if (dest_sockfd_ < 0) {
			RCLCPP_FATAL(get_logger(), "socket() failed");
			cleanup();
			rclcpp::shutdown();
			return;
		}
		dest_addr_.sin_family = AF_INET;
		dest_addr_.sin_port = htons(dest_port_);
		inet_pton(AF_INET, dest_ip_, &dest_addr_.sin_addr);

		// 수신 스레드 시작
		recv_thread_ = std::thread(&UdpShmBridge::receiveLoop, this);

		// SIGINT 핸들러 등록
		signal(SIGINT, [](int){
			rclcpp::shutdown();
		});
	}

	~UdpShmBridge() override {
		running_ = false;
		if (recv_thread_.joinable()) recv_thread_.join();
		cleanup();

		cv::destroyAllWindows();
	}

private:
	void receiveLoop() {
	    constexpr size_t MAX_PACKET = 10240;
		const size_t HEADER_SIZE = 15; 

		// buffer
		std::vector<uint8_t> buffer(MAX_PACKET + HEADER_SIZE);
	    std::unordered_map<uint32_t, std::vector<std::vector<uint8_t>>> chunk_buffer[3];

	    while (rclcpp::ok() && running_) {
	        ssize_t n = recvfrom(sockfd_, buffer.data(), buffer.size(), 0, nullptr, nullptr);
	        if (n <= 0) continue;
			
	        auto *hdr = reinterpret_cast<PacketHeader*>(buffer.data());	// 헤더
			
			if (hdr->camera_id == 2) {
				// 바로 릴레이
				sendto(dest_sockfd_, buffer.data(), n, 0, reinterpret_cast<sockaddr*>(&dest_addr_), sizeof(dest_addr_));
			}

			// 시작비트 확인
	        if (hdr->magic != MAGIC_VALUE) {
	            std::cerr << "Invalid magic value: " << (int)hdr->magic << "\n";
	            continue;
	        }
			// 유효 카메라 id 확인
	        if (hdr->camera_id > 2) {
	            std::cerr << "Invalid camera_id: " << (int)hdr->camera_id << "\n";
	            continue;
	        }
			// 현재 청크번호, 총 청크갯수 비교 확인
	        if (hdr->chunk_id >= hdr->total_chunks) {
	            std::cerr << "Invalid chunk_id: " << hdr->chunk_id << " >= " << hdr->total_chunks << "\n";
	            continue;
	        }
			// 이번 청크 사이즈, 헤더제외 크기 비교 확인
	        if (hdr->chunk_size > (n - sizeof(PacketHeader))) {
	            std::cerr << "Invalid chunk_size: " << hdr->chunk_size << " > " << (n - sizeof(PacketHeader)) << "\n";
	            continue;
	        }
	
	        auto &buf_map = chunk_buffer[hdr->camera_id];
	        auto &chunks = buf_map[hdr->frame_id];
		
	        if (chunks.empty()) chunks.resize(hdr->total_chunks);
	        chunks[hdr->chunk_id] = std::vector<uint8_t>(buffer.data() + sizeof(PacketHeader), buffer.data() + n);
		
	        bool all_chunks_ready = true;
	        for (const auto& c : chunks) {
	            if (c.empty()) {
	                all_chunks_ready = false;
	                break;
	            }
	        }
		
	        if (all_chunks_ready) {
	            std::vector<uint8_t> full_data;
	            for (const auto& chunk : chunks) full_data.insert(full_data.end(), chunk.begin(), chunk.end());
	            cv::Mat img = cv::imdecode(full_data, cv::IMREAD_COLOR);
	            if (!img.empty()) {
	                std::vector<uint8_t> encoded;
	                cv::imencode(".jpg", img, encoded);

					/*
					if (hdr->camera_id == 0) {
						cv::imshow("img1", img);
						cv::waitKey(1);
					}
					if (hdr->camera_id == 1) {
						cv::imshow("img2", img);
						cv::waitKey(1);
					}
					if (hdr->camera_id == 2) {
						cv::imshow("img3", img);
						cv::waitKey(1);
					}
					*/

	                Slot& slot = shm_ptr_->cam[hdr->robot_id - 1][hdr->camera_id];
	                if (encoded.size() > MAX_IMG) {
	                    std::cerr << "Encoded image size " << encoded.size() << " exceeds MAX_IMG " << MAX_IMG << "\n";
	                } else {
	                    slot.size.store(0, std::memory_order_release);
	                    memcpy(slot.data.data(), encoded.data(), encoded.size());
	                    slot.size.store(encoded.size(), std::memory_order_release);
	                    slot.frame_id.store(hdr->frame_id, std::memory_order_release);
						std::cout << "[ROBOT " << int(hdr->robot_id) << "]";
	                    std::cout << "[CAM " << int(hdr->camera_id) << "] frame " << hdr->frame_id << " stored\n";
	                }
	            }
	            buf_map.erase(hdr->frame_id);
	        }
	    }
	}

	void cleanup() {
		if (sockfd_ >= 0) close(sockfd_);
		if (shm_ptr_) shm::close(shm_ptr_);
	}

	int port_;
	int	sockfd_ = -1;
	struct sockaddr_in server_addr_;
	Segment* shm_ptr_ = nullptr;
	std::thread recv_thread_;
	std::atomic<bool> running_;

	int dest_port_;
	int dest_sockfd_ = -1;
	const char *dest_ip_ = "192.168.0.1";
	struct sockaddr_in dest_addr_;

};

int main(int argc, char **argv) {
	rclcpp::init(argc, argv);
	auto node = std::make_shared<UdpShmBridge>();
	rclcpp::spin(node);
	rclcpp::shutdown();

	return 0;
}
