#include "tangerbot_server/brain.h"

#include <iostream>
#include <thread>
#include <cstring>
#include <mutex>
#include <chrono>
#include <cmath>

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
    vision_set_follow_mode_client_ = this->create_client<SetFollowMode>("/vision/set_follow_mode");
    tserver_set_follow_mode_client_ = this->create_client<SetFollowMode>("/tserver/set_follow_mode");
    set_human_pose_mode_client_ = this->create_client<SetFollowMode>("/set_human_pose_follow_mode");
    set_state_client_ = this->create_client<SetState>("set_state");

    //Action Client
    path_planning_client_ = rclcpp_action::create_client<tangerbot_msgs::action::PathPlanning>(this, "path_planning");
    follow_path_client_ = rclcpp_action::create_client<nav2_msgs::action::FollowPath>(this, "follow_path");
    parking_client_= rclcpp_action::create_client<tangerbot_msgs::action::Parking>(this, "parking");

    //Subscriber
    robot_states_ = this->create_subscription<RobotState>(
        "robot_state", 10, std::bind(&Brain::robot_state_callback, this, _1)
    );
    obstacle_subscriber_ = this->create_subscription<std_msgs::msg::Bool>(
        "/obstacle_bool", 10,
        std::bind(&Brain::obstacle_callback, this, std::placeholders::_1)
    );

    //publisher
    cmd_vel_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    call_state_publisher_ = this->create_publisher<tangerbot_msgs::msg::CallState>("call_state", 10);

    //timer
    // timer_ = this->create_wall_timer(
    //     std::chrono::seconds(1),  // Call every 500 milliseconds
    //     std::bind(&Brain::timer_callback, this)
    // );

    //connect database
    db_driver_ = sql::mysql::get_mysql_driver_instance();
    db = std::unique_ptr<sql::Connection> (db_driver_->connect("tcp://127.0.0.1:3306", "root", "0119"));
    db->setSchema("tgdb");

    std::unique_ptr<sql::PreparedStatement> pstmt(db->prepareStatement("SELECT sectionName, ST_AsText(coordinate) AS coordinate, yaw FROM Section"));
    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    for (int i = 0; i < res->rowsCount(); ++i) {
        res->next();
        std::string sectionName = res->getString("sectionName");
        std::string point = res->getString("coordinate");
        std::string yaw = res->getString("yaw");
        //printf("%s, %s", sectionName.c_str(), point.c_str());
        auto goal_pose = geometry_msgs::msg::PoseStamped();

        double x,y;
        int yaw_int;
        sscanf(point.c_str(), "POINT(%lf %lf)", &x, &y);
        sscanf(yaw.c_str(), "%d", &yaw_int);
        printf("%s", point.c_str());
        printf("x: %lf Y: %lf", x, y);
        printf("yaw: %d", yaw_int);
        goal_pose.pose.position.x = x;
        goal_pose.pose.position.y = y;
        goal_pose.pose.position.z = 0.0;

        auto q = yaw_deg_to_quaternion(yaw_int);
        goal_pose.pose.orientation.x = q.x;
        goal_pose.pose.orientation.y = q.y;
        goal_pose.pose.orientation.z = q.z;
        goal_pose.pose.orientation.w = q.w;

        section_poses_[sectionName] = goal_pose;
    }

    robot_home_map_["robot1"] = "home1";
    robot_home_map_["robot2"] = "home2";
    robot_home_map_["robot3"] = "home3";

    // INIT 
    tangerbot_msgs::msg::RobotState robot_state;
    robot_state.robot_id = "robot1";
    robot_state.main_status = 0;
    robot_states_data_["robot1"] = robot_state;
}

Brain::~Brain(){
    if (threadMove_.joinable()) threadMove_.join();
    if (threadReturnStorage_.joinable()) threadReturnStorage_.join();
    if (threadReturnHome_.joinable()) threadReturnHome_.join();
}


// void Brain::timer_callback() {
//     for (const auto& [robot_id, state] : robot_states_data_) {
//         RCLCPP_INFO(this->get_logger(), "Robot %s status: %d", robot_id.c_str(), state.main_status);
//     }
// }

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





