#!/usr/bin/env python
import rospy
import cv2
import numpy as np
import matplotlib.pyplot as plt
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
from sensor_msgs.msg import CompressedImage


class Gray():
    def __init__(self):
        # you can choose image type "compressed", "raw"
        self.selecting_sub_image = "compressed"

        if self.selecting_sub_image == "compressed":
            self._sub = rospy.Subscriber(
                'raspicam_node/image/compressed', CompressedImage, self.callback, queue_size=1)
        else:
            self._sub = rospy.Subscriber(
                'raspicam_node/image_raw', Image, self.callback, queue_size=1)

        self.bridge = CvBridge()

    def callback(self, image_msg):

        if self.selecting_sub_image == "compressed":
            # converting compressed image to opencv image
            np_arr = np.fromstring(image_msg.data, np.uint8)
            cv_image = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
        elif self.selecting_sub_image == "raw":
            cv_image = self.bridge.imgmsg_to_cv2(image_msg, "bgr8")


        # reverse image, Korean comment not allowed
        cv_image_flipped = cv2.flip(cv_image, -1)




	def HSV_yellow(img):
		hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
		low = np.array([20, 50, 100])
		high = np.array([30, 255, 255])
		yellowmask = cv2.inRange(hsv, low, high)
		return yellowmask
	
	def left_ROI(img):
    		poly = np.array([[(0,260),(0,460),(200,460),(200,260)]])
    		BG = np.zeros_like(img)
   		cv2.fillPoly(BG,poly,255)
    		masked_img = cv2.bitwise_and(img,BG)
    		return masked_img

	def right_ROI(img):
  		poly = np.array([[(420,260),(420,460),(630,460),(630,260)]])
    		BG = np.zeros_like(img)
    		cv2.fillPoly(BG,poly,255)
    		masked_img = cv2.bitwise_and(img,BG)
    		return masked_img

	def display_square(img,lines):
   		BG = np.zeros_like(img)
    		if lines is not None:
        		for line in lines:
            			x1,y1,x2,y2 = line.reshape(4)
            			cv2.line(BG,(x1,y1),(x2,y2),(0,255,0),5)
    		return BG


	def average_slope(img,lines):
    		left_fit = []
    		right_fit = []
    		if lines is not None:
        		for line in lines:
            			x1, y1, x2, y2 = line.reshape(4)
            			parameters = np.polyfit((x1, x2), (y1, y2), 1)	
				slope = parameters[0]
            			intercept = parameters[1]
        	
            			if slope < 0:
                			left_fit.append((slope,intercept))
            			else:
                			right_fit.append((slope,intercept))

        		left_fit_average = np.average(left_fit, axis=0)
        		right_fit_average = np.average(right_fit, axis=0)

        		left_line = make_coordinates(img, left_fit_average)
        		right_line = make_coordinates(img, right_fit_average)

        	return np.array([left_line, right_line])

	def make_coordinates(img,coordinate):
   		slope,intercept = coordinate
    		y1 = img.shape[0]
    		y2 = 300
    		x1 = int((y1-intercept)/slope)
    		x2 = int((y2-intercept)/slope)
    		print(x1,y1,x2,y2)
    		return np.array([x1, y1, x2, y2])

        cv_gray = cv2.cvtColor(cv_image_flipped, cv2.COLOR_RGB2GRAY)
        blur = cv2.GaussianBlur(cv_gray, (5, 5), 0)
	right_lane = right_ROI(cv2.Canny(blur,50,150))
       
	left_lane = left_ROI(cv2.Canny(HSV_yellow(cv_image_flipped),50,150))
        
	lanedtc = cv2.bitwise_or(right_lane,left_lane)

	lines = cv2.HoughLinesP(lanedtc, 2, np.pi/180, 100, np.array([]), minLineLength=10, maxLineGap=30)

	averaged_lines = average_slope(cv_image_flipped,lines)
	line_image = display_square(cv_image_flipped,averaged_lines)

	combo_image = cv2.addWeighted(cv_image_flipped, 0.6, line_image, 1, 1)
        
	#plt.imshow(right_lane)
        #plt.show()

        cv2.imshow('image', combo_image)
        cv2.waitKey(1)

    def main(self):
        rospy.spin()


if __name__ == '__main__':
    rospy.init_node('gray')
    node = Gray()
    node.main()
