#include <tangerbot_controller/tangerbot_manager.h>
#include "rcl_interfaces/msg/parameter_descriptor.hpp"
#include <cmath>

using namespace std::chrono_literals;
using namespace std;
using namespace std::placeholders;

using SetState = tangerbot_msgs::srv::SetState;
using Parking = tangerbot_msgs::action::Parking;
using GoalHandlerParking = rclcpp_action::ServerGoalHandle<Parking>;
using DetectedMarker = tangerbot_msgs::msg::DetectedMarker;
using RobotState = tangerbot_msgs::msg::RobotState;
using Twist = geometry_msgs::msg::Twist;


/************************************************
 * * CONSTRUCTOR 
 * @node_name: tangerbot_manager
 * @description: This node is responsible for managing the robot's state and pose.
 ************************************************/
TangerbotManager::TangerbotManager() : Node("tangerbot_manager")
{
    // initalization
    main_status = tangerbot_msgs::msg::RobotState::IDLE;
    motion_status = tangerbot_msgs::msg::RobotState::STOP;
    pid_linear = PID(0.5, 0.1, 1);
    pid_angular = PID(1.5, 0.1, 1);
    ns = robot_id;

    // publisher
    state_publisher = this->create_publisher<tangerbot_msgs::msg::RobotState>("robot_state", 10);
    cmd_vel_pub  = this->create_publisher<Twist>(ns + "/cmd_vel", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&TangerbotManager::state_callbacks, this));
    workload_timer = this->create_wall_timer(1s, std::bind(&TangerbotManager::update_workload, this));
    
    // subscriber
    person_pose_subscriber = this->create_subscription<tangerbot_msgs::msg::RobotPose>(
        "person_pose", 10, std::bind(&TangerbotManager::person_pose_callbacks, this, _1)
    );
    detected_marker_sub = this->create_subscription<DetectedMarker>(
        "/detected_marker", 10, std::bind(&TangerbotManager::detected_marker_callback, this, _1)
    );

    // service
    set_state_server = this->create_service<SetState>(ns + "/set_state", std::bind(&TangerbotManager::set_state, this, _1, _2));
    
    // action
    parking_server = rclcpp_action::create_server<Parking>(
        this,
        ns + "parking",
        std::bind(&TangerbotManager::parking_handle_goal, this, _1, _2),
        std::bind(&TangerbotManager::parking_handle_cancel, this, _1),
        std::bind(&TangerbotManager::parking_handle_accepted, this, _1)
    );

    // parameters
    auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
    param_desc.integer_range.resize(1);
    param_desc.integer_range[0].from_value = 0;
    param_desc.integer_range[0].to_value = 1000;
    param_desc.integer_range[0].step = 1;
    this->declare_parameter("workload", 0);
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