void Brain::obstacle_callback(const std_msgs::msg::Bool::SharedPtr msg)
{
    if (msg->data) {
        RCLCPP_INFO(this->get_logger(), "Obstacle detected!");
        obstacle_detected_ = true;
    } else {
        obstacle_detected_ = false;
    }
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
    
    RCLCPP_INFO(this->get_logger(), "x: %lf, y: %lf, yaw: %lf",
                 goal_pose.pose.position.x , goal_pose.pose.position.y, goal_pose.pose.orientation);

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

        double battery_score = state.battery/100.0;
        double distance_score = 1.0/(1.0+distance);
        double workload_score = 1.0/(1.0+state.workload);

        double score = 0.5 * battery_score + 0.3 * distance_score + 0.2 * workload_score;
        //double score = distance;
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






void Brain::set_robot_state(const std::string& robot_id, int main_status, int motion_status){
    auto request = std::make_shared<tangerbot_msgs::srv::SetState::Request>();
    request->robot_id = robot_id;
    request->main_status = main_status;
    request->motion_status = motion_status;

    while (!set_state_client_->wait_for_service(std::chrono::seconds(1))) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the set state service.");
        }
        RCLCPP_INFO(this->get_logger(), "Waiting for set robot state service to become available...");
    }

    set_state_client_->async_send_request(request);
}




std::string Brain::select_storage(const std::string& robot_id){
    std::vector<std::string> storage_sections = {"storage1", "storage2"};
    double min_distance = 1000.0;
    std::string selected_storage_;
    for (const auto& storage : storage_sections) {
        goal_pose_ = section_poses_[storage];
        auto result = request_path_planning_action(robot_id, goal_pose_);

        float distance = result->distance;

        if (distance < min_distance) {
            min_distance = distance;
            selected_storage_ = storage;
            selected_robot_path_ = result->path;
        }
    }
    return selected_storage_;
}



