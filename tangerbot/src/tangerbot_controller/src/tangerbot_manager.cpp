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

    this->battery = battery_percentage;  
}

//TODO
/************************************************
 * * State Callbacks
 * @description: This function is called every 500ms to update the robot's state.
************************************************/   
void TangerbotManager::state_callbacks() {
    update_battery(); 

    auto msg = tangerbot_msgs::msg::RobotState();
    msg.robot_id = robot_id;
    msg.main_status = main_status;
    msg.motion_status = motion_status;
    msg.battery = battery;

    state_publisher->publish(msg);
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

int main(int argc , char **argv) {
    rclcpp::init(argc, argv);
    auto pub = std::make_shared<TangerbotManager>();
    rclcpp::spin(pub);
    rclcpp::shutdown();

    return 0;
}
