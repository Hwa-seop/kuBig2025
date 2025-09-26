import rospy
from geometry_msgs.msg import Twist

class Pub_class:
    def __init__(self):
        rospy.init_node("hyunho_pub_node") #1. node의 이름 설정
        self.pub_node = rospy.Publisher("/cmd_vel",Twist,queue_size=1)
        
    def run(self):
        msg = Twist()
        n=0
        while not rospy.is_shutdown():
            msg.linear.x = 0.5
            self.pub_node.publish(msg)

pub_class = Pub_class()
pub_class.run()