// Other Libraries
#include "tangerbot_server/path_planner.h"
#include <tf2/LinearMath/Quaternion.h>

//Msg
#include "std_msgs/msg/float32.hpp"

// STL
#include <queue>
#include <unordered_map>
#include <cmath>
#include <iostream>

using OccupancyGrid = nav_msgs::msg::OccupancyGrid;
using PathPlanning = tangerbot_msgs::action::PathPlanning;
using GoalHandlePathPlanning = rclcpp_action::ServerGoalHandle<PathPlanning>;
using namespace std::placeholders;
using namespace std;

using Point = pair<int, int>;

PathPlanner::PathPlanner(const rclcpp::NodeOptions & options = rclcpp::NodeOptions()) : Node("path_planner", options) {
    path_planning_server = rclcpp_action::create_server<PathPlanning>(
      this,
      "path_planning",
      std::bind(&PathPlanner::handle_goal, this, _1, _2),
      std::bind(&PathPlanner::handle_cancel, this, _1),
      std::bind(&PathPlanner::handle_accepted, this, _1));

    costmap_sub = this->create_subscription<OccupancyGrid>(
        "/global_costmap/costmap", 10, std::bind(&PathPlanner::costmap_callback, this, _1)
    );

    tracked_pose_sub = this->create_subscription<geometry_msgs::msg::PoseStamped>(
        "/tracked_pose", 10, std::bind(&PathPlanner::tracked_pose_callback, this, _1)
    );
}

void PathPlanner::costmap_callback(const OccupancyGrid::SharedPtr msg) {
    int width = msg->info.width;
    int height = msg->info.height;
    origin = msg->info.origin.position;
    const std::vector<int8_t> &data = msg->data;

    RCLCPP_INFO(this->get_logger(), "Map width: %d, height: %d", width, height);

    cv::Mat map_img(height, width, CV_8UC1);

    for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int8_t value = data[y * width + x];
                uint8_t pixel;

                if (value == 100)         pixel = 0; 
                else                    pixel = 255; 

                map_img.at<uchar>(y, x) = pixel;
            }
        }
    
    cv::Mat filled = map_img.clone();
    cv::Mat mask(filled.rows + 2, filled.cols + 2, CV_8UC1, cv::Scalar(0));
    cv::floodFill(filled, mask, cv::Point(0, 0), 128);

    cv::Mat result(filled.size(), CV_8UC1);
    for (int y = 0; y < filled.rows; ++y) {
        for (int x = 0; x < filled.cols; ++x) {
            result.at<uchar>(y, x) = (filled.at<uchar>(y, x) == 128) ? 0 : 255;
            result.at<uchar>(y, x) &= map_img.at<uchar>(y, x);
        }
    }

    cv::imshow("Occupancy Grid Map", result);
    cv::waitKey(1); 
    cv::resize(result, result, cv::Size(width*5, height*5));
    costmap = result;
}

void PathPlanner::tracked_pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) {
    tracked_pose = *msg;
}

pair<vector<Point>, float> PathPlanner::astar(const cv::Mat& binary_map, const cv::Mat& dist_map, Point start, Point goal, float k) {
    int h = binary_map.rows;
    int w = binary_map.cols;
    Point map_pose;
    map_pose.first = -origin.x * 100;
    map_pose.second = -origin.y * 100;

    cv::Mat visited = cv::Mat::zeros(binary_map.size(), CV_8U);
    unordered_map<int, Point> came_from;
    unordered_map<int, float> g_score;
    unordered_map<int, float> f_score;

    auto hash = [w](Point p) { return p.second * w + p.first; };

    auto heuristic = [&](Point pos) {
        float goal_dist = hypot(pos.first - goal.first, pos.second - goal.second);
        float obstacle_dist = dist_map.at<float>(pos.second, pos.first);
        return goal_dist - k * obstacle_dist;
    };

    priority_queue<Score, vector<Score>, greater<Score>> open_set;
    g_score[hash(start)] = 0.0f;
    f_score[hash(start)] = heuristic(start);
    open_set.push({start, f_score[hash(start)]});

    auto neighbors = [&](Point pos) {
        vector<Point> result;
        vector<Point> deltas = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& d : deltas) {
            int nx = pos.first + d.first;
            int ny = pos.second + d.second;
            if (nx >= 0 && nx < w && ny >= 0 && ny < h && binary_map.at<uchar>(ny, nx) == 255) {
                result.emplace_back(nx, ny);
            }
        }
        return result;
    };

    while (!open_set.empty()) {
        Point current = open_set.top().pos;
        open_set.pop();

        if (current == goal) {
            // Reconstruct path
            vector<Point> raw_path, path;
            Point cur = current;
            while (came_from.count(hash(cur))) {
                raw_path.push_back(cur);
                cur = came_from[hash(cur)];
            }
            path.push_back(start);
            reverse(raw_path.begin(), raw_path.end());

            float total_dist = 0.0f;
            for (size_t i = 0; i < raw_path.size(); ++i) {
                double x = (raw_path[i].first - map_pose.first) / 100.0f;
                double y = (raw_path[i].second - map_pose.second) / 100.0f;
                path.emplace_back(x, y);
                if (i > 0) {
                    float dx = raw_path[i].first - raw_path[i-1].first;
                    float dy = raw_path[i].second - raw_path[i-1].second;
                    total_dist += std::hypot(dx, dy);
                }
            }
            return {path, total_dist};
        }

        visited.at<uchar>(current.second, current.first) = 1;

        for (Point neighbor : neighbors(current)) {
            if (visited.at<uchar>(neighbor.second, neighbor.first)) continue;

            float tentative_g = g_score[hash(current)] + hypot(current.first - neighbor.first, current.second - neighbor.second);
            if (!g_score.count(hash(neighbor)) || tentative_g < g_score[hash(neighbor)]) {
                came_from[hash(neighbor)] = current;
                g_score[hash(neighbor)] = tentative_g;
                f_score[hash(neighbor)] = tentative_g + heuristic(neighbor);
                open_set.push({neighbor, f_score[hash(neighbor)]});
            }
        }
    }

    return {}; // Path not found
}

