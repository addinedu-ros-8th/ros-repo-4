#include "tangerbot_server/brain.h"

#include <yaml-cpp/yaml.h>

//sql
// #include <mysql_driver.h>
// #include <mysql_connection.h>
// #include <cppconn/driver.h>
// #include <cppconn/statement.h>
// #include <cppconn/prepared_statement.h>
// #include <cppconn/resultset.h>

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
    signup_server_ = this->create_service<SignUp>(
        "sign_up",
        std::bind(&Brain::signup_callback, this, _1, _2)
    );
    // signin_server_ = this->create_service<SignIn>(
    //     "sign_in",
    //     std::bind(&Brain::signin_callback, this, _1, _2)
    // );

    //Service Client
    get_workload_client_ = this->create_client<GetWorkload>("get_workload");
    vision_set_follow_mode_client_ = this->create_client<SetFollowMode>("/vision/set_follow_mode");
    tserver_set_follow_mode_client_ = this->create_client<SetFollowMode>("/tserver/set_follow_mode");
    set_human_pose_mode_client_ = this->create_client<SetFollowMode>("/set_human_pose_follow_mode");
    set_state_client_ = this->create_client<SetState>("set_state");
    redirect_client_ = this->create_client<Redirect>("redirect");
<<<<<<< HEAD
=======

>>>>>>> dev

    //Action Client
    path_planning_client_ = rclcpp_action::create_client<tangerbot_msgs::action::PathPlanning>(this, "path_planning");
    follow_path_client_ = rclcpp_action::create_client<nav2_msgs::action::FollowPath>(this, "follow_path");

    //Subscriber
    robot_states_ = this->create_subscription<RobotState>(
        "robot_state", 10, std::bind(&Brain::robot_state_callback, this, _1)
    );
    obstacle_subscriber_ = this->create_subscription<std_msgs::msg::Bool>(
        "/obstacle_bool", 10,
        std::bind(&Brain::obstacle_callback, this, std::placeholders::_1)
    );
    gesture_subscriber_ = this->create_subscription<Gesture>(
        "gesture", 10, std::bind(&Brain::gesture_callback, this, _1)
    );

    //publisher
    cmd_vel_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    call_state_publisher_ = this->create_publisher<tangerbot_msgs::msg::CallState>("call_state", 10);

    //connect database
    db_driver_ = sql::mysql::get_mysql_driver_instance();
    db = std::unique_ptr<sql::Connection> (db_driver_->connect("tcp://127.0.0.1:3306", "root", "0119"));
    db->setSchema("tgdb");

    std::unique_ptr<sql::PreparedStatement> pstmt(db->prepareStatement("SELECT sectionName, ST_AsText(coordinate) AS coordinate FROM Section"));
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




void Brain::signup_callback(const std::shared_ptr<tangerbot_msgs::srv::SignUp::Request> request,
    const std::shared_ptr<tangerbot_msgs::srv::SignUp::Response> response)
{   
    RCLCPP_INFO(this->get_logger(), "Sign Up Request Received");

    //check user info
    std::string user_name = request->name;

    //check if the user exists in the database
    std::unique_ptr<sql::PreparedStatement> pstmt(db->prepareStatement("SELECT * FROM User WHERE userName = ?"));
    pstmt->setString(1, user_name);
    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    if (res->next()) {
        RCLCPP_INFO(this->get_logger(), "User %s exists", user_name.c_str());
        response->error_code=tangerbot_msgs::srv::SignUp::Response::EXIST; //EXIST
        return;
    }
    response->error_code = tangerbot_msgs::srv::SignUp::Response::NONE; //NONE
    //insert new user
    pstmt.reset(db->prepareStatement("INSERT INTO User (userName, dob, callNumber, email, password, UID) VALUES (?, ?, ?, ?, ?, ?)"));
    pstmt->setString(1, request->name);
    pstmt->setString(2, request->birthday);
    pstmt->setString(3, request->cell_number);
    pstmt->setString(4, request->email);
    pstmt->setString(5, request->password);
    pstmt->setString(6, request->user_id);
    pstmt->execute();
}



// void Brain::signin_callback(const std::shared_ptr<tangerbot_msgs::srv::SignIn::Request> request,
//     const std::shared_ptr<tangerbot_msgs::srv::SignIn::Response> response)
// {
//     RCLCPP_INFO(this->get_logger(), "Sign In Request Received");

//     std::unique_ptr<sql::PreparedStatement> pstmt(db->prepareStatement("SELECT * FROM User WHERE userName = ?"));
//     pstmt->setString(1, user_name);
//     std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

//     //if user exists -> check if password match
//     //else -> return error code
// }



void Brain::robot_state_callback(const RobotState::SharedPtr msg) 
{
    robot_states_data_[msg->robot_id] = *msg;
}





