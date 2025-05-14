#ifndef TANGERINE_H
#define TANGERINE_H

#include <QMainWindow>
#include <QString>
#include <rclcpp/rclcpp.hpp>
#include <rviz_common/visualization_manager.hpp>
#include <rviz_common/render_panel.hpp>
#include <rviz_common/display.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include "tangerbot_msgs/srv/handle_command.hpp"
#include <chrono>
#include <string>


namespace Ui { 
    class Tangerine; 
}


class Tangerine : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tangerine(QWidget *parent = nullptr);
    bool get_called_robot();
    ~Tangerine();

private slots:
    void handle_selection(QString section);

private:
    Ui::Tangerine *ui;

    std::string user_id = "user1";

    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr goal_pub_;
    rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_subscriber_;
    rclcpp::Client<tangerbot_msgs::srv::HandleCommand>::SharedPtr handle_command_client;
    
    bool map_received_;
    QImage map_image_;

    bool called_robot = false;
};

#endif
