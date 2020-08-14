import cv2
import numpy as np
import matplotlib.pyplot as plt

image = cv2.imread('test_image.jpg')                                    # 이미지를 들여오고

gray = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
blur = cv2.GaussianBlur(gray, (5, 5), 0)
canny = cv2.Canny(blur, 50, 150)                                        # 여기까지 노이즈제거해주고

hough_line = cv2.HoughLinesP(canny, 1, np.pi/180, 100)                  # 여기부터 houghline 시작. !!!!!!!!!!! hough_line은 좌표값을 넘겨받음!!!!!!!

for line in hough_line:                                                 # 여기서부터가 중요함.. 넘겨받은 좌표값을 임의의 변수에 저장할것.
    x1, y1, x2, y2 = line[0]                                            # 좌표 = line[0] 해도되고 line.reshape(4) 해도 됨. 이건 넘겨받은 좌표값들 2차원 -> 1차원 배열로 차원 내려주는것
    cv2.line(image, (x1, y1), (x2, y2), (255, 0, 0), 10)                # cv.line은 라인그려주는 함수. x와y좌표 순서대로 주고 색생과 선 굵기 정해줌
    
    # x1 y1 x2 y2 는 for문 안에서만 살아있음!!!!!!!! cv.line 꼭 for문 안에 설정해주기!!!!!!!
    # 전역변수인 img를 받아와서 cv.line을 for문 안에서 처리해줘도 적용 됨.

cv2.imshow("result", image)
cv2.waitKey(0)
# plt.imshow(blur)
# plt.show()
cv2.destroyAllWindows()
