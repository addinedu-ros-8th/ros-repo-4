#include <chrono>

#include <tangerbot_controller/tangerbot_manager.h>
using namespace std::chrono_literals;
using namespace std;

/************************************************
 * * CONSTRUCTOR 
 * @node_name: tangerbot_manager
 * @description: This node is responsible for managing the robot's state and pose.
 ************************************************/
TangerbotManager::TangerbotManager() : Node("tangerbot_manager")
{
    //initalization
    robot_id = "robot2";
    main_status = tangerbot_msgs::msg::RobotState::IDLE;
    motion_status = tangerbot_msgs::msg::RobotState::STOP;

    //publisher
    state_publisher = this->create_publisher<tangerbot_msgs::msg::RobotState>("robot_state", 10); 
    timer_ = this->create_wall_timer(500ms, std::bind(&TangerbotManager::state_callbacks, this));
    
    //subscriber
    person_pose_subscriber = this->create_subscription<tangerbot_msgs::msg::RobotPose>(
        "person_pose", 10, std::bind(&TangerbotManager::person_pose_callbacks, this, std::placeholders::_1));
}
//TODO (revise parameter?)
/************************************************
 * * Set Robot State
 * Robot Status: [Idle, Working], [Moving, Following, Stop, Loading]
 * @param robotID, mainStatus, motionStatus, battery  
*************************************************/
void TangerbotManager::set_state(const std::shared_ptr<tangerbot_msgs::srv::SetState::Request> request,
std::shared_ptr<tangerbot_msgs::srv::SetState::Response> response)
{
    if (request->robot_id != robot_id) {
        response->success = false;
        response->success = "Invalid robot_id";
        return;
    }
    main_status = request->main_status;
    motion_status = request->motion_status;
    response->success = true;
}

/************************************************
 * * Person Pose Callbacks
 * * A new person pose is received
 * Updates the internal person_pose variable with the received position and orientation
 * @msg: incoming person pose
*************************************************/
void TangerbotManager::person_pose_callbacks(const tangerbot_msgs::msg::RobotPose::SharedPtr msg) {
    auto person_pose = geometry_msgs::msg::PoseStamped();
    person_pose.pose.position.x = msg->pose.pose.position.x;
    person_pose.pose.position.y = msg->pose.pose.position.y;
    person_pose.pose.orientation.z = msg->pose.pose.orientation.z;
    RCLCPP_INFO(this->get_logger(), "Received new person pose: x=%.2f, y=%.2f, theta=%.2f", 
                msg->pose.pose.position.x, msg->pose.pose.position.y, msg->pose.pose.orientation.z);
}     

//TODO
/***********************************************
 * * update_battery
 * It decreases the battery level based on the robot's motion status and recharges it when idle.
 * @param robotID The ID of the robot
 * @param currentBattery The current battery level
************************************************/
// void TangerbotManager::update_battery(string robotID, float currentBattery) {
//     auto msg = tangerbot_msgs::msg::RobotState();
//     msg.robot_id = robotID;

//     // current robot status
//     msg.main_status = main_status;
//     msg.motion_status = motion_status;

//     // Decrease 0.1% per cycle (every 500ms)
//     float consumption_rate = 0.05f;  // Default
//     if (msg.motion_status == tangerbot_msgs::msg::RobotState::MOVING) consumption_rate = 0.1f;
//     else if (msg.motion_status == tangerbot_msgs::msg::RobotState::LOADING) consumption_rate = 0.15f;
//     currentBattery -= consumption_rate;
    
//     // Battery can't be negative
//     if (battery < 0.0f)
//         battery = 0.0f;
    
//     // Rechrage battery when idle
//     if (msg.main_status == tangerbot_msgs::msg::RobotState::IDLE && battery < 100.0f) {
//         battery += 0.2f;  // Charge while idle
//         if (battery > 100.0f)
//             battery = 100.0f;
//     }

//     msg.battery = battery;

//     RCLCPP_INFO(this->get_logger(), "Publishing Battery: %.2f%%", battery);
//     state_publisher->publish(msg);

// }

//TODO
/************************************************
 * * State Callbacks
 * @description: This function is called every 500ms to update the robot's state.
************************************************/   
void TangerbotManager::state_callbacks() {
    auto msg = tangerbot_msgs::msg::RobotState();
    msg.robot_id = robot_id;
    msg.main_status = main_status;
    msg.motion_status = motion_status;
    msg.battery = battery;

    state_publisher->publish(msg);

    // Simulate battery consumption
    //update_battery(robot_id, battery);
}

int main(int argc , char **argv)
{
    rclcpp::init(argc, argv);
    auto pub = std::make_shared<TangerbotManager>();
    rclcpp::spin(pub);
    rclcpp::shutdown();
    return 0;
}


