#ifndef TANGERINE_H
#define TANGERINE_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QMovie>
#include <QCoreApplication>
#include <QDialog>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include "tangerbot_msgs/msg/call_state.hpp"
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <tangerbot_msgs/msg/decoded_voice.hpp>
#include "tangerbot_msgs/msg/robot_state.hpp"

#include "tangerbot_msgs/srv/handle_command.hpp"
#include "tangerbot_msgs/srv/sign_up.hpp"
#include "tangerbot_msgs/srv/handle_raw_voice.hpp"

#include "user_gui/recording_dialog.h"

#include <chrono>
#include <string>
#include <utility>

class CircularProgressBar;
class BatteryWidget;
class RecordingDialog;

namespace Ui { 
    class Tangerine; 
}

/****************************************************** 
  Using
*******************************************************/
using PoseStamped = geometry_msgs::msg::PoseStamped;
using OccupancyGrid = nav_msgs::msg::OccupancyGrid;
using HandleCommand = tangerbot_msgs::srv::HandleCommand;
using CallState = tangerbot_msgs::msg::CallState;
using DecodedVoice = tangerbot_msgs::msg::DecodedVoice;
using RobotState = tangerbot_msgs::msg::RobotState;
using SignUp = tangerbot_msgs::srv::SignUp;
using HandleRawVoice = tangerbot_msgs::srv::HandleRawVoice;


class Tangerine : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tangerine(QWidget *parent = nullptr);
    bool get_called_robot();
    ~Tangerine();

private slots:
    void handle_selection(QString section);
    void process_audio_data(QByteArray audio_data);

private:
    Ui::Tangerine *ui;

    std::string user_id = "user1";
    std::string robot_id = "robot1";

    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<PoseStamped>::SharedPtr goal_pub_;
    rclcpp::Publisher<DecodedVoice>::SharedPtr decoded_voice_pub;
    rclcpp::Subscription<OccupancyGrid>::SharedPtr map_subscriber_;
    rclcpp::Subscription<CallState>::SharedPtr call_state_sub;
    rclcpp::Subscription<RobotState>::SharedPtr robot_state_sub;


    rclcpp::Client<HandleCommand>::SharedPtr handle_command_client;
    rclcpp::Client<SignUp>::SharedPtr signup_client;
    rclcpp::Client<HandleRawVoice>::SharedPtr handle_raw_voice_client;


    bool map_received_;
    QImage map_image_;
    QMovie *loading;
    CircularProgressBar *circular_progressbar;
    CircularProgressBar *battery_circular_progressbar;
    BatteryWidget *battery_widget;
    RecordingDialog *record_dialog;

    bool called_robot = false;
    int current_robottab_index = 0;
    int total_eta = -1;
    bool follow_mode = false;

    void call_state_callback(const CallState::SharedPtr msg);
    void robot_state_callback(const RobotState::SharedPtr msg);
    void signup_response_callback(rclcpp::Client<SignUp>::SharedFuture future);
    
    void request_signup();
    std::pair<bool, std::string> check_signup_validation();

    void request_follwing();

    void start_recording();
};

#endif
