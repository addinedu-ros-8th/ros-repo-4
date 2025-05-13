#include "tangerbot_server/brain.h"
#include "rclcpp/rclcpp.hpp"

#include "tangerbot_msgs/srv/handle_command.hpp"
#include "tangerbot_msgs/srv/path_planning.hpp"
#include "tangerbot_msgs/srv/get_workload.hpp"
#include "tangerbot_msgs/srv/set_follow_mode.hpp"
#include "tangerbot_msgs/srv/redirect.hpp"
#include "tangerbot_msgs/msg/robot_state.hpp"

#include <cstring>

using namespace std::placeholders;
/************************************************
 * * CONSTRUCTOR 
 * @node_name: brain
 * @description: This node is responsible for managing all situation
 ************************************************/
Brain::Brain() : Node("brain") {
    //Service Server
    handle_command_server = this->create_service<HandleCommand>(
        "handle_command",
        std::bind(&Brain::handle_command_callback, this, _1, _2)
    );

    //Service Client
    path_planning_client = this->create_client<PathPlanning>("path_planning");
    get_workload_client = this->create_client<GetWorkload>("get_workload");
    set_follow_mode_client = this->create_client<SetFollowMode>("set_follow_mode");
    redirect_client = this->create_client<Redirect>("redirect");

    //Subscriber
    robot_state_subscriber = this->create_subscription<RobotState>(
        "robot_state", 10, std::bind(&Brain::robot_state_callback, this, _1)
    );
}

/************************************************
 * * Handle Command Callback 
 * @param reqeust, response
 * @brief MOVETOSECTION, FOLLOWING, STOP, RETURN
 * @description: This node is responsible for handling commands from the user.
 ************************************************/
void Brain::handle_command_callback(const std::shared_ptr<HandleCommand::Request> request,
                                    std::shared_ptr<HandleCommand::Response> response) 
{
    
    response->success = true;
    RCLCPP_INFO(this->get_logger(), "Received command: %d", request->type);
    

    switch (request->type){

        case HandleCommand::Request::MOVETOSECTION:
            RCLCPP_INFO(this->get_logger(), "Robot moving to section: %d", request->data);   
            break;  
        case HandleCommand::Request::FOLLOWING:
            RCLCPP_INFO(this->get_logger(), "Robot following: %d", request->data);
            break;
        case HandleCommand::Request::STOP:
            RCLCPP_INFO(this->get_logger(), "Robot stopping");
            break;
        case HandleCommand::Request::RETURN:
            RCLCPP_INFO(this->get_logger(), "Robot returning to base");
            break;
        
        default:
            response->success = false;
            RCLCPP_ERROR(this->get_logger(), "Unknown command type: %d", request->type);
            break;  
    }
                        
}



/************************************************
 * * Robot State Callback
 * @description: This node is responsible for managing the robot's state and pose.
 ************************************************/
void Brain::robot_state_callback(const tangerbot_msgs::msg::RobotState::SharedPtr msg) {
    // Log the received state and pose
    RCLCPP_INFO(this->get_logger(), "Received Robot State:");
    // RCLCPP_INFO(this->get_logger(), "State: %s", msg->state.c_str());
    // RCLCPP_INFO(this->get_logger(), "Pose: [x: %.2f, y: %.2f, theta: %.2f]",
    //             msg->pose.x, msg->pose.y, msg->pose.theta);

    // Example: Update internal state variables (if needed)
    // current_state_ = msg->state;
    // current_pose_ = msg->pose;

    // Example: Trigger actions based on the state
    // if (msg->state == "ERROR") {
    //     handle_error_state();
    // }
}



int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Brain>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