/***********************************************
 * * update_battery
 * It decreases the battery level based on the robot's motion status and recharges it when idle.
 * @param robotID The ID of the robot
 * @param currentBattery The current battery level
************************************************/
void TangerbotManager::update_battery() {
    Battery battery_sensor;  
    float battery_percentage = battery_sensor.get_battery();  

    RCLCPP_INFO(this->get_logger(), "Battery percentage: %.2f%%", battery_percentage);
    if (battery_percentage == 0 || battery_percentage == 100) return;
    this->battery = battery_percentage; 
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

void TangerbotManager::detected_marker_callback(const DetectedMarker::SharedPtr msg) {
    std::lock_guard<std::mutex> lock(marker_mutex);
    detected_marker_msg = *msg;
}

//TODO
/************************************************
 * * State Callbacks
 * @description: This function is called every 500ms to update the robot's state.
************************************************/   
void TangerbotManager::state_callbacks() {
    std::thread{std::bind(&TangerbotManager::publish_robot_state, this)}.detach();
}

/************************************************
 * * CONSTRUCTOR 
 * @node_name: tangerbot_manager
 * @description: raw 계산결과 퍼센트로 변경
 ************************************************/
float Battery::calculate_percentage(int value) {
    if (value < min_value_)
        return 0.0f;
    else if (value > max_value_)
        return 100.0f;
    else
        return (float)(value - min_value_) / (max_value_ - min_value_) * 100.0f;
}



/*************************************************
 * Parking Action Server
 *************************************************/
rclcpp_action::GoalResponse TangerbotManager::parking_handle_goal(
        const rclcpp_action::GoalUUID &uuid,
        std::shared_ptr<const Parking::Goal> goal
)
{
    RCLCPP_INFO(this->get_logger(), "Received goal request with marker id: %d", goal->marker_id);
    (void)uuid;
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}
rclcpp_action::CancelResponse TangerbotManager::parking_handle_cancel(
const std::shared_ptr<GoalHandlerParking> goal_handle)
{
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
}

void TangerbotManager::parking_handle_accepted(const std::shared_ptr<GoalHandlerParking> goal_handle) {
    std::thread{std::bind(&TangerbotManager::parking_execute, this, _1), goal_handle}.detach();
}

void TangerbotManager::parking_execute(const std::shared_ptr<GoalHandlerParking> goal_handle) {
    RCLCPP_INFO(this->get_logger(), "Execute parking");
    auto prev_time = std::chrono::high_resolution_clock::now();
    auto stop_cmd_vel = Twist();
    stop_cmd_vel.linear.x = 0.0;
    stop_cmd_vel.angular.z = 0.0;
    auto cmd_vel_msg = Twist();
    auto back_cmd_vel = Twist();
    back_cmd_vel.linear.x = -0.1;
    const auto goal = goal_handle->get_goal();
    int target_marker_id = goal->marker_id;
    auto result = std::make_shared<Parking::Result>();

    double x_tolerance = 0.03;
    double z_tolerance = 0.03;
    rclcpp::Rate loop_rate(5);
    while(rclcpp::ok()) {
        if (goal_handle->is_canceling()) {
            result->success = false;
            goal_handle->canceled(result);
            RCLCPP_INFO(this->get_logger(), "Action Parkin goal canceled");
            return;
        }


        int try_count = 0;
        int marker_index;
        bool marker_found = false;
        bool rotate_direction = true;
        while (rclcpp::ok() && !marker_found) {
            cmd_vel_pub->publish(back_cmd_vel);
            back_cmd_vel.angular.z = rotate_direction ? 0.5 : -0.5;
            rotate_direction = !rotate_direction;
            
            const int check_intervals = 10; 
            for (int i = 0; i < check_intervals; ++i) {
                {
                    std::lock_guard<std::mutex> lock(marker_mutex);
                    marker_index = find_index(detected_marker_msg.marker_id, target_marker_id);
                }

                if (marker_index != -1) {
                    cmd_vel_pub->publish(stop_cmd_vel);
                    RCLCPP_INFO(this->get_logger(), "Marker %d detected immediately!", target_marker_id);
                    marker_found = true;
                    break;
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }

                if (marker_found) {
                    break; 
                }

                cmd_vel_pub->publish(stop_cmd_vel);
                RCLCPP_INFO(this->get_logger(), "Marker %d not detected (try %d)", target_marker_id, try_count + 1);

                try_count++;
                if (try_count >= 5) {
                    result->success = false;
                    goal_handle->abort(result);
                    return;
                }

            std::this_thread::sleep_for(std::chrono::seconds(1)); 
        }
<<<<<<< HEAD
        //
        std::vector<int> v;
        v.push_back(local_marker_msg.marker_id);
        //
        int marker_index = find_index(v, target_marker_id);
        // int marker_index = find_index(local_marker_msg.marker_id, target_marker_id);
        if (marker_index == -1) {
            result->success = false;
            goal_handle->abort(result);
            cmd_vel_pub->publish(stop_cmd_vel);
            return;
        }
        
        // double x = local_marker_msg.relative_point[marker_index].x;
        // double z = local_marker_msg.relative_point[marker_index].z;
        
        double x = local_marker_msg.relative_point.x;
        double z = local_marker_msg.relative_point.z;

=======
        
        double x = detected_marker_msg.relative_point[marker_index].x;
        double z = detected_marker_msg.relative_point[marker_index].z;
>>>>>>> dev
        RCLCPP_INFO(this->get_logger(), "x: %lf, z: %lf", x, z);
        auto current_time = std::chrono::high_resolution_clock::now();
        auto dt = std::chrono::duration<double>(current_time - prev_time).count();
        pid_angular.set_dt(dt);
        pid_linear.set_dt(dt);
        cmd_vel_msg.linear.x = pid_linear.compute(z, 0.15);
        cmd_vel_msg.angular.z = pid_angular.compute(0.0, x);

        if (std::abs(0.15 - z) <= z_tolerance && std::abs(x) <= x_tolerance) {
            result->success = true;
            goal_handle->succeed(result);
            cmd_vel_pub->publish(stop_cmd_vel);
            return;
        }

        cmd_vel_pub->publish(cmd_vel_msg);

        prev_time = std::chrono::high_resolution_clock::now();
        loop_rate.sleep();
    }
}


/************************************************
 * * CONSTRUCTOR 
 * @node_name: tangerbot_manager
 * @description: raw값 평균계산 후 퍼센트 변경요청 및 퍼센트 반환
 ************************************************/
float Battery::get_battery(int sample_count) {
    std::vector<int> values;
    for (int i = 0; i < sample_count; i++) {
        int value = read_adc_value();
        values.push_back(value);
        usleep(100000);  // 0.1초 대기
    }
    
    // 평균값 계산
    int sum = 0;
    for (int v : values) sum += v;
    int avg_value = sum / values.size();
    
    // 퍼센트 계산
    return calculate_percentage(avg_value);
}

/************************************************
 * * CONSTRUCTOR 
 * @node_name: tangerbot_manager
 * @description: 배터리 칩셋 요청 (배터리 전압 반환 요청 및 결과 로우데이터 반환)
 ************************************************/
int Battery::read_adc_value() {
    // ADS1115에 읽기 명령 전송 (변환 시작)
    uint8_t config[3] = {0x01, 0xC3, 0x83};  // AIN0, 4.096V, 128SPS, single-shot
    write(file_, config, 3);

    // 변환 대기 후 레지스터 포인터로 읽기
    uint8_t pointer[1] = {0x00};  // 데이터 레지스터 포인터
    write(file_, pointer, 1);
    usleep(100000);  // 변환 대기
    
    uint8_t data[2];
    read(file_, data, 2);
    // 16비트 데이터를 결합하여 반환
    int16_t raw = (data[0] << 8) | data[1];

    return raw;
}

int TangerbotManager::find_index(const std::vector<int>& vec, int value) {
    auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        return static_cast<int>(it - vec.begin());
    } else {
        return -1;
    }
}

void TangerbotManager::publish_robot_state() {
    update_battery(); 

    auto msg = tangerbot_msgs::msg::RobotState();
    msg.robot_id = robot_id;
    msg.main_status = main_status;
    msg.motion_status = motion_status;
    msg.battery = battery;
    msg.workload = workload;

    state_publisher->publish(msg);
}

void TangerbotManager::update_workload() {
    if (motion_status == RobotState::LOADING) {
        workload -= 100;
        if (workload <= 0) {
            workload = 0;
        }
    } else if (main_status == RobotState::WORKING && motion_status != RobotState::MOVING) {
        workload += 10;
        if (workload >= 1000) {
            workload = 1000;
        }
    }
}

int main(int argc , char **argv) {
    rclcpp::init(argc, argv);
    auto pub = std::make_shared<TangerbotManager>();
    rclcpp::spin(pub);
    rclcpp::shutdown();
    return 0;
}
