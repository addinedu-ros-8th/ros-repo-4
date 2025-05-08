#include "tangerbot_server/path_planner.h"
#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/srv/path_planning.hpp"
#include "geometry_msgs/msg/point.hpp"
#include <vector>

using PathPlanning = tangerbot_msgs::srv::PathPlanning;

/**********************************************
 * * Constructor <PathPlanner>
 **********************************************/

PathPlanner::PathPlanner() : rclcpp::Node("path_planner") {
    using namespace std::placeholders;
    path_planning_server = this->create_service<PathPlanning>(
        "path_planning",
        std::bind(&PathPlanner::path_planning_callback, this, _1, _2)
    );
}

/**********************************************
 * * Service Callback
 **********************************************/
void PathPlanner::path_planning_callback(const std::shared_ptr<PathPlanning::Request> request,
                                    std::shared_ptr<PathPlanning::Response> response)
{   
    RCLCPP_INFO(this->get_logger(), "Path Planning!");

    /******************************************************************************************
     * * Populating Robot ID List
     * @brief Assigns a robot ID to the response based on the request
    ******************************************************************************************/
    std::vector<std::string> robotIDList; 
    if (!request->robot_id.empty()) {
        robotIDList.push_back(request->robot_id);
    }
    //robotIDList.push_back("robot1"); //debug
    response->robot_id = robotIDList;


    /******************************************************************************************
     * * Populating Waypoints List
     * @brief Provides a list of waypoints for the robot to navigate
    ******************************************************************************************/
    auto waypoint = geometry_msgs::msg::Point();
    waypoint.x = 0.1;
    waypoint.y = 0.2;
    std::vector<geometry_msgs::msg::Point> waypoints;
    waypoints.push_back(waypoint);
    response->waypoints = waypoints;


    /****************************************************************************************** 
     * * Populating Distance List
     * @brief Provides a list of distances associated with the waypoints (meter).
    ******************************************************************************************/
    std::vector<float> distance_list;
    distance_list.push_back(0.1);
    response->distance = distance_list;
}

/**********************************************
 * * Main Function
 **********************************************/

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PathPlanner>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}