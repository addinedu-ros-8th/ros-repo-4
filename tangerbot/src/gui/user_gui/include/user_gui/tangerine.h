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

private slots:
    void updateMonitoringMap();

private:
    Ui::Tangerine *ui;

    void setupMapSubscriber();
    void processMap(const nav_msgs::msg::OccupancyGrid::SharedPtr msg);
    void sendGoalFromClick(const QPoint &click_pos);
    void mousePressEvent(QMouseEvent *event) override;


    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr goal_pub_;
    rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_subscriber_;

    
    bool map_received_;
    QImage map_image_;
    nav_msgs::msg::MapMetaData map_metadata_;

    rviz_common::RenderPanel *robot_render_panel_;
    rviz_common::VisualizationManager *robot_vis_manager_;
    rviz_common::Display *map_display_;
};

#endif
