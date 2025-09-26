import rospy
from std_msgs.msg import Int32

class Pub_class:
    def __init__(self):
        rospy.init_node("hyunho_pub_node") #1. node의 이름 설정
        self.pub_node = rospy.Publisher("/counter",Int32,queue_size=1)
        
    def run(self):
        msg = Int32()
        n=0
        while not rospy.is_shutdown():
            msg.data = n
            self.pub_node.publish(msg)

pub_class = Pub_class()
pub_class.run()