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
using RobotPose = tangerbot_msgs::msg::RobotPose;
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
    
    for (const auto& robot_id : ns) {
        costmap_sub[robot_id] = this->create_subscription<OccupancyGrid>(
        robot_id + "/global_costmap/costmap", 10, [this, robot_id](const OccupancyGrid::SharedPtr msg){
            this->costmap_callback(msg, robot_id);
        });
    }

    robot_pose_sub = this->create_subscription<RobotPose>(
        "/robot_pose", 10, std::bind(&PathPlanner::robot_pose_callback, this, _1)
    );

    get_map_client = this->create_client<nav_msgs::srv::GetMap>("robot3/map_server/map");

    while (!get_map_client->wait_for_service(std::chrono::seconds(1))) {
        RCLCPP_INFO(this->get_logger(), "Waiting for /map service...");
    }
    auto request = std::make_shared<nav_msgs::srv::GetMap::Request>();
    auto result_future = get_map_client->async_send_request(
        request,
        std::bind(&PathPlanner::map_callback, this, std::placeholders::_1));
}

void PathPlanner::costmap_callback(const OccupancyGrid::SharedPtr msg, string ns) {
    int width = msg->info.width;
    int height = msg->info.height;
    origin = msg->info.origin.position;
    const std::vector<int8_t> &data = msg->data;

    RCLCPP_INFO(this->get_logger(), "%s Costmap Callback Map width: %d, height: %d", ns.c_str(), width, height);

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

    cv::resize(result, result, cv::Size(width*5, height*5));
    costmap[ns] = result;
}

void PathPlanner::map_callback(rclcpp::Client<nav_msgs::srv::GetMap>::SharedFuture future) {
    auto response = future.get();                     // GetMap::Response::SharedPtr
    auto& msg = response->map;   
    int width = msg.info.width;
    int height = msg.info.height;
    origin = msg.info.origin.position;
    const std::vector<int8_t> &data = msg.data;

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

    cv::resize(result, result, cv::Size(width*5, height*5));
    map = result;
}

void PathPlanner::robot_pose_callback(const RobotPose::SharedPtr msg) {
    auto robot_id = msg->robot_id;
    robot_pose[robot_id] = msg->pose;
}

pair<vector<pair<double, double>>, float> PathPlanner::astar(const cv::Mat& binary_map, const cv::Mat& dist_map, Point start, Point goal, float k) {
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
            vector<Point> raw_path;
            vector<pair<double, double>> path;
            Point cur = current; 
            while (came_from.count(hash(cur))) {
                raw_path.push_back(cur);
                cur = came_from[hash(cur)];
            }
            path.push_back({start.first / 100.0f, start.second / 100.0f});
            RCLCPP_INFO(this->get_logger(), "Path found! start x: %lf, y: %lf", start.first / 100.0f, start.second / 100.0f);
            reverse(raw_path.begin(), raw_path.end());

            float total_dist = 0.0f;
            for (size_t i = 0; i < raw_path.size(); ++i) {
                double x = (raw_path[i].first - map_pose.first) / 100.0f;
                double y = (raw_path[i].second - map_pose.second) / 100.0f;
                //RCLCPP_INFO(this->get_logger(), "Path x: %lf, y: %lf", x, y);
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

nav_msgs::msg::Path PathPlanner::add_orientation(const vector<pair<double, double>> path, PoseStamped goal_pose, string frame_id) {
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
            auto pose_stamped = geometry_msgs::msg::PoseStamped();
            pose_stamped.header.frame_id = frame_id;
            pose_stamped.pose.position.x = x;
            pose_stamped.pose.position.y = y;
            pose_stamped.pose.position.z = 0.0;
            pose_stamped.pose.orientation.x = goal_pose.pose.orientation.x;
            pose_stamped.pose.orientation.y = goal_pose.pose.orientation.y;
            pose_stamped.pose.orientation.z = goal_pose.pose.orientation.z;
            pose_stamped.pose.orientation.w = goal_pose.pose.orientation.w;
            path_with_orientation.poses.push_back(pose_stamped);
            continue;
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
    auto original_goal_pose = goal->goal;
    auto robot_id = goal->robot_id;
    auto feedback = std::make_shared<PathPlanning::Feedback>();
    auto result = std::make_shared<PathPlanning::Result>();

    cv::Mat dist;
    cv::distanceTransform(costmap[robot_id], dist, cv::DIST_L2, 5);

    Point start, goal_pose, map_pose;
    map_pose.first = -origin.x * 100;
    map_pose.second = -origin.y * 100;
    start.first = static_cast<int>(robot_pose[robot_id].pose.position.x * 100) + map_pose.first;
    start.second = static_cast<int>(robot_pose[robot_id].pose.position.y * 100) + map_pose.second;
    goal_pose.first = static_cast<int>(original_goal_pose.pose.position.x * 100) + map_pose.first;
    goal_pose.second = static_cast<int>(original_goal_pose.pose.position.y * 100) + map_pose.second;

    auto [path, distance] = this->astar(costmap[robot_id], dist, start, goal_pose, 10.0);
    if (path.empty()) {
        RCLCPP_INFO(this->get_logger(), "Path planning with original map");
        std::tie(path, distance) = this->astar(map, dist, start, goal_pose, 10.0);
    }
   
    if (path.empty()) {
        auto result = std::make_shared<PathPlanning::Result>();
        result->robot_id = goal->robot_id;
        result->path = {};
        result->error_code = PathPlanning::Result::NO_PATH;
        result->error_msg = "A* failed: no path found";

        goal_handle->abort(result);
        return;
    }

    cv::Mat img_show = costmap[robot_id];
    for (auto each : path) {
        RCLCPP_INFO(this->get_logger(), "Path x: %lf, y: %lf", each.first, each.second);
        cv::circle(img_show, cv::Point(map_pose.first + each.first * 100, map_pose.second + each.second * 100), 5, cv::Scalar(0, 0, 0), -1);
    }
    RCLCPP_INFO(this->get_logger(), "Redeay for sending path");
    auto path_msg = nav_msgs::msg::Path();
    path_msg = this->add_orientation(path, original_goal_pose, "map");

    
    // Check if goal is done
    if (rclcpp::ok()) {
        result->robot_id = goal->robot_id;
        result->path = path_msg;
        result->distance = distance;
        goal_handle->succeed(result);
        RCLCPP_INFO(this->get_logger(), "Goal succeeded");
    }
    cv::imshow("Occupancy Grid Map", img_show);
    cv::waitKey(0); 
}

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PathPlanner>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}