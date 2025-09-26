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
        os.system("clear")
        deg_min=degrees(msg.angle_min)
        deg_max=degrees(msg.angle_max)
        deg_inc=degrees(msg.angle_increment)

        degs = [deg_min+deg_inc*i for i,v in enumerate(msg.ranges)]

        obstacle = []
        mid_space = 0  
        for i,v in enumerate(msg.ranges):
            if  abs(degs[i]) <80 and 0 < v <0.3:
                # print(f"장애물:{degs[i],v}")
                obstacle.append(i)
                if len(obstacle) > 1 and obstacle[-1]-obstacle[-2] > 50:
                    mid_space = obstacle[-1]-obstacle[-2]
                    mid_avg_index = (obstacle[-1]+obstacle[-2])//2
            else :
                pass

        if len(obstacle)>0:
            self.cmd_msg.linear.x =0.0
            left_space = len(degs) - obstacle[-1]
            left_avg_index = (len(degs) + obstacle[-1]) // 2
            right_space = obstacle[0]
            right_avg_index = obstacle[0] // 2
            if max([left_space,mid_space,right_space])==left_space:
                self.cmd_msg.angular.z = radians(degs[left_avg_index])
                print("왼쪽으로 회전")
            elif max([left_space,mid_space,right_space])==right_space:
                self.cmd_msg.angular.z = radians(degs[right_avg_index])
                print("오른쪽으로 회전")
            else :
                self.cmd_msg.angular.z = radians(degs[mid_avg_index])
                print("중앙에서 회전")
        else :
            self.cmd_msg.linear.x =0.0
            self.cmd_msg.angular.z = 0.0
            print("직진")
        print(degrees(self.cmd_msg.angular.z))
        self.cmd_pub.publish(self.cmd_msg)

        



sub_class = Sub_class()
rospy.spin()