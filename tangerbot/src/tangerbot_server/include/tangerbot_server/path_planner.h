#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/srv/path_planning.hpp"

class PathPlanner : public rclcpp::Node {
    using PathPlanning = tangerbot_msgs::srv::PathPlanning;
public:
    PathPlanner();
private:
    rclcpp::Service<PathPlanning>::SharedPtr path_planning_server;
    void path_planning_callback(const std::shared_ptr<PathPlanning::Request> request,
    std::shared_ptr<PathPlanning::Response> reponse);
};