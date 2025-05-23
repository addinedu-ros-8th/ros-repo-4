#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped
from cartographer_ros_msgs.srv import FinishTrajectory, StartTrajectory, GetTrajectoryStates
from ament_index_python.packages import get_package_share_directory


class InitialPoseHandler(Node):
    def __init__(self):
        super().__init__('initialpose_handler')
        self.subscription = self.create_subscription(
            PoseWithCovarianceStamped,
            '/initialpose',
            self.initialpose_callback,
            10)
        
        self.finish_trajectory_client = self.create_client(FinishTrajectory, '/finish_trajectory')
        self.start_trajectory_client = self.create_client(StartTrajectory, '/start_trajectory')
        self.get_trajectory_states_client = self.create_client(GetTrajectoryStates, '/get_trajectory_states')

        package_name = "pinky_cartographer"
        self.configuration_package = get_package_share_directory(package_name)
        self.configuration_directory = self.configuration_package + '/params'
        self.configuration_basename = 'nav2_cartographer_params.lua'

        self.pose = None
    
    def get_latest_trajectory_id(self):
        if not self.get_trajectory_states_client.wait_for_service(timeout_sec=5.0):
            self.get_logger().error('GetTrajectoryStates service not available')
            return None

        get_states_req = GetTrajectoryStates.Request()
        future = self.get_trajectory_states_client.call_async(get_states_req)
        future.add_done_callback(self.get_latest_trajectory_callback)
    
    def get_latest_trajectory_callback(self, future):
        """GetTrajectoryStates 서비스의 응답을 처리하는 콜백"""
        try:
            response = future.result()
            states = response.trajectory_states
            trajectory_id_list = states.trajectory_id
            latest_trajectory_id = trajectory_id_list[-1] if trajectory_id_list else None

            if latest_trajectory_id is not None:
                self.get_logger().info(f'Latest trajectory_id: {latest_trajectory_id}')
                self.set_initialpose(self.pose, latest_trajectory_id)
            else:
                self.get_logger().error('No valid trajectory ID found.')
        except Exception as e:
            self.get_logger().error(f'Failed to call GetTrajectoryStates service: {str(e)}')

    def initialpose_callback(self, msg):
        """/initialpose 토픽에서 메시지를 받을 때 호출되는 콜백"""
        self.pose = msg
        self.get_logger().info("Received initial pose, processing...")
        self.get_latest_trajectory_id()  # 최신 트래젝터리 ID를 얻고 이후 실행

    def set_initialpose(self, msg, latest_trajectory_id):
        """새로운 초기 위치를 설정하고, 기존 Trajectory를 종료 후 새 Trajectory 시작"""
        if latest_trajectory_id is None:
            return
        
        # Finish current trajectory
        if not self.finish_trajectory_client.wait_for_service(timeout_sec=5.0):
            self.get_logger().error('FinishTrajectory service not available')
            return
        
        finish_req = FinishTrajectory.Request()
        finish_req.trajectory_id = latest_trajectory_id
        future = self.finish_trajectory_client.call_async(finish_req)
        future.add_done_callback(self.finish_trajectory_callback)

    def finish_trajectory_callback(self, future):
        """FinishTrajectory 서비스 응답을 처리하는 콜백"""
        try:
            response = future.result()
            self.get_logger().info('FinishTrajectory service called successfully')

            # Start new trajectory with received initial pose
            if not self.start_trajectory_client.wait_for_service(timeout_sec=5.0):
                self.get_logger().error('StartTrajectory service not available')
                return
            
            start_req = StartTrajectory.Request()
            start_req.configuration_directory = self.configuration_directory
            start_req.configuration_basename = self.configuration_basename
            start_req.use_initial_pose = True
            start_req.initial_pose.position.x = self.pose.pose.pose.position.x
            start_req.initial_pose.position.y = self.pose.pose.pose.position.y
            start_req.initial_pose.position.z = self.pose.pose.pose.position.z
            start_req.initial_pose.orientation = self.pose.pose.pose.orientation
            start_req.relative_to_trajectory_id = 0

            future = self.start_trajectory_client.call_async(start_req)
            future.add_done_callback(self.start_trajectory_callback)
        except Exception as e:
            self.get_logger().error(f'Failed to call FinishTrajectory service: {str(e)}')

    def start_trajectory_callback(self, future):
        """StartTrajectory 서비스 응답을 처리하는 콜백"""
        try:
            response = future.result()
            self.get_logger().info('StartTrajectory service called successfully')
        except Exception as e:
            self.get_logger().error(f'Failed to call StartTrajectory service: {str(e)}')


def main(args=None):
    rclpy.init(args=args)
    node = InitialPoseHandler()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
