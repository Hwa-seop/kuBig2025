import rospy
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Twist
import os
from tf.transformations import euler_from_quaternion
from math import *

class Sub_class:
    def __init__(self):
        rospy.init_node("hyunho_sub_node")
        rospy.Subscriber("/imu",Imu,self.int_cb)
        self.cmd_pub = rospy.Publisher("/cmd_vel",Twist,queue_size=1)
        self.cmd_msg = Twist()
        self.degs = [0,90,180,-90]
        
        self.i = 0
    def int_cb(self,msg:Imu):
        os.system('clear')
        
        x,y,z = euler_from_quaternion([msg.orientation.x,msg.orientation.y,msg.orientation.z,msg.orientation.w])
        pres_z = degrees(z)
        goal_deg = self.degs[self.i]
        print(f"pres_z:{pres_z}")
        print(f"goal_deg:{goal_deg}")
        diff_deg = (goal_deg-pres_z)
        print(f"diff_deg:{diff_deg}")

        diff_deg = (diff_deg + 180) % 360 - 180

        rad_deg = radians(diff_deg)
        self.cmd_msg.angular.z = rad_deg
        self.cmd_pub.publish(self.cmd_msg)
        
        print(diff_deg)
        if abs(diff_deg) < 3 :
            self.i = self.i+1
            self.i = self.i%len(self.degs)


sub_class = Sub_class()
rospy.spin()