void Brain::gesture_callback(const tangerbot_msgs::msg::Gesture::SharedPtr msg)
{   
    std::string robot_id = msg->robot_id;

    // if (robot_states_data_[robot_id].main_status != tangerbot_msgs::msg::RobotState::WORKING
    //      && robot_states_data_[robot_id].motion_status != tangerbot_msgs::msg::RobotState::FOLLOWING) {
    //     RCLCPP_ERROR(this->get_logger(), "Robot %s is not working and following mode.", robot_id.c_str());
    //     return;
    // }
    
    RCLCPP_INFO(this->get_logger(), "Gesture Detecting is started");
    
    uint8_t gesture = msg->gesture;

    switch (gesture){
        case tangerbot_msgs::msg::Gesture::COME:
            RCLCPP_INFO(this->get_logger(), "Gesture COME");
            break;

        case tangerbot_msgs::msg::Gesture::STOP:
            RCLCPP_INFO(this->get_logger(), "Gesture STOP");
            break;

        case tangerbot_msgs::msg::Gesture::BACK:
            RCLCPP_INFO(this->get_logger(), "Gesture BACK");
            break;  
        
        default:
            RCLCPP_INFO(this->get_logger(), "Unknown Gesture");
            break;
    }
}




void Brain::obstacle_callback(const std_msgs::msg::Bool::SharedPtr msg)
{
    if (msg->data) {
        RCLCPP_INFO(this->get_logger(), "Obstacle detected!");
        obstacle_detected_ = true;
    } else {
        obstacle_detected_ = false;
    }
}




float Brain::request_workload(const std::string &robot_id)
{
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





std::shared_ptr<tangerbot_msgs::action::PathPlanning::Result> Brain::request_path_planning_action(
                    const std::string& robot_id, const geometry_msgs::msg::PoseStamped& goal_pose)
{

    auto goal_msg = tangerbot_msgs::action::PathPlanning::Goal();
    goal_msg.robot_id = robot_id;
    goal_msg.goal = goal_pose;

    if (!path_planning_client_->wait_for_action_server()) {
        RCLCPP_ERROR(this->get_logger(), "Path Planning Action server not available");
        return nullptr;
    }

    //send goal_msg (robot id and goal pose) to the Path Planning
    auto future_goal_handle = path_planning_client_->async_send_goal(goal_msg);
    
    RCLCPP_INFO(this->get_logger(), "x: %lf, y: %lf", goal_pose.pose.position.x , goal_pose.pose.position.y);

    auto goal_handle = future_goal_handle.get();
    if (!goal_handle) {
        RCLCPP_ERROR(this->get_logger(), "Goal was rejected");
        return nullptr;
    }

    auto future_result = path_planning_client_->async_get_result(goal_handle);
    
    RCLCPP_INFO(this->get_logger(), " Complete Path !");
    return future_result.get().result;
}







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

        //double battery_score = state.battery/100.0;
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
    if (selected_robot_id.empty()){
        return "";
    }
    tangerbot_msgs::msg::CallState msg;
    msg.robot_id = selected_robot_id;
    msg.success = true;
    call_state_publisher_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Selected Optimal Robot: %s", selected_robot_id.c_str());
    return selected_robot_id;
}






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







