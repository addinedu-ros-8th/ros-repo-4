#include "tangerbot_server/brain.h"

#include <yaml-cpp/yaml.h>

//sql
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>


#include <iostream>
#include <thread>
#include <cstring>
#include <mutex>
#include <chrono>

using namespace std::placeholders;


/************************************************
 * * CONSTRUCTOR 
 * @node_name: brain
 * @description: This node is responsible for managing all situation
 ************************************************/
Brain::Brain() : Node("brain") {
     RCLCPP_INFO(this->get_logger(), "Tangerbot Brain Node is Starting.");

    //Service Server
    handle_command_server_ = this->create_service<HandleCommand>(
        "handle_command",
        std::bind(&Brain::handle_command_service_callback, this, _1, _2)
    );

    //Service Client
    get_workload_client_ = this->create_client<GetWorkload>("get_workload");
    set_follow_mode_client_ = this->create_client<SetFollowMode>("set_follow_mode");
    set_state_client_ = this->create_client<SetState>("set_state");
    redirect_client_ = this->create_client<Redirect>("redirect");

    //Action Client
    path_planning_client_ = rclcpp_action::create_client<tangerbot_msgs::action::PathPlanning>(this, "path_planning");
    follow_path_client_ = rclcpp_action::create_client<nav2_msgs::action::FollowPath>(this, "follow_path");

    //Subscriber
    robot_states_ = this->create_subscription<RobotState>(
        "robot_state", 10, std::bind(&Brain::robot_state_callback, this, _1)
    );

    //connect database
    sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
    std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "root", "0119"));
    con->setSchema("tgdb");

    std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT sectionName, ST_AsText(coordinate) AS coordinate FROM Section"));
    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    for (int i = 0; i < res->rowsCount(); ++i) {
        res->next();
        std::string sectionName = res->getString("sectionName");
        std::string point = res->getString("coordinate");
        //printf("%s, %s", sectionName.c_str(), point.c_str());
        auto goal_pose = geometry_msgs::msg::PoseStamped();

        double x,y;
        sscanf(point.c_str(), "POINT(%lf %lf)", &x, &y);
        printf("%s", point.c_str());
        printf("x: %lf Y: %lf", x, y);
        goal_pose.pose.position.x = x;
        goal_pose.pose.position.y = y;
        goal_pose.pose.position.z = 0.0;


        goal_pose.pose.orientation.x = 0.0;
        goal_pose.pose.orientation.y = 0.0;
        goal_pose.pose.orientation.z = 0.0;
        goal_pose.pose.orientation.w = 1.0;

        section_poses_[sectionName] = goal_pose;
    }
    tangerbot_msgs::msg::RobotState robot_state;
    robot_state.robot_id = "robot1";
    robot_state.main_status = 0;
    robot_states_data_["robot1"] = robot_state;

}

Brain::~Brain(){
    if (threadMove_.joinable()) threadMove_.join();
}


/**********************************************************************************************************/

void Brain::robot_state_callback(const RobotState::SharedPtr msg) {
    robot_states_data_[msg->robot_id] = *msg;
}


float Brain::request_workload(const std::string &robot_id){
    auto request = std::make_shared<tangerbot_msgs::srv::GetWorkload::Request>();
    request->robot_id = robot_id;
    float workload;

    while (!get_workload_client_->wait_for_service(std::chrono::seconds(1))) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service.");
            return -1.0f;
        }
        RCLCPP_INFO(this->get_logger(), "Waiting for service to become available...");
    }

    // Send request and get future response
    auto future = get_workload_client_->async_send_request(request);

    // Handle response (blocking call until response is received)
    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) == rclcpp::FutureReturnCode::SUCCESS) {
        auto response = future.get();
        workload = response->workload;
        
    } else {
        RCLCPP_ERROR(this->get_logger(), "Failed to call service.");
        return -1.0f;
    }

    return workload;
    
}
/************************************************
 * REQUEST AND GET PATH PALN
 * @helper: for select_optimal_robot
 ***********************************************/
std::shared_ptr<tangerbot_msgs::action::PathPlanning::Result> Brain::request_path_planning_action(
                    const std::string& robot_id, const geometry_msgs::msg::PoseStamped& goal_pose)
{

    auto goal_msg = tangerbot_msgs::action::PathPlanning::Goal();
    goal_msg.robot_id = robot_id;
    goal_msg.goal = goal_pose;

    if (!path_planning_client_->wait_for_action_server()) {
        RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
        return nullptr;
    }

    //send goal_msg (robot id and goal pose) to the Path Planning
    auto future_goal_handle = path_planning_client_->async_send_goal(goal_msg);
    
    RCLCPP_INFO(this->get_logger(), "x: %lf", goal_pose.pose.position.x);

    auto goal_handle = future_goal_handle.get();
    if (!goal_handle) {
        RCLCPP_ERROR(this->get_logger(), "Goal was rejected");
        return nullptr;
    }

    RCLCPP_INFO(this->get_logger(), "hi");
    auto future_result = path_planning_client_->async_get_result(goal_handle);
    
    RCLCPP_INFO(this->get_logger(), " Complete Path !");
    return future_result.get().result;
}
/************************************************
 * SELECT OPTIMAL ROBOT
 * @helper: for move_to_section
 ************************************************/
