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
        
    def set_transform(self, data, transform_stamped, child_frame_id):
        transform_stamped.header.frame_id = data[child_frame_id]["header"]["frame_id"]
        transform_stamped.header.stamp = self.get_clock().now().to_msg()
        transform_stamped.child_frame_id = child_frame_id
        transform_stamped.transform.translation.x = data[child_frame_id]["transform"]["translation"]['x']
        transform_stamped.transform.translation.y = data[child_frame_id]["transform"]["translation"]['y']
        transform_stamped.transform.translation.z = data[child_frame_id]["transform"]["translation"]['z']
        roll = math.radians(data[child_frame_id]["euler"]["roll"])
        pitch = math.radians(data[child_frame_id]["euler"]["pitch"])
        yaw = math.radians(data[child_frame_id]["euler"]["yaw"])
        q = quaternion_from_euler(roll, pitch, yaw)
        transform_stamped.transform.rotation.x = q[0]
        transform_stamped.transform.rotation.y = q[1]
        transform_stamped.transform.rotation.z = q[2]
        transform_stamped.transform.rotation.w = q[3]
        return transform_stamped
    
    def publish_marker(self):
        pkg_path = get_package_share_directory('aruco_package')
        marker_data_path = os.path.join(pkg_path, 'config', "marker.yaml")
        data = self.load_yaml_data(marker_data_path)
        
        home1 = TransformStamped()
        home1 = self.set_transform(data, home1, "home1")
        home2 = TransformStamped()
        home2 = self.set_transform(data, home2, "home2")
        home3 = TransformStamped()
        home3 = self.set_transform(data, home3, "home3")
        
        self.br.sendTransform([home1, home2, home3])
          
def main(args=None):
    rp.init(args=args)
    bc = Broadcaster()
    
  
    rp.spin(bc)
    rp.shutdown(bc)