void Brain::move_to_section(const geometry_msgs::msg::PoseStamped& goal_pose)
{
    
    std::string selected_robot_id = select_optimal_robot(goal_pose);


    if (selected_robot_id.empty()){
        RCLCPP_ERROR(this->get_logger(), "No Available Robot to Assign.");
        return;
    }


    // if (!set_robot_state(selected_robot_id, 1, 0)){
    //     RCLCPP_WARN(this->get_logger(), "Failed to update robot state");
    // } 

    while(rclcpp::ok() ){
        rclcpp::Rate loop_rate(10);
        if (!follow_path_client_->wait_for_action_server(std::chrono::seconds(10))){
            RCLCPP_ERROR(this->get_logger(), "Follow Path Action Server not availaable");
            //set_robot_state(selected_robot_id, 1, 2); //Working, Stop
            return;
        }

        auto goal_msg = nav2_msgs::action::FollowPath::Goal();
        goal_msg.path = selected_robot_path_;
        

        auto send_goal_options = rclcpp_action::Client<nav2_msgs::action::FollowPath>::SendGoalOptions(); 
        send_goal_options.result_callback = [this, selected_robot_id, goal_msg, send_goal_options](const auto& result){
            if (result.code==rclcpp_action::ResultCode::SUCCEEDED){
                tangerbot_msgs::msg::CallState msg;
                msg.robot_id = selected_robot_id;
                msg.success=true;
                msg.done = true;
                msg.time_remaining = 0.0;
                call_state_publisher_->publish(msg);

                RCLCPP_INFO(this->get_logger(), "Robot %s reached the goal.", selected_robot_id.c_str());
            } else {
                RCLCPP_INFO(this->get_logger(), "Robot %s failed to reach the goal.", selected_robot_id.c_str());
            }
        };

        send_goal_options.feedback_callback = [this, selected_robot_id](auto /*goal_handle*/, const std::shared_ptr<const nav2_msgs::action::FollowPath::Feedback> feedback) {
            if (feedback) {
                current_distance_remaining_ = feedback->distance_to_goal;
                float current_speed = feedback->speed;
                float time_remaining = current_distance_remaining_ / current_speed; 
                if (time_remaining < 0) return;

                tangerbot_msgs::msg::CallState msg;
                msg.robot_id = selected_robot_id;
                msg.success = true;
                msg.done = false;
                msg.time_remaining = time_remaining;
                call_state_publisher_->publish(msg);
        
                RCLCPP_INFO(this->get_logger(), "Robot %s remaining distance: %.2f m, ETA: %.2f s", 
                            selected_robot_id.c_str(), current_distance_remaining_, time_remaining);
            }
        };

        auto future_goal_handle = follow_path_client_->async_send_goal(goal_msg, send_goal_options);
        goal_handle_ = future_goal_handle.get();
        if (!goal_handle_) {
            RCLCPP_ERROR(this->get_logger(), "Goal was rejected by the server");
            return;
        }

        RCLCPP_INFO(this->get_logger(), "Sent follow path goal");


        while (rclcpp::ok()) {     

            if (obstacle_detected_){
                if (goal_handle_) {
                    RCLCPP_INFO(this->get_logger(), "obstacle detected, canceling follow path");
                    auto cancel_future = follow_path_client_->async_cancel_goal(goal_handle_);
                    
                    RCLCPP_INFO(this->get_logger(), "Follow Path canceled successfully.");
                    auto cmd_vel = geometry_msgs::msg::Twist();
                    
                    while (obstacle_detected_){
                        cmd_vel.linear.x = -0.1;
                        cmd_vel.angular.z = 0.0;
                        cmd_vel_publisher_->publish(cmd_vel);
                        loop_rate.sleep();
                    }
    
                    cmd_vel.linear.x = 0.0;
                    cmd_vel.angular.z = 0.0;
                    cmd_vel_publisher_->publish(cmd_vel);
    
                    auto result = request_path_planning_action(selected_robot_id, goal_pose);
    
                    goal_msg.path = result->path;
            
                    future_goal_handle = follow_path_client_->async_send_goal(goal_msg, send_goal_options);
                    goal_handle_ = future_goal_handle.get();
                    if (!goal_handle_) {
                        RCLCPP_ERROR(this->get_logger(), "Goal was rejected by the server");
                        return;
                    }
                    RCLCPP_INFO(this->get_logger(), "Path Replanning Re-Requested");
                }
            }
        }
    }
}






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
    
    if (command == request->FOLLOWING) {
        std::string robot_id = request->robot_id;


        auto follow_req = std::make_shared<SetFollowMode::Request>();
        follow_req->robot_id = robot_id;
        follow_req->mode = true;

        // 1. vision_set_follow_mode
        RCLCPP_INFO(this->get_logger(), "Calling vision_set_follow_mode for robot %s", robot_id.c_str());
        if (!vision_set_follow_mode_client_->wait_for_service(std::chrono::seconds(5))) {
            RCLCPP_ERROR(this->get_logger(), "vision_set_follow_mode service not available.");
            response->success = false;
            return;
        }
        auto vision_result = vision_set_follow_mode_client_->async_send_request(follow_req);

        // 2. set_human_pose_mode
        RCLCPP_INFO(this->get_logger(), "Calling set_human_pose_mode for robot %s", robot_id.c_str());
        if (!set_human_pose_mode_client_->wait_for_service(std::chrono::seconds(5))) {
            RCLCPP_ERROR(this->get_logger(), "set_human_pose_mode service not available.");
            response->success = false;
            return;
        }
        auto pose_result = set_human_pose_mode_client_->async_send_request(follow_req);

        // 3. tserver_set_follow_mode
        RCLCPP_INFO(this->get_logger(), "Calling tserver_set_follow_mode for robot %s", robot_id.c_str());
        if (!tserver_set_follow_mode_client_->wait_for_service(std::chrono::seconds(5))) {
            RCLCPP_ERROR(this->get_logger(), "tserver_set_follow_mode service not available.");
            response->success = false;
            return;
        }
        auto tserver_result = tserver_set_follow_mode_client_->async_send_request(follow_req);

        RCLCPP_INFO(this->get_logger(), "Following mode activated for robot: %s", robot_id.c_str());
        response->success = true;


<<<<<<< HEAD

    } 
=======
        // 4. Gesture On
        
        return;
    }
>>>>>>> dev

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

