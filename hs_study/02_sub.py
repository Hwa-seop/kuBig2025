import rospy
from std_msgs.msg import Int32

rospy.init_node("hyunho_sub_node")

def int_cb(msg):
    print(msg)

rospy.Subscriber("/counter",Int32,callback=int_cb)

rospy.spin()