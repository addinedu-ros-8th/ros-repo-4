#ifndef PATH_PLANNER_H
#define PATH_PLANNER_H
// Other Libraries
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include <opencv2/opencv.hpp>

//Msg
#include "nav_msgs/msg/occupancy_grid.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "tangerbot_msgs/action/path_planning.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav_msgs/srv/get_map.hpp"
#include "tangerbot_msgs/msg/robot_pose.hpp"

//STL
#include <utility>
#include <vector>

using namespace std;
using Point = pair<int, int>;

struct Score {
    Point pos;
    float f_score;

    bool operator>(const Score& other) const {
        return f_score > other.f_score;
    }
};

class PathPlanner : public rclcpp::Node {
    using OccupancyGrid = nav_msgs::msg::OccupancyGrid;
    using PathPlanning = tangerbot_msgs::action::PathPlanning;
    using GoalHandlePathPlanning = rclcpp_action::ServerGoalHandle<PathPlanning>;
    using PoseStamped = geometry_msgs::msg::PoseStamped;
    using RobotPose = tangerbot_msgs::msg::RobotPose;
public:
    PathPlanner(const rclcpp::NodeOptions & options);

private:
    // Variables
    string ns[3] = {"robot1", "robot2", "robot3"};
    rclcpp_action::Server<PathPlanning>::SharedPtr path_planning_server;
    std::unordered_map<string, rclcpp::Subscription<OccupancyGrid>::SharedPtr> costmap_sub;
    rclcpp::Subscription<RobotPose>::SharedPtr robot_pose_sub;
    rclcpp::Client<nav_msgs::srv::GetMap>::SharedPtr get_map_client;

    geometry_msgs::msg::Point origin;
    std::unordered_map<string, cv::Mat> costmap;
    cv::Mat map;
    std::unordered_map<std::string, PoseStamped> robot_pose;
    //geometry_msgs::msg::PoseStamped goal_pose;

    // Functions
    void costmap_callback(const OccupancyGrid::SharedPtr msg, string ns);
    void robot_pose_callback(const RobotPose::SharedPtr msg);

    pair<vector<pair<double, double>>, float> astar(const cv::Mat& binary_map, const cv::Mat& dist_map, Point start, Point goal, float k);
    nav_msgs::msg::Path add_orientation(const vector<pair<double, double>> path, PoseStamped goal_pose, string frame_id = "map");

    rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const PathPlanning::Goal> goal);

    rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandlePathPlanning> goal_handle);

    void handle_accepted(const std::shared_ptr<GoalHandlePathPlanning> goal_handle);

    void execute(const std::shared_ptr<GoalHandlePathPlanning> goal_handle);

    void map_callback(rclcpp::Client<nav_msgs::srv::GetMap>::SharedFuture future);
};

#endif //PATH_PLANNER_H