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
public:
    PathPlanner(const rclcpp::NodeOptions & options);

private:
    // Variables
    rclcpp_action::Server<PathPlanning>::SharedPtr path_planning_server;
    rclcpp::Subscription<OccupancyGrid>::SharedPtr costmap_sub;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr tracked_pose_sub;

    geometry_msgs::msg::Point origin;
    cv::Mat costmap;
    geometry_msgs::msg::PoseStamped tracked_pose;

    // Functions
    void costmap_callback(const OccupancyGrid::SharedPtr msg);
    void tracked_pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);

    pair<vector<Point>, float> astar(const cv::Mat& binary_map, const cv::Mat& dist_map, Point start, Point goal, float k);
    nav_msgs::msg::Path add_orientation(const vector<Point> path, string frame_id = "map");

    rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const PathPlanning::Goal> goal);

    rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandlePathPlanning> goal_handle);

    void handle_accepted(const std::shared_ptr<GoalHandlePathPlanning> goal_handle);

    void execute(const std::shared_ptr<GoalHandlePathPlanning> goal_handle);
};

#endif //PATH_PLANNER_H