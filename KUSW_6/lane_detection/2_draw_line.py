import cv2
import numpy as np
import matplotlib.pyplot as plt

image = cv2.imread('test_image.jpg')

                                                                    # 일단 여러 함수들을 깔끔하게 묶어줌

def noise_elimination(img):
    gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
    blur = cv2.GaussianBlur(gray, (5, 5), 0)
    canny = cv2.Canny(blur, 50, 150)

    return canny


def hough_transform(img):
    return cv2.HoughLinesP(img, 1, np.pi/180, 100)                  # 허프만 변환을 거친 좌표들


def draw_line(img, xy):                                             # 이 좌표를 토대로 라인을 그림
    for line in xy:
        x1, y1, x2, y2 = line[0]
        cv2.line(img, (x1, y1), (x2, y2), (255, 0, 0), 10)

    return img


noise_eliminated_img = noise_elimination(image)
coordinate = hough_transform(noise_eliminated_img)
lined_img = draw_line(image, coordinate)

cv2.imshow("result", lined_img)
cv2.waitKey(0)
# plt.imshow(blur)
# plt.show()
cv2.destroyAllWindows()
