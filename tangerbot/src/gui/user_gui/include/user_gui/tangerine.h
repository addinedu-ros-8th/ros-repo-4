   


#ifndef TANGERINE_H
#define TANGERINE_H

#include <QMainWindow>
#include <rclcpp/rclcpp.hpp>
#include <rviz_common/visualization_manager.hpp>
#include <rviz_common/render_panel.hpp>
#include <rviz_common/display.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>


namespace Ui { 
    class Tangerine; 
}


class Tangerine : public QMainWindow
{
  Q_OBJECT

public:
    explicit Tangerine(QWidget *parent = nullptr);
    ~Tangerine();

private:
    Ui::Tangerine *ui;
};

// private:
//   void initializeRViz();
//   void setupMapDisplay();
//   void setupMapSubscriber();
//   void setupRobotModelDisplay();
//   void setupLaserScanDisplay();
//   void setupJoystickControls();
//   void sendJoystickCommand();

//   Ui::Tangerine *ui;
//   rclcpp::Node::SharedPtr node_;
//   rviz_common::RenderPanel *main_render_panel_;  // For Main page
//   rviz_common::RenderPanel *robot_render_panel_; // For Robot page
//   rviz_common::VisualizationManager *main_vis_manager_;
//   rviz_common::VisualizationManager *robot_vis_manager_;
//   rviz_common::Display *map_display_;
//   rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher_;
//   rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr goal_pose_publisher_;
//   rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_subscriber_;
//   geometry_msgs::msg::Twist current_twist_;
//   bool map_received_;
// };

#endif // TANGERINE_H