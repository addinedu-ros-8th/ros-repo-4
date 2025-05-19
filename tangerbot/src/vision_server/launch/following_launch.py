from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    vision_server_dir = get_package_share_directory('vision_server')

    return LaunchDescription([

        # streamer.cpp 실행 노드
        Node(
            package='vision_server',
            executable='streamer',
            name='streamer_node',
            output='screen',
            parameters=[
                {'port': 14555}
            ]
        ),

        # follower.cpp 실행 노드
        Node(
            package='vision_server',
            executable='follower',
            name='follower_node',
            output='screen',
            parameters=[
                {
                    'calib_file': os.path.join(
                        vision_server_dir,
                        'config',
                        'calibration_data.yml'
                    )
                }
            ]
        ),

        # human_pose.py 실행 노드
        Node(
            package='vision_server',
            executable='human_pose',
            name='human_pose_node',
            output='screen',
            env={
                'PYTHONPATH': os.environ.get('PYTHONPATH', '') + ':/home/mu/venv/ros_python/lib/python3.12/site-packages',
                'LD_LIBRARY_PATH': os.environ.get('LD_LIBRARY_PATH', '') + ':/opt/ros/jazzy/lib',
                'HOME': os.environ['HOME'] 
            }
        ),
    ])
