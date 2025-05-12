#include "tangerbot_server/path_planner.h"
#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/srv/path_planning.hpp"
#include "geometry_msgs/msg/point.hpp"
#include <vector>
using PathPlanning = tangerbot_msgs::srv::PathPlanning;
PathPlanner::PathPlanner() : rclcpp::Node("path_planner") {
    using namespace std::placeholders;
    path_planning_server = this->create_service<PathPlanning>(
        "path_planning",
        std::bind(&PathPlanner::path_planning_callback, this, _1, _2)
    );
}

void PathPlanner::path_planning_callback(const std::shared_ptr<PathPlanning::Request> request,
                                    std::shared_ptr<PathPlanning::Response> response)
{
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Path Planning!");
    std::vector<std::string> robot_id_list;
    robot_id_list.push_back("robot1");
    response->robot_id = robot_id_list;
    auto waypoint = geometry_msgs::msg::Point();
    waypoint.x = 0.1;
    waypoint.y = 0.2;
    std::vector<geometry_msgs::msg::Point> waypoints;
    waypoints.push_back(waypoint);
    response->waypoints = waypoints;
    std::vector<float> distance_list;
    distance_list.push_back(0.1);
    response->distance = distance_list;
}

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PathPlanner>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}