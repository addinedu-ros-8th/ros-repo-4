#include <chrono>
#include <memory>
#include <vector>
#include <string>
#include <limits>
#include <csignal>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/msg/local_map.hpp"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/ximgproc.hpp>

#include <cuda_runtime.h>
#include <libsgm.h>
#include "vision_server/sample_common.h"			
#include "vision_server/shared_memory.hpp"		
//#include "ament_index_cpp/get_package_share_directory.hpp"

// Camera 
struct CameraParameters {
	float fu; float fv;
	float u0; float v0;
	float baseline;
	float height;
	float tilt;
};

using namespace std::chrono_literals;
using namespace shm;
using namespace std;

class Follower : public rclcpp::Node {
public:
	Follower() :Node("follower_node") {
		cout << "Hi" << '\n';
	}
//private:
};

// main
int main(int argc, char** argv) {
	rclcpp::init(argc, argv);
	try {
		auto node = std::make_shared<Follower>();
		rclcpp::spin(node);
	} catch (const std::exception& e) {
		std::cerr << "Fatal: " << e.what() << std::endl;
	}
	rclcpp::shutdown();
	return 0;
}

