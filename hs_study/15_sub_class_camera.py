import rospy
from sensor_msgs.msg import CompressedImage
from cv_bridge import CvBridge
import cv2

class Sub_class:
    def __init__(self):
        rospy.init_node("hyunho_sub_node")
        rospy.Subscriber("/camera/rgb/image_raw/compressed",CompressedImage,self.int_cb)
        self.bridge = CvBridge()
    
    def int_cb(self,msg:CompressedImage):
        self.cv_img = self.bridge.compressed_imgmsg_to_cv2(msg)
        hsv_img = cv2.cvtColor(self.cv_img,cv2.COLOR_BGR2HSV)
        h,s,v = cv2.split(hsv_img)
        
        cv2.inRange(hsv_img,)
        cv2.imshow("h",h)
        cv2.imshow("s",s)
        cv2.imshow("v",v)

        cv2.imshow("hsv_img",hsv_img)        

        cv2.imshow("cv_img",self.cv_img)
        cv2.waitKey(1)


sub_class = Sub_class()
rospy.spin()