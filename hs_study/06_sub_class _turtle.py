import rospy
from turtlesim.msg import Color

class Sub_class:
    def __init__(self):
        rospy.init_node("hyunho_sub_node")
        rospy.Subscriber("/turtle1/color_sensor",Color,self.int_cb)

    def int_cb(self,msg):
        print(msg)

sub_class = Sub_class()
rospy.spin()