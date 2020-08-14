import cv2
import numpy as np


def ROI(frame):                                             #ROI 설정함수
    background = np.zeros_like(frame)
    height = frame.shape[0]
    triangle_polygon = np.array([
        [(200, height), (1100, height), (550, 250)]
    ])
    cv2.fillPoly(background, triangle_polygon, 255)
    masked_image = cv2.bitwise_and(frame, background)
    return masked_image


cap = cv2.VideoCapture("test2.mp4")
while(cap.isOpened()):
    _, frame = cap.read()
    if frame is None:

        break

    frame = frame.astype('uint8')

    blackimg = np.zeros_like(frame)

    blur = cv2.GaussianBlur(frame, (5, 5), 0)
    hsv = cv2.cvtColor(blur, cv2.COLOR_BGR2HSV)                         # HSV값으로 변환
    low = np.array([10, 100, 50])                                       # 원하는 색의 최대 임계값. 여기서는 주황색
    high = np.array([15, 255, 255])                                     # // 최소임계값
    yellomask = cv2.inRange(hsv, low, high)                             # cv2.inRange를 통해 범위안의 픽셀들 제외하고 0으로 돌림
    edge = cv2.Canny(yellomask, 75, 150)                                # 이 아래로는 그냥 차선인식이랑 동일
    ROI_frame = ROI(edge)
    lines = cv2.HoughLinesP(ROI_frame, 1, np.pi/180, 50, 50)
    for line in lines:
        x1, y1, x2, y2 = line.reshape(4)
        print("되는건가?", x1, y1)
        cv2.line(blackimg, (x1, y1), (x2, y2), (0, 255, 0), 10)         # 차선 평균으로 깔끔하게 내는거 이전까지만 해봤음

    cv2.imshow("result", blackimg)
    cv2.waitKey(1)
