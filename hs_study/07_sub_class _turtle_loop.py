import rospy
from turtlesim.msg import Color
from geometry_msgs.msg import Twist

class Sub_class:
    def __init__(self):
        rospy.init_node("hyunho_sub_node")
        rospy.Subscriber("/turtle1/color_sensor",Color,self.int_cb)
        self.pub_node = rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=1)

    def int_cb(self,msg):
        cmd_msg = Twist()
        cmd_msg.linear.x = 0.1
        print(msg)
        self.pub_node.publish(cmd_msg)
        
sub_class = Sub_class()
rospy.spin()