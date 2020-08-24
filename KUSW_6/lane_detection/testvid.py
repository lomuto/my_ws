import cv2
import numpy as np
import matplotlib.pyplot as plt

def edge_detect(frame):
	gray = cv2.cvtColor(frame,cv2.COLOR_RGB2GRAY)
	blur = cv2.GaussianBlur(gray, (5, 5), 0)
	canny = cv2.Canny(blur, 10, 100)
	
	return canny


cap = cv2.VideoCapture("test2.mp4")
while(cap.isOpened()):
    _, frame = cap.read()
    if frame is None:

        break

    frame = frame.astype('uint8')
    nosie_eliminated_frame = edge_detect(frame)
    cv2.imshow("result",nosie_eliminated_frame)
    cv2.waitKey(1)
