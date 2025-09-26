import rospy
from std_msgs.msg import Int32

class Sub_class:
    def __init__(self):
        rospy.init_node("hyunho_sub_node")
        rospy.Subscriber("/counter",Int32,self.int_cb)

    def int_cb(self,msg):
        print(msg)

sub_class = Sub_class()
rospy.spin()