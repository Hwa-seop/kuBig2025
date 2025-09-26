import rospy
from std_msgs.msg import Int32

rospy.init_node("hyunho_pub_node") # 1. node의 이름 설정
pub_node = rospy.Publisher("/counter",Int32,queue_size=1) # 2. node의 역할 설정 - publisher
msg = Int32()
n=0

while not rospy.is_shutdown():
    msg.data = n
    n=n+1
    pub_node.publish(msg) # 3. publish