std::string Brain::select_optimal_robot(const geometry_msgs::msg::PoseStamped& goal_pose)
{
    //initalize
    std::string selected_robot_id;
    double best_score = -1.0;
    
    for (const auto& [robot_id, state] : robot_states_data_){
        if (state.main_status != 0) continue; //pass if it's not IDLE
    
        //request and get distance and workload
        auto result = request_path_planning_action(robot_id, goal_pose);
        if (!result || result->error_code !=0) continue; //pass if path got error
        
        float distance = result->distance;

        double battery_score = state.battery/100.0;
        double distance_score = 1.0/(1.0+distance);
        //double workload_score = 1.0/(1.0+request_workload(robot_id));

        //double score = 0.5 * battery_score + 0.3 * distance_score + 0.2 * workload_score;
        double score = distance;
        if (score > best_score){
            best_score = score;
            selected_robot_id = robot_id;
            selected_robot_path_ = result->path;
        }
    }   
        
    return selected_robot_id;
}

/************************************************
 * Set Robot State
 * @helper: for move_to_section
 ************************************************/
bool Brain::set_robot_state(const std::string& robot_id, int main_status, int motion_status){
    auto request = std::make_shared<tangerbot_msgs::srv::SetState::Request>();
    request->robot_id = robot_id;
    request->main_status = main_status;
    request->motion_status = motion_status;

    while (!set_state_client_->wait_for_service(std::chrono::seconds(1))) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service.");
            return false;
        }
        RCLCPP_INFO(this->get_logger(), "Waiting for set robot state service to become available...");
    }

    // Send request and get future response
    auto future = set_state_client_->async_send_request(request);

    // Handle response (blocking call until response is received)
    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) == rclcpp::FutureReturnCode::SUCCESS) {
        auto response = future.get();
        return response->success;
        
    } else {
        RCLCPP_ERROR(this->get_logger(), "Failed to SetState service.");
        return false;
    }
}

/************************************************
 * * MOVE TO SECTION
 * @param goal_pose
 * @description: When I received the request of call(Move to Section) with goal_pose, 
 *                  will find and select optimal robot and command move to the selected robot
 ************************************************/
void Brain::move_to_section(const geometry_msgs::msg::PoseStamped& goal_pose)
{
    
    // Step 1: Select optimal robot
    std::string selected_robot_id = select_optimal_robot(goal_pose);

    if (selected_robot_id.empty()){
        RCLCPP_ERROR(this->get_logger(), "No Available Robot to Assign.");
        return;
    }

    RCLCPP_INFO(this->get_logger(), "Selected Optimal Robot: %s", selected_robot_id.c_str());


    //Step 2: Change status of selected robot
    // bool set_state = set_robot_state(selected_robot_id, 1, 0); //Working, Moving
    // if (!set_state){
    //     RCLCPP_WARN(this->get_logger(), "Failed to update robot state");
    // }
    RCLCPP_INFO(this->get_logger(), "Set Robot State");
    
    /* Step 3: Send FollowPath goal asynchronously */
    //create the goal message
    auto goal_msg = nav2_msgs::action::FollowPath::Goal();
    goal_msg.path = selected_robot_path_;


    //wait for the follow path action server to become available
    if (!follow_path_client_->wait_for_action_server(std::chrono::seconds(10))){
        RCLCPP_ERROR(this->get_logger(), "Follow Path Action Server not availaable");
        //set_robot_state(selected_robot_id, 0, 2); //IDLE, Stop
        return;
    }

    //setup send goal options (goal is accepted / feedback is received / result comes back)
    auto send_goal_options = rclcpp_action::Client<nav2_msgs::action::FollowPath>::SendGoalOptions(); 
    send_goal_options.result_callback = [this, selected_robot_id](const auto& result){

        if (result.code==rclcpp_action::ResultCode::SUCCEEDED){
            RCLCPP_INFO(this->get_logger(), "Robot %s reached the goal.", selected_robot_id.c_str());
        } else {
            RCLCPP_INFO(this->get_logger(), "Robot %s failed to reach the goal.", selected_robot_id.c_str());
        }
    };

    auto future_goal_handle = follow_path_client_->async_send_goal(goal_msg, send_goal_options);
    RCLCPP_INFO(this->get_logger(), "Send follow path goal");
    
    auto goal_handle = future_goal_handle.get();
    if (!goal_handle) {
        RCLCPP_ERROR(this->get_logger(), "Goal was rejected by the server");
        return;
    }
    auto result_future = follow_path_client_->async_get_result(goal_handle);
    RCLCPP_INFO(this->get_logger(), "%lf", goal_msg.path.poses[0].pose.position.x);
    auto result = result_future.get();
    if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
        RCLCPP_INFO(this->get_logger(), "Robot reached the goal.");
    } else {
        RCLCPP_WARN(this->get_logger(), "Robot failed to reach the goal. Result code: %d", result.code);
    }
}

/**********************************************************************************************************/


/************************************************
 * * Handle Command Service Callback 
 * @param reqeust, response
 * @brief MOVETOSECTION, FOLLOWING, STOP, RETURN
 * @thread: threadMove (move to section)
 * @description: This node is responsible for handling commands from the user.
 ************************************************/
void Brain::handle_command_service_callback( 
    const std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Request> request,
    std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Response> response) 
{
    uint8_t command = request->type;
    geometry_msgs::msg::PoseStamped goal_pose;

    //get the section pose
    goal_pose = section_poses_[request->data];
    
   

    if (command == request->MOVETOSECTION){
        std::thread(&Brain::move_to_section, this, goal_pose).detach();
    }

    // if (command == request->FOLLOWING){
        
    // }

    // if (command == request->STOP){
    //     std::string robot_id = request->robot_id;
    //     //just make the stop
    // }

    // if (command == request->RETURN){
    //     std::string robot_id = request->robot_id;
    //     //just make the return
    // }
    
    response->success = true;
}



int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Brain>();

    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);

    executor.spin();

    rclcpp::shutdown();
    return 0;
}