#include <chrono>
#include <memory>
#include <cmath>
#include <deque>
#include <numeric>

#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/point_stamped.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include "tangerbot_msgs/srv/set_follow_mode.hpp"

using namespace std::chrono_literals;
using namespace std;

class PID {
public:
    PID(double Kp, double Ki, double Kd) : Kp_(Kp), Ki_(Ki), Kd_(Kd), prev_error_(0.0), integral_(0.0) {}

    double compute(double error, double dt) {
        integral_ += error * dt;
        double derivative = (error - prev_error_) / dt;
        double output = Kp_ * error + Ki_ * integral_ + Kd_ * derivative;
        prev_error_ = error;
        
        return output;
    }
private:
    double Kp_, Ki_, Kd_;
    double prev_error_;
    double integral_;
};

class VelocityController : public rclcpp::Node {
public:
    VelocityController() : Node("velocity_controller") {
        declare_parameter<double>("target_depth", 0.8);
        declare_parameter<double>("k_p", 0.8);
        declare_parameter<double>("k_i", 0.1);
        declare_parameter<double>("k_d", 0.3);
        declare_parameter<double>("k_a", 2.0);
        declare_parameter<double>("k_i_a", 0.1);
        declare_parameter<double>("k_d_a", 0.3);

        // declare_parameter<double>("max_linear", 0.3);
        // declare_parameter<double>("max_angular", 2.0);
        declare_parameter<double>("max_linear", 1.0);
        declare_parameter<double>("max_angular", 3.0);

        declare_parameter<double>("min_depth", 0.2);
        declare_parameter<double>("fu", 467.16504728177745);
        declare_parameter<double>("u0", 313.29207046554541);
        declare_parameter<double>("tolerance_x", 2.5);
        declare_parameter<double>("depth_tolerance", 0.05);

        get_parameter("depth_tolerance", depth_tolerance_);
        get_parameter("target_depth", target_depth_);
        get_parameter("k_p", k_p_);
        get_parameter("k_i", k_i_);
        get_parameter("k_d", k_d_);
        get_parameter("k_a", k_a_);
        get_parameter("k_i_a", k_i_a_);
        get_parameter("k_d_a", k_d_a_);
        get_parameter("max_linear", max_linear_);
        get_parameter("max_angular", max_angular_);
        get_parameter("min_depth", min_depth_);
        get_parameter("fu", fu_);
        get_parameter("u0", u0_);
        get_parameter("tolerance_x", tolerance_x_);

        pid_z_ = std::make_unique<PID>(k_p_, k_i_, k_d_);
        pid_x_ = std::make_unique<PID>(k_a_, k_i_a_, k_d_a_);

        set_mode_service_ = create_service<tangerbot_msgs::srv::SetFollowMode>(
            "/tserver/set_follow_mode",
            std::bind(&VelocityController::handle_set_mode, this, std::placeholders::_1, std::placeholders::_2)
        );

        object_sub_ = create_subscription<geometry_msgs::msg::PointStamped>("transformed_point", 10, std::bind(&VelocityController::object_callback, this, std::placeholders::_1));
        cmd_vel_pub_ = create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        timer_ = create_wall_timer(200ms, std::bind(&VelocityController::check_timeout, this));

        last_msg_time_ = this->now();
        last_linear_x_ = 0.0;
        last_angular_z_ = 0.0;

        RCLCPP_INFO(this->get_logger(), "Target depth set to: %.2f meters", target_depth_);
    }

private:
    void handle_set_mode(
        const std::shared_ptr<tangerbot_msgs::srv::SetFollowMode::Request> req,
        std::shared_ptr<tangerbot_msgs::srv::SetFollowMode::Response> res) {
        robot_id_ = req->robot_id;
        active_ = req->mode;
        res->success = true;

        RCLCPP_INFO(this->get_logger(),
            "Follow Mode %s for robot %s",
            active_ ? "ENABLED" : "DISABLED",
            robot_id_.c_str()
        );
    }

