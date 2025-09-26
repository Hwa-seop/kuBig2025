import rospy
from sensor_msgs.msg import Imu
import os
from tf.transformations import euler_from_quaternion
from math import degrees

class Sub_class:
    def __init__(self):
        rospy.init_node("hyunho_sub_node")
        rospy.Subscriber("/imu",Imu,self.int_cb)

    def int_cb(self,msg:Imu):
        os.system('clear')
        # print(msg.orientation)
        x,y,z = euler_from_quaternion([msg.orientation.x,msg.orientation.y,msg.orientation.z,msg.orientation.w])
        print(degrees(z))

sub_class = Sub_class()
rospy.spin()