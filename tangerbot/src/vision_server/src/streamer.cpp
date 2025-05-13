#include <arpa/inet.h>
#include <thread>
#include <atomic>
#include <vector>
#include <map>
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
		sockaddr_in addr{};
		addr.sin_family = AF_INET;
		addr.sin_port   = htons(port_);
		addr.sin_addr.s_addr = INADDR_ANY;
		if (bind(sockfd_, (sockaddr*)&addr, sizeof(addr)) < 0) {
			RCLCPP_FATAL(get_logger(), "bind() failed");
			cleanup();
			rclcpp::shutdown();
			return;
		}

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
	}

private:
	/*
	void receiveLoop() {
		constexpr size_t MAX_PACKET = 1400;
		uint8_t buffer[MAX_PACKET];
		sockaddr_in client{};
		socklen_t   len = sizeof(client);

		// 프레임별 청크 저장
		std::map<uint32_t, std::vector<std::vector<uint8_t>>> chunk_buffer[2];

		while (rclcpp::ok() && running_) {
			ssize_t n = recvfrom(sockfd_, buffer, MAX_PACKET, 0,
			                     (sockaddr*)&client, &len);
			if (n <= 0) continue;

			auto *hdr = reinterpret_cast<PacketHeader*>(buffer);  // 패킷 해더 디코딩

			// 무결성 검증
			if (hdr->magic != MAGIC_VALUE) {
				std::cerr << "Invalid magic value: " << (int)hdr->magic << "\n";
				continue;
			}
			if (hdr->camera_id > 1) {
				std::cerr << "Invalid camera_id: " << (int)hdr->camera_id << "\n";
				continue;
			}
			if (hdr->chunk_id >= hdr->total_chunks) {
				std::cerr << "Invalid chunk_id: " << hdr->chunk_id << " >= " << hdr->total_chunks << "\n";
				continue;
			}
			if (hdr->chunk_size > (n - sizeof(PacketHeader))) {
				std::cerr << "Invalid chunk_size: " << hdr->chunk_size << " > " << (n - sizeof(PacketHeader)) << "\n";
				continue;
			}

			auto& buf_map = chunk_buffer[hdr->camera_id];
			auto& chunks = buf_map[hdr->frame_id];

			// 패킷의 첫번째 청크
			if (chunks.empty()) chunks.resize(hdr->total_chunks);

			// 청크 사이즈 만큼 초기화
			chunks[hdr->chunk_id] = std::vector<uint8_t>(buffer + sizeof(PacketHeader), buffer + n);

			bool all_chunks_ready = true;
			for (const auto& c : chunks) {
				if (c.empty()) {
					all_chunks_ready = false;
					break;
				}
			}

			// 모든 청크 수신 완료 시
			if (all_chunks_ready) {
				std::vector<uint8_t> full_data;
				for (const auto& chunk : chunks) full_data.insert(full_data.end(), chunk.begin(), chunk.end());
				cv::Mat img = cv::imdecode(full_data, cv::IMREAD_COLOR);
				if (!img.empty()) {
					std::vector<uint8_t> encoded;
					cv::imencode(".jpg", img, encoded);

					Slot& slot = shm_ptr_->cam[hdr->camera_id];
					// memcpy 안전성 확인
					if (encoded.size() > MAX_IMG) {
						std::cerr << "Encoded image size " << encoded.size() << " exceeds MAX_IMG " << MAX_IMG << "\n";
					} else {
						memcpy(slot.data.data(), encoded.data(), encoded.size());
						slot.size.store(encoded.size(), std::memory_order_release);
						slot.frame_id.store(hdr->frame_id, std::memory_order_release);
						std::cout << "[CAM " << int(hdr->camera_id) << "] frame " << hdr->frame_id << " stored\n";
					}
				}
				buf_map.erase(hdr->frame_id);
			}
		}
	}
	*/

	void receiveLoop() {
	    constexpr size_t MAX_PACKET = 1400;
	    uint8_t buffer[MAX_PACKET];
	    sockaddr_in client{};
	    socklen_t   len = sizeof(client);
	
	    std::map<uint32_t, std::vector<std::vector<uint8_t>>> chunk_buffer[2];
	
	    while (rclcpp::ok() && running_) {
	        ssize_t n = recvfrom(sockfd_, buffer, MAX_PACKET, 0,
	                             (sockaddr*)&client, &len);
	        if (n <= 0) continue;
			
	        auto *hdr = reinterpret_cast<PacketHeader*>(buffer);
			
	        if (hdr->magic != MAGIC_VALUE) {
	            std::cerr << "Invalid magic value: " << (int)hdr->magic << "\n";
	            continue;
	        }
	        if (hdr->camera_id > 1) {
	            std::cerr << "Invalid camera_id: " << (int)hdr->camera_id << "\n";
	            continue;
	        }
	        if (hdr->chunk_id >= hdr->total_chunks) {
	            std::cerr << "Invalid chunk_id: " << hdr->chunk_id << " >= " << hdr->total_chunks << "\n";
	            continue;
	        }
	        if (hdr->chunk_size > (n - sizeof(PacketHeader))) {
	            std::cerr << "Invalid chunk_size: " << hdr->chunk_size << " > " << (n - sizeof(PacketHeader)) << "\n";
	            continue;
	        }
		
	        auto& buf_map = chunk_buffer[hdr->camera_id];
	        auto& chunks = buf_map[hdr->frame_id];
		
	        if (chunks.empty()) chunks.resize(hdr->total_chunks);
	        chunks[hdr->chunk_id] = std::vector<uint8_t>(buffer + sizeof(PacketHeader), buffer + n);
		
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
	            // DEBUG : full_data 저장
	            //FILE* fp = fopen(("debug_full_data_cam" + std::to_string(hdr->camera_id) + ".jpg").c_str(), "wb");
	            //fwrite(full_data.data(), 1, full_data.size(), fp);
	            //fclose(fp);
	            cv::Mat img = cv::imdecode(full_data, cv::IMREAD_COLOR);
	            if (!img.empty()) {
	                std::vector<uint8_t> encoded;
	                cv::imencode(".jpg", img, encoded);
	                Slot& slot = shm_ptr_->cam[hdr->camera_id];
	                if (encoded.size() > MAX_IMG) {
	                    std::cerr << "Encoded image size " << encoded.size() << " exceeds MAX_IMG " << MAX_IMG << "\n";
	                } else {
	                    // DEBUG
	                    /*
						printf("[CAM %d] frame %u, encoded size=%zu, first 2 bytes=%02x%02x\n",
	                           hdr->camera_id, hdr->frame_id, encoded.size(),
	                           encoded[0], encoded[1]);
						*/
	                    slot.size.store(0, std::memory_order_release);
	                    memcpy(slot.data.data(), encoded.data(), encoded.size());
	                    // DEBUG: slot.data 확인
						/*
	                    printf("[CAM %d] slot.data first 2 bytes=%02x%02x\n",
	                           hdr->camera_id, slot.data[0], slot.data[1]);
						*/
	                    slot.size.store(encoded.size(), std::memory_order_release);
	                    slot.frame_id.store(hdr->frame_id, std::memory_order_release);
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

	int                   port_;
	int                   sockfd_{-1};
	Segment*              shm_ptr_{nullptr};
	std::thread           recv_thread_;
	std::atomic<bool>     running_;
};

int main(int argc, char **argv) {
	rclcpp::init(argc, argv);
	auto node = std::make_shared<UdpShmBridge>();
	rclcpp::spin(node);
	rclcpp::shutdown();

	return 0;
}