void Brain::move_to_section(const std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Request> request)
{
    section_ = request->data;
    goal_pose_ = section_poses_[request->data];
    user_id_ = request->user_id;
    selected_robot_id_ = select_optimal_robot(goal_pose_);

    if (selected_robot_id_.empty()){
        RCLCPP_WARN(this->get_logger(), "No Available Robot to Assign.");
        return;
    }
    set_robot_state(selected_robot_id_, 1, 0); //WORKING, MOVING

    goal_done_ = false;

    while(rclcpp::ok() && !goal_done_) {
        rclcpp::Rate loop_rate(10);
        if (!follow_path_client_->wait_for_action_server(std::chrono::seconds(10))){
            RCLCPP_ERROR(this->get_logger(), "Follow Path Action Server not availaable");
            return;
        }

        auto goal_msg = nav2_msgs::action::FollowPath::Goal();
        goal_msg.path = selected_robot_path_;
        

        auto send_goal_options = rclcpp_action::Client<nav2_msgs::action::FollowPath>::SendGoalOptions(); 
        send_goal_options.result_callback = [this, goal_msg, send_goal_options](const auto& result){
            if (result.code==rclcpp_action::ResultCode::SUCCEEDED)
            {
                tangerbot_msgs::msg::CallState msg;
                msg.robot_id = this->selected_robot_id_;
                msg.user_id = user_id_;
                msg.success=true;
                msg.done = true;
                msg.time_remaining = 0.0;
                call_state_publisher_->publish(msg);
                
                
                set_robot_state(this->selected_robot_id_, 1, 2); //WORKING, STOP
                goal_done_=true;
                RCLCPP_INFO(this->get_logger(), "Robot %s reached the %s.", this->selected_robot_id_.c_str(), section_.c_str());
                return;
                
            } 
            else 
            {
                RCLCPP_INFO(this->get_logger(), "Robot %s failed to reach the %s.", this->selected_robot_id_.c_str(), section_.c_str());
                return;
            }
            
        };

        send_goal_options.feedback_callback = [this](auto, const std::shared_ptr<const nav2_msgs::action::FollowPath::Feedback> feedback) {
            if (feedback) {
                current_distance_remaining_ = feedback->distance_to_goal;
                float current_speed = feedback->speed;
                float time_remaining = current_distance_remaining_ / current_speed; 
                if (time_remaining < 0) return;

                tangerbot_msgs::msg::CallState msg;
                
                msg.robot_id = this->selected_robot_id_;
                msg.user_id = user_id_;
                msg.success = true;
                msg.done = false;
                msg.time_remaining = time_remaining;
                call_state_publisher_->publish(msg);

            }
        };

        auto future_goal_handle = follow_path_client_->async_send_goal(goal_msg, send_goal_options);
        goal_handle_ = future_goal_handle.get();
        if (!goal_handle_) {
            RCLCPP_ERROR(this->get_logger(), "Goal was rejected by the server");
            return;
        }

        RCLCPP_INFO(this->get_logger(), "Sent follow path %s", section_.c_str());


        while (rclcpp::ok() && !goal_done_) {     

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
    
                    auto result = request_path_planning_action(selected_robot_id_, goal_pose_);
    
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

    return;
}




void Brain::return_to_storage(const std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Request> request)
{
    workload_ = robot_states_data_[request->robot_id].workload;
    if (workload_ == 0){
        return;
    }
    bool goal_done = false;

    RCLCPP_INFO(this->get_logger(), "Returning to Storage! ");

    selected_robot_id_ = request->robot_id;
    selected_storage_ = select_storage(selected_robot_id_); //saved path here
    goal_pose_ = section_poses_[selected_storage_];

    RCLCPP_INFO(this->get_logger(), "Selected Storage: %s", selected_storage_.c_str());

    /* Battery */
    if (robot_states_data_[selected_robot_id_].battery < 50.0){
        set_robot_state(selected_robot_id_, 1, 2); //DEACTIVATE, MOVING
        RCLCPP_INFO(this->get_logger(), "Battery is low, Deactivating Robot %s", selected_robot_id_.c_str());
    }
    else {
        /* Workload */
        if (robot_states_data_[selected_robot_id_].workload < 800){ 
            set_robot_state(selected_robot_id_, 0, 1); //NON-MAX, IDLE, MOVING
        } else { 
            set_robot_state(selected_robot_id_, 1, 1); //MAX, WORKING, MOVING
        }
    }


    while(rclcpp::ok() && !goal_done) {
        rclcpp::Rate loop_rate(10);
        
        if (!follow_path_client_->wait_for_action_server(std::chrono::seconds(10))){
            RCLCPP_ERROR(this->get_logger(), "Follow Path Action Server not available");
            return;
        }
        
        auto goal_msg = nav2_msgs::action::FollowPath::Goal();
        goal_msg.path = selected_robot_path_;
        

        auto send_goal_options = rclcpp_action::Client<nav2_msgs::action::FollowPath>::SendGoalOptions(); 
        send_goal_options.result_callback = [&](const auto& result){
            if (result.code == rclcpp_action::ResultCode::SUCCEEDED)
            {                   
                set_robot_state(selected_robot_id_, 1, 3 ); //Working, Loading
                RCLCPP_INFO(this->get_logger(), "Robot %s reached the %s.",
                            this->selected_robot_id_.c_str(), selected_storage_.c_str());
                
                threadReturnHome_ = std::thread(&Brain::return_to_home, this, request);
                threadReturnHome_.detach();
                
                goal_done = true;
            }
            else 
            {
                RCLCPP_INFO(this->get_logger(), "Robot %s failed to reach the %s.",
                            this->selected_robot_id_.c_str(), section_.c_str());
            }
        };
        

        auto future_goal_handle = follow_path_client_->async_send_goal(goal_msg, send_goal_options);
        goal_handle_ = future_goal_handle.get();
        if (!goal_handle_) {
            RCLCPP_ERROR(this->get_logger(), "Goal was rejected by the server");
            return;
        }

        RCLCPP_INFO(this->get_logger(), "Sent follow path %s", selected_storage_.c_str());


        while (rclcpp::ok() && !goal_done) {     
            RCLCPP_INFO(this->get_logger(), "return to storage while loop");
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
    
                    auto result = request_path_planning_action(selected_robot_id_, goal_pose_);
    
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

            loop_rate.sleep();
        }
    }

    return;
}




void Brain::return_to_home(const std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Request> request)
{
    rclcpp::Rate loop_rate(10);
    while (workload_){
        workload_ = robot_states_data_[request->robot_id].workload;
        loop_rate.sleep();
    }
    
    bool goal_done = false;
    RCLCPP_INFO(this->get_logger(), "Returning to Home! ");
    selected_robot_id_=request->robot_id;
    goal_pose_ = section_poses_[robot_home_map_[selected_robot_id_]];
    RCLCPP_INFO(this->get_logger(), "Robot: %s, Selected Home: %s", selected_robot_id_.c_str(), robot_home_map_[selected_robot_id_].c_str());
    auto result = request_path_planning_action(selected_robot_id_, goal_pose_);
    selected_robot_path_ = result->path;
    
    /* Battery is LOW */
    if (robot_states_data_[selected_robot_id_].battery < 50.0){
        set_robot_state(selected_robot_id_, 1, 2); //DEACTIVATE, MOVING
        RCLCPP_INFO(this->get_logger(), "Battery is low, Deactivating Robot %s", selected_robot_id_.c_str());
    }
    /* Battery is HIGH */
    else {
        set_robot_state(selected_robot_id_, 0, 1); //IDLE, MOVING
    }

    while(rclcpp::ok() && !goal_done) {
        
        if (!follow_path_client_->wait_for_action_server(std::chrono::seconds(10))){
            RCLCPP_ERROR(this->get_logger(), "Follow Path Action Server not available");
            return;
        }

        auto goal_msg = nav2_msgs::action::FollowPath::Goal();
        goal_msg.path = selected_robot_path_;
        

        auto send_goal_options = rclcpp_action::Client<nav2_msgs::action::FollowPath>::SendGoalOptions(); 
        send_goal_options.result_callback = [&](const auto& result){
            if (result.code==rclcpp_action::ResultCode::SUCCEEDED)
            {                   
                RCLCPP_INFO(this->get_logger(), "Robot %s reached the %s. Start Parking.", this->selected_robot_id_.c_str(), (robot_home_map_[selected_robot_id_]).c_str());
                threadParking_ = std::thread(&Brain::parking, this, selected_robot_id_);
                threadParking_.detach();
                
                goal_done = true;
            }
            else 
            {
                RCLCPP_INFO(this->get_logger(), "Robot %s failed to reach the %s.", this->selected_robot_id_.c_str(), (robot_home_map_[selected_robot_id_]).c_str());
            }
        };

        auto future_goal_handle = follow_path_client_->async_send_goal(goal_msg, send_goal_options);
        goal_handle_ = future_goal_handle.get();
        if (!goal_handle_) {
            RCLCPP_ERROR(this->get_logger(), "Goal was rejected by the server");
            return;
        }

        RCLCPP_INFO(this->get_logger(), "Sent follow path %s", section_.c_str());


        while (rclcpp::ok() && !goal_done) {     

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
    
                    auto result = request_path_planning_action(selected_robot_id_, goal_pose_);
    
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
    if (robot_states_data_[selected_robot_id_].battery < 50){
        set_robot_state(selected_robot_id_, 2, 2); //Deactivate Stop
    } else {
        set_robot_state(selected_robot_id_, 0, 2); //Idle Stop
    }
    return;
}

void Brain::parking(const std::string selected_robot_id) {
    auto parking_goal = tangerbot_msgs::action::Parking::Goal();
                
    if (selected_robot_id == "robot1") 
        parking_goal.marker_id = 11;
    else if (selected_robot_id == "robot2") 
        parking_goal.marker_id = 12;
    else if (selected_robot_id == "robot3") 
        parking_goal.marker_id = 13;
    else {}

    auto parking_future_goal_handle = parking_client_->async_send_goal(parking_goal);
    auto parking_goal_handle = parking_future_goal_handle.get();

    if (parking_goal_handle) {
        RCLCPP_INFO(this->get_logger(), "Robot %s parked successfully.", this->selected_robot_id_.c_str());
    } else {
        RCLCPP_ERROR(this->get_logger(), "Failed to park robot %s.", this->selected_robot_id_.c_str());
    }

    if (robot_states_data_[this->selected_robot_id_].battery < 50.0){
        set_robot_state(this->selected_robot_id_, 2, 2); //DEACTIVATE, STOP
    } else {
        set_robot_state(this->selected_robot_id_, 0, 2); //IDLE, STOP
    }
}




void Brain::handle_command_service_callback( 
    const std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Request> request,
    std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Response> response) 
{
    RCLCPP_INFO(this->get_logger(), "Handle Command Request Received. Received Data.");
    RCLCPP_INFO(this->get_logger(), "  Type: %u", request->type);
    RCLCPP_INFO(this->get_logger(), "  Data: %s", request->data.c_str());
    RCLCPP_INFO(this->get_logger(), "  Robot ID: %s", request->robot_id.c_str());
    RCLCPP_INFO(this->get_logger(), "  User ID: %s", request->user_id.c_str());


    uint8_t command = request->type;
    geometry_msgs::msg::PoseStamped goal_pose;
    goal_pose = section_poses_[request->data];
    
    if (command == request->MOVETOSECTION) {
        std::thread(&Brain::move_to_section, this, request).detach();
    }


    if (request->type == 3){
        RCLCPP_INFO(this->get_logger(), " Return Service Starting! ");
        std::thread(&Brain::return_to_storage, this, request).detach();
        //std::thread(&Brain::return_to_home, this, request).detach();
        return;
    }

    
    if ((command == request->FOLLOWING || command == request->STOP) && robot_states_data_[request->robot_id].main_status == tangerbot_msgs::msg::RobotState::WORKING) {
        std::string robot_id = request->robot_id;


        auto follow_req = std::make_shared<SetFollowMode::Request>();
        follow_req->robot_id = robot_id;

        if (command == request->FOLLOWING)
            follow_req->mode = true;
        else
            follow_req->mode = false;

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


        // 4. Gesture On
        
        return;
=======
>>>>>>> dev
    }

    response->success = true;
    return;
}



Quaternion Brain::yaw_deg_to_quaternion(int yaw_deg) {
    double yaw_rad = yaw_deg * M_PI / 180.0;
    Quaternion q;
    q.w = cos(yaw_rad / 2.0);
    q.x = 0.0;
    q.y = 0.0;
    q.z = sin(yaw_rad / 2.0);
    return q;
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
