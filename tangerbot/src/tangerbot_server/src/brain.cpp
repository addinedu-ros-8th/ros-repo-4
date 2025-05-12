#include "tangerbot_server/brain.h"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "tangerbot_msgs/srv/handle_command.hpp"
#include "tangerbot_msgs/srv/path_planning.hpp"
#include "tangerbot_msgs/srv/get_workload.hpp"
#include "tangerbot_msgs/srv/set_follow_mode.hpp"
#include "tangerbot_msgs/srv/set_state.hpp"
#include "tangerbot_msgs/srv/redirect.hpp"
#include "tangerbot_msgs/msg/robot_state.hpp"
#include "tangerbot_msgs/action/navigate_to_pose.hpp"

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
    set_state_client_ = this->create_client<SetState>("set_state");
    redirect_client = this->create_client<Redirect>("redirect");

    //Subscriber
    robot_state_subscriber = this->create_subscription<RobotState>(
        "robot_state", 10, std::bind(&Brain::robot_state_callback, this, _1)
    );
}



/************************************************
 * * Set Robot State
 * @param robot_id, main_status, motion_status
 * @description: set the state of the robot.
 *************************************************/
void Brain::set_robot_state(const std::string &robot_id, uint8_t main_status, uint8_t motion_status) {
    auto request = std::make_shared<SetState::Request>();
    request->robot_id = robot_id;
    request->main_status = main_status;
    request->motion_status = motion_status;

    if (!set_state_client_->wait_for_service(std::chrono::seconds(1))) {
        RCLCPP_ERROR(this->get_logger(), "SetState service not available");
        return;
    }

    auto future = set_state_client_->async_send_request(
        request,[this, robot_id](rclcpp::Client<SetState>::SharedFuture result_future) {
            if (result_future.get()->success) {
                RCLCPP_INFO(this->get_logger(), "Successfully updated state of robot %s", robot_id.c_str());
            } else {
                RCLCPP_WARN(this->get_logger(), "Failed to update state of robot %s", robot_id.c_str());
            }
        }
    );
}




/************************************************
 * * Convert Command-Type to String
 * @param type
 * @return string
 * @description: converts the command type to a string for logging purposes.
 ************************************************/
std::string command_type_to_string(uint8_t type) {
    switch (type) {
        case 0: return "MOVETOSECTION";
        case 1: return "FOLLOWING";
        case 2: return "STOP";
        case 3: return "RETURN";
        default: return "UNKNOWN";
    }
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
    auto msg = tangerbot_msgs::msg::RobotState::SharedPtr
    response->success = true;
    const auto &robot_id = request->robot_id;
    RCLCPP_INFO(this->get_logger(), "Robot %s has received command: %s", request->robot_id, command_type_to_string(request->type).c_str());
    

    switch (request->type){

        case HandleCommand::Request::MOVETOSECTION:
            RCLCPP_INFO(this->get_logger(), "Robot starts moving to section: %d", request->data);   
            set_robot_state(robot_id, tangerbot_msgs::msg::RobotState::WORKING, tangerbot_msgs::msg::RobotState::MOVING);
            break;  
        
            case HandleCommand::Request::FOLLOWING:
            RCLCPP_INFO(this->get_logger(), "Robot starts following: %d", request->data);
            set_robot_state(robot_id, tangerbot_msgs::msg::RobotState::WORKING, tangerbot_msgs::msg::RobotState::FOLLOWING);
            break;
        
            case HandleCommand::Request::STOP:
            RCLCPP_INFO(this->get_logger(), "Robot starts stopping");
            set_robot_state(robot_id, tangerbot_msgs::msg::RobotState, tangerbot_msgs::msg::RobotState::FOLLOWING);
            break;
        
            case HandleCommand::Request::RETURN:
            RCLCPP_INFO(this->get_logger(), "Robot starts returning to base");
            set_robot_state(robot_id, tangerbot_msgs::msg::RobotState::IDLE, tangerbot_msgs::msg::RobotState::MOVING);
            break;
        
        default:
            response->success = false;
            RCLCPP_ERROR(this->get_logger(), "Unknown command type: %d", request->type);
            break;  
    }
                        
}





/************************************************
 * * Robot State Callback
 * @param msg 
 * @description: Receives real-time updates about the robots' state & Decides what to do by current status
 ************************************************/
void Brain::robot_state_callback(const tangerbot_msgs::msg::RobotState::SharedPtr msg) {
 

    RCLCPP_INFO(this->get_logger(), "Robot state: %s", status_to_string(MAIN_STATUS, msg->main_status).c_str());
    RCLCPP_INFO(this->get_logger(), "Robot motion: %s", status_to_string(MOTION_STATUS, msg->motion_status).c_str());


    /********************************************
     * * WORKING
     ********************************************/
    if (msg->main_status == tangerbot_msgs::msg::RobotState::WORKING) {
        RCLCPP_INFO(this->get_logger(), "Robot %d is working", msg->robot_id);
    
        if (msg->motion_status == tangerbot_msgs::msg::RobotState::MOVING) {
            RCLCPP_INFO(this->get_logger(), "Robot %d is moving", msg->robot_id);
            handle_moving_state(current_robot_);
        } else if (msg->motion_status == tangerbot_msgs::msg::RobotState::FOLLOWING) {
            RCLCPP_INFO(this->get_logger(), "Robot %d is following", msg->robot_id);
            handle_following_state(current_robot_);
        } else if (msg->motion_status == tangerbot_msgs::msg::RobotState::STOP) {
            RCLCPP_INFO(this->get_logger(), "Robot %d is stopped", msg->robot_id);
            handle_stop_state(current_robot_);
        } else if (msg->motion_status == tangerbot_msgs::msg::RobotState::LOADING) {
            RCLCPP_INFO(this->get_logger(), "Robot %d is loading", msg->robot_id);
            handle_loading_state(current_robot_);
        } else {
            RCLCPP_ERROR(this->get_logger(), "Unknown motion status: %d", msg->motion_status);
        }
    
    }

    /********************************************
     * * IDLE
     ********************************************/
    else if (msg->main_status == tangerbot_msgs::msg::RobotState::IDLE) {
        RCLCPP_ERROR(this->get_logger(), "Robot %d is in idle", msg->robot_id);
        handle_idle_state(current_robot_);
    
    
    } 


    /********************************************
     * * DEACTIVATE
     ********************************************/
    else if (msg->main_status == tangerbot_msgs::msg::RobotState::DEACTIVATE) {
        RCLCPP_INFO(this->get_logger(), "Robot %d is in deactivate", msg->robot_id);

        if (msg->battery < 20) {
            RCLCPP_WARN(this->get_logger(), "Battery low: %d%%", msg->battery);
            handle_low_battery(msg->battery);
        } else {
            RCLCPP_INFO(this->get_logger(), "Battery level: %d%%", msg->battery);
            
            auto request = std::make_shared<tangerbot_msgs::srv::SetState::Request>();
            request->robot_id = msg->robot_id;
            request->new_state = tangerbot_msgs::msg::RobotState::IDLE;

            auto result = set_state_client->async_send_request(request);
            if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) == rclcpp::FutureReturnCode::SUCCESS) {
                RCLCPP_INFO(this->get_logger(), "Successfully changed robot state to IDLE");
            } else {
                RCLCPP_ERROR(this->get_logger(), "Failed to change robot state to IDLE");
            }
        }
    }

}





int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Brain>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
