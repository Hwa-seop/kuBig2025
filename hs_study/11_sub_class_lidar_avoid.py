from re import L
import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
import os 
from math import *

class Sub_class:
    def __init__(self):
        rospy.init_node("hyunho_sub_node")
        rospy.Subscriber("/scan",LaserScan,self.int_cb)
        self.cmd_pub = rospy.Publisher("/cmd_vel",Twist,queue_size=1)
        self.cmd_msg = Twist()
    def int_cb(self,msg:LaserScan):
        # os.system("clear")
        deg_min=degrees(msg.angle_min)
        deg_max=degrees(msg.angle_max)
        deg_inc=degrees(msg.angle_increment)

        degs = [deg_min+deg_inc*i for i,v in enumerate(msg.ranges)]

        obstacle = []       
        for i,v in enumerate(msg.ranges):
            if -45 < degs[i] <45 and 0 < v <0.3:
                print(f"장애물:{degs[i],v}")
                obstacle.append(i)
            else :
                pass
        
        if len(obstacle)>0:
            self.cmd_msg.linear.x =0.0
            left_space = len(degs) - obstacle[-1]
            right_sapce = obstacle[0]

            if left_space > right_sapce:
                self.cmd_msg.angular.z = 0.5
                print("왼쪽으로 회전")
            else :
                self.cmd_msg.angular.z = -0.5
                print("오른쪽으로 회전")
        else :
            self.cmd_msg.linear.x =0.3
            self.cmd_msg.angular.z = 0.0
            print("직진")
        self.cmd_pub.publish(self.cmd_msg)

        



sub_class = Sub_class()
rospy.spin()