nav_msgs::msg::Path PathPlanner::add_orientation(const vector<Point> path, string frame_id) {
    nav_msgs::msg::Path path_with_orientation;
    path_with_orientation.header.frame_id = frame_id;

    for (size_t i = 0; i < path.size(); i++) {
        double x = path[i].first;
        double y = path[i].second;
        double dx, dy, yaw;
        if (i < path.size() - 1) {
            dx = path[i+1].first - x;
            dy = path[i+1].second - y;
            yaw = atan2(dy, dx);
        } else {
            dx = x - path[i-1].first;
            dy = y - path[i-1].second;
            yaw = atan2(dy, dx);
        }
        tf2::Quaternion q;
        q.setRPY(0, 0, yaw);

        auto pose_stamped = geometry_msgs::msg::PoseStamped();
        pose_stamped.header.frame_id = frame_id;
        pose_stamped.pose.position.x = x;
        pose_stamped.pose.position.y = y;
        pose_stamped.pose.position.z = 0.0;
        pose_stamped.pose.orientation.x = q[0];
        pose_stamped.pose.orientation.y = q[1];
        pose_stamped.pose.orientation.z = q[2];
        pose_stamped.pose.orientation.w = q[3];

        path_with_orientation.poses.push_back(pose_stamped);
    }
    
    return path_with_orientation;
}

rclcpp_action::GoalResponse PathPlanner::handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const PathPlanning::Goal> goal)
{
    RCLCPP_INFO(this->get_logger(), "Received goal! robot_id : %s, pose : x :%lf, y :%lf", goal->robot_id.c_str(), goal->goal.pose.position.x, goal->goal.pose.position.y);
    (void)uuid;
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse PathPlanner::handle_cancel(
    const std::shared_ptr<GoalHandlePathPlanning> goal_handle)
{
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
}

void PathPlanner::handle_accepted(const std::shared_ptr<GoalHandlePathPlanning> goal_handle)
  {
    using namespace std::placeholders;
    // this needs to return quickly to avoid blocking the executor, so spin up a new thread
    std::thread{std::bind(&PathPlanner::execute, this, _1), goal_handle}.detach();
  }

void PathPlanner::execute(const std::shared_ptr<GoalHandlePathPlanning> goal_handle)
{
    RCLCPP_INFO(this->get_logger(), "Executing goal");
    rclcpp::Rate loop_rate(1);
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<PathPlanning::Feedback>();
    auto result = std::make_shared<PathPlanning::Result>();

    cv::Mat dist;
    cv::distanceTransform(costmap, dist, cv::DIST_L2, 5);

    Point start, goal_pose, map_pose;
    map_pose.first = -origin.x * 100;
    map_pose.second = -origin.y * 100;
    start.first = static_cast<int>(tracked_pose.pose.position.x * 100) + map_pose.first;
    start.second = static_cast<int>(tracked_pose.pose.position.y * 100) + map_pose.second;

    goal_pose.first = static_cast<int>(goal->goal.pose.position.x * 100) + map_pose.first;
    goal_pose.second = static_cast<int>(goal->goal.pose.position.y * 100) + map_pose.second;

    auto [path, distance] = this->astar(costmap, dist, start, goal_pose, 5.0);

    if (path.empty()) {
        auto result = std::make_shared<PathPlanning::Result>();
        result->robot_id = goal->robot_id;
        result->path = {};
        result->error_code = PathPlanning::Result::NO_PATH;
        result->error_msg = "A* failed: no path found";

        goal_handle->abort(result);
        return;
    }

    cv::Mat img_show = costmap;
    for (auto each : path) {
        cv::circle(img_show, cv::Point(each.first, each.second), 1, cv::Scalar(0, 0, 0), -1);
    }

    auto path_msg = nav_msgs::msg::Path();
    path_msg = this->add_orientation(path, "map");

    // Check if goal is done
    if (rclcpp::ok()) {
        result->robot_id = goal->robot_id;
        result->path = path_msg;
        result->distance = distance;
        goal_handle->succeed(result);
        RCLCPP_INFO(this->get_logger(), "Goal succeeded");
    }
}

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PathPlanner>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}