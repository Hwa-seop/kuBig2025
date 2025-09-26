import rospy
from sensor_msgs.msg import CompressedImage
from geometry_msgs.msg import Twist
from cv_bridge import CvBridge
from math import *
import cv2
import numpy as np 
import os
class Sub_class:
    def __init__(self):
        rospy.init_node("hyunho_sub_node")
        rospy.Subscriber("/camera/rgb/image_raw/compressed",CompressedImage,self.int_cb)
        self.cmd_pub = rospy.Publisher("/cmd_vel",Twist,queue_size=1)
        self.cmd_msg = Twist()
        self.bridge = CvBridge()
    
    def int_cb(self,msg:CompressedImage):
        os.system('clear')
        cv_img = self.bridge.compressed_imgmsg_to_cv2(msg)
        y,x, channel = cv_img.shape
        # print(y,x, channel)
        hsv_img = cv2.cvtColor(cv_img,cv2.COLOR_BGR2HSV)
        h,s,v = cv2.split(hsv_img)

        color_1_lower = np.array([15,100,0])
        color_1_upper = np.array([45,255,255])
        color_1_filter = cv2.inRange(hsv_img,color_1_lower,color_1_upper)

        # color_2_lower = np.array([105,100,0])
        # color_2_upper = np.array([135,255,255])
        # color_2_filter = cv2.inRange(hsv_img,color_2_lower,color_2_upper)

        # combine_img = cv2.bitwise_or(color_1_filter,color_2_filter)

        and_img = cv2.bitwise_and(cv_img,cv_img,mask=color_1_filter)

        x1 = 60
        x2 = 230
        y2 = 330
        src1 = [x1,y]
        src2 = [x2,y2]
        src3 = [x-x2,y2]
        src4 = [x-x1, y]
        srcs = np.float32([src1,src2,src3,src4])

        x3 = 80
        dst1=[x3,y]
        dst2=[x3,0]
        dst3=[x-x3,0]
        dst4=[x-x3,y]
        dsts=np.float32([dst1,dst2,dst3,dst4])
        matrix = cv2.getPerspectiveTransform(srcs,dsts)
        warp_img = cv2.warpPerspective(color_1_filter,matrix,[x,y])
        color_warp_img = cv2.warpPerspective(cv_img,matrix,[x,y])
        bin_img = np.zeros_like(warp_img)
        bin_img[warp_img!=0]=1

        window_n = 6
        window_h = y//window_n


        historgram = np.sum(bin_img,axis=0)
        print(historgram)
        historgram[historgram<100]=0
        left_hist = historgram[0:x//2]
        right_hist = historgram[x//2:x]
        left_indices = np.nonzero(left_hist)[0]
        right_indices = np.nonzero(right_hist)[0]
        left_avg_index = (left_indices[0]+left_indices[-1]) //2
        right_avg_index = (right_indices[0]+right_indices[-1])//2 + x//2

        avg_index = (left_avg_index+right_avg_index) //2
        cv2.line(color_warp_img,[avg_index,0],[avg_index,y],[0,0,255],3)
        cv2.line(color_warp_img,[x//2,0],[x//2,y],[0,255,0],3)
        np.nonzero(historgram)
        goal_index = x//2
        diff_index = goal_index-avg_index

        self.cmd_msg.linear.x = 0.1
        self.cmd_msg.angular.z = diff_index*pi/x
        self.cmd_pub.publish(self.cmd_msg)
        cv2.imshow("cv_img",cv_img)
        cv2.imshow("warp_img",warp_img)
        cv2.imshow("bin_img",bin_img)
        cv2.imshow("color_warp_img",color_warp_img)
        cv2.waitKey(1)


sub_class = Sub_class()
rospy.spin()