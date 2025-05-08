import rclpy as rp
from rclpy.node import Node

from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import TransformStamped

import yaml
import tf2_ros
from ament_index_python.packages import get_package_share_directory
import os
from tf_transformations import quaternion_from_euler
import math

class Broadcaster(Node):
    def __init__(self):
        super().__init__("broadcaster")
        
        self.br = tf2_ros.TransformBroadcaster(self)
        self.timer = self.create_timer(1.0, self.publish_marker)
        
    def load_yaml_data(self, yaml_file):
        with open(yaml_file, 'r') as file:
            return yaml.safe_load(file)
    
    def publish_marker(self):
        pkg_path = get_package_share_directory('aruco_package')
        marker_data_path = os.path.join(pkg_path, 'config', "marker.yaml")
        data = self.load_yaml_data(marker_data_path)
        
        marker15 = TransformStamped()
        marker15.header.frame_id = data["marker15"]["header"]["frame_id"]
        marker15.header.stamp = self.get_clock().now().to_msg()
        marker15.child_frame_id = data["marker15"]["child_frame_id"]
        marker15.transform.translation.x = data["marker15"]["transform"]["translation"]['x']
        marker15.transform.translation.y = data["marker15"]["transform"]["translation"]['y']
        marker15.transform.translation.z = data["marker15"]["transform"]["translation"]['z']
        roll = math.radians(data["marker15"]["euler"]["roll"])
        pitch = math.radians(data["marker15"]["euler"]["pitch"])
        yaw = math.radians(data["marker15"]["euler"]["yaw"])
        q = quaternion_from_euler(roll, pitch, yaw)
        marker15.transform.rotation.x = q[0]
        marker15.transform.rotation.y = q[1]
        marker15.transform.rotation.z = q[2]
        marker15.transform.rotation.w = q[3]
        
        self.br.sendTransform(marker15)
          
def main(args=None):
    rp.init(args=args)
    bc = Broadcaster()
    
  
    rp.spin(bc)
    rp.shutdown(bc)