    void object_callback(const geometry_msgs::msg::PointStamped::SharedPtr msg) {
        if (!active_) return; 
        
        double x = msg->point.x;
        double y = msg->point.y;
        double z = msg->point.z;

        // x, y, z 검증
        if (x < 0.0 || x >= 640.0 || y < 0.0 || y >= 480.0 || z <= 0.0) {
            RCLCPP_WARN(this->get_logger(), "Invalid data: x=%.2f, y=%.2f, z=%.2f, stopping", x, y, z);
            publish_cmd_vel(0.0, 0.0);
            return;
        }

        // 깊이 이동 평균
        z_history_.push_back(z);
        if (z_history_.size() > z_history_size_) z_history_.pop_front();
        double z_avg = std::accumulate(z_history_.begin(), z_history_.end(), 0.0) / z_history_.size();

        // 너무 가까우면 정지
        if (z_avg < min_depth_) {
            RCLCPP_WARN(this->get_logger(), "Too close to object (z_avg=%.2f), stopping", z_avg);
            publish_cmd_vel(0.0, 0.0);
            return;
        }

        // 타겟 거리 허용 오차 내에 있으면 정지
        double error_z = z_avg - target_depth_;
        if (std::abs(error_z) < depth_tolerance_) {
            RCLCPP_INFO(this->get_logger(), "Reached target depth (z_avg=%.2f, target=%.2f), stopping", z_avg, target_depth_);
            publish_cmd_vel(0.0, 0.0);
            pid_z_->compute(0.0, dt_); // 적분 항 리셋
            return;
        }

        // PID 제어 - 선속도
        double linear_x = pid_z_->compute(error_z, dt_);

        // PID 제어 - 각속도
        double pixel_offset = x - u0_;
        double error_angle = std::atan2(pixel_offset, fu_);
        double angular_z = -pid_x_->compute(error_angle, dt_) * 1.5;
        if (std::abs(pixel_offset) < tolerance_x_) {
            angular_z = 0.0;
        }

        // 속도 제한
        linear_x = std::clamp(linear_x, -max_linear_, max_linear_);
        angular_z = std::clamp(angular_z, -max_angular_, max_angular_);

        // DEBUG
        RCLCPP_INFO(this->get_logger(),
            "x=%.2f y=%.2f z=%.2f z_avg=%.2f error_z=%.2f pixel_offset=%.2f error_angle=%.2f linear_x=%.2f angular_z=%.2f",
            x, y, z, z_avg, error_z, pixel_offset, error_angle, linear_x, angular_z);

        // 속도 저장 및 타임스탬프 업데이트
        last_linear_x_ = linear_x;
        last_angular_z_ = angular_z;
        last_msg_time_ = this->now();

        // cmd_vel 퍼블리시
        publish_cmd_vel(linear_x, angular_z);
    }

    void check_timeout() {
        if (!active_) return; 
        
        auto now = this->now();
        auto elapsed = (now - last_msg_time_).seconds();
        if (elapsed > 0.2) {
            RCLCPP_WARN(this->get_logger(), "No valid data for %.2f seconds, stopping", elapsed);
            last_linear_x_ *= 0.8;
            last_angular_z_ *= 0.8;
            if (std::abs(last_linear_x_) < 0.01 && std::abs(last_angular_z_) < 0.01) {
                last_linear_x_ = 0.0;
                last_angular_z_ = 0.0;
            }
            publish_cmd_vel(last_linear_x_, last_angular_z_);
        }
    }

    void publish_cmd_vel(double linear_x, double angular_z) {
        geometry_msgs::msg::Twist twist;
        twist.linear.x = linear_x;
        twist.linear.y = 0.0;
        twist.linear.z = 0.0;
        twist.angular.x = 0.0;
        twist.angular.y = 0.0;
        twist.angular.z = angular_z;
        cmd_vel_pub_->publish(twist);
    }

    rclcpp::Subscription<geometry_msgs::msg::PointStamped>::SharedPtr object_sub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::Service<tangerbot_msgs::srv::SetFollowMode>::SharedPtr set_mode_service_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::unique_ptr<PID> pid_z_;
    std::unique_ptr<PID> pid_x_;

    double target_depth_;
    double k_p_, k_i_, k_d_;
    double k_a_, k_i_a_, k_d_a_;
    double max_linear_, max_angular_;
    double min_depth_;
    double fu_, u0_;
    double tolerance_x_;
    double dt_ = 0.033;
    double depth_tolerance_;

    std::deque<double> z_history_;
    static constexpr size_t z_history_size_ = 10;

    rclcpp::Time last_msg_time_;
    double last_linear_x_;
    double last_angular_z_;

    bool active_ = false;
    std::string robot_id_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    try {
        auto node = std::make_shared<VelocityController>();
        rclcpp::spin(node);
    } catch (const std::exception& e) {
        std::cerr << "Fatal: " << e.what() << std::endl;
    }
    rclcpp::shutdown();
    
    return 0;
}
