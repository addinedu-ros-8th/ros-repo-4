#include "tangerbot_server/path_planner.h"
#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/srv/path_planning.hpp"
#include "geometry_msgs/msg/point.hpp"
#include <vector>

using PathPlanning = tangerbot_msgs::srv::PathPlanning;

/**********************************************
 * * Constructor
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
    if (request->robot_id.empty()) {
        RCLCPP_ERROR(this->get_logger(), "No robot IDs provided");
        return;
    }
    if (request->end.empty()) {
        RCLCPP_ERROR(this->get_logger(), "No end conditions provided");
        return;
    }

    response->results.clear();
    /******************************************************************************************
     * * Populating Results
     * * Robot ID / Waypoints / Distances
     * @brief Handle multiple robots' path planning requests
     * @param request->robot_id
     * @param request->end
     * @param response->results
    ******************************************************************************************/
    for (size_t i = 0; i < request->robot_id.size(); ++i) {
        
        /**************************************
        * * ROBOT ID 
        **************************************/
        RCLCPP_INFO(this->get_logger(), "Planning for robot %s with end condition %d",
                    request->robot_id[i].c_str(), request->end[i]);
        
        tangerbot_msgs::msg::PathResult result;
        result.robot_id = request->robot_id[i];

    
        /**************************************
        * * SETUP GOAL  
        * This is a placeholder for the actual goal setup
        **************************************/
        geometry_msgs::msg::Point waypoint;
        waypoint.x = 0.1 * (i + 1); 
        waypoint.y = 0.2 * (i + 1);
        waypoint.z = 0.0;
        result.waypoints.push_back(waypoint);
        result.distances.push_back(0.1 * (i + 1));

        response->results.push_back(result);
    }    

    RCLCPP_INFO(this->get_logger(), "Path computed with %zu waypoints", response->results.size());
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