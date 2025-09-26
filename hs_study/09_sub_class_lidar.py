import rospy
from sensor_msgs.msg import LaserScan
import os 
from math import *
class Sub_class:
    def __init__(self):
        rospy.init_node("hyunho_sub_node")
        rospy.Subscriber("/scan",LaserScan,self.int_cb)

    def int_cb(self,msg:LaserScan):
        os.system("clear")
        deg_min=degrees(msg.angle_min)
        deg_max=degrees(msg.angle_max)
        deg_inc=degrees(msg.angle_increment)

        degs = [deg_min+deg_inc*i for i,v in enumerate(msg.ranges)]
        
        for i,v in enumerate(msg.ranges):
            if -45 < degs[i] <45 and 0 < v <0.5:
                print(f"장애물:{degs[i],v}")


        



sub_class = Sub_class()
rospy.spin()