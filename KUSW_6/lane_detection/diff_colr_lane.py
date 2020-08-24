import cv2
import numpy as np
import matplotlib.pyplot as plt

image = cv2.imread('lane_img.jpg')
lane_img = np.copy(image)

def HSV_yellow(img):
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    low = np.array([20, 100, 100])
    high = np.array([30, 255, 255])
    yellowmask = cv2.inRange(hsv, low, high)
    return yellowmask

def left_ROI(img):
    poly = np.array([
        [(0,260),(0,520),(110,520),(110,260)]
        ])
    BG = np.zeros_like(img)
    cv2.fillPoly(BG,poly,255)
    masked_img = cv2.bitwise_and(img,BG)
    return masked_img

def right_ROI(img):
    poly = np.array([
        [(655,260),(655,490),(745,490),(745,260)]
        ])
    BG = np.zeros_like(img)
    cv2.fillPoly(BG,poly,255)
    masked_img = cv2.bitwise_and(img,BG)
    return masked_img

# img 매개변수 넘겨줄 때 grayscale된 이미지를 넘겨주면 라인 색깔 없어지고 튜플1로 받아들임
#주의!
def display_square(img,lines):
    BG = np.zeros_like(img)
    if lines is not None:
        for line in lines:
            x1,y1,x2,y2 = line.reshape(4)
            cv2.line(BG,(x1,y1),(x2,y2),(0,255,0),5
                     )
    return BG
#########################################################



def average_slope(img,lines):
    left_fit = []
    right_fit = []
    if lines is not None:
        for line in lines:
            x1, y1, x2, y2 = line.reshape(4)
            parameters = np.polyfit((x1, x2), (y1, y2), 1)      # 두점을 지나는 함수의 차수를 매개변수로 정해주면 기울기와 y절편 반환
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
    y2 = int(y1*(1/5))
    x1 = int((y1-intercept)/slope)
    x2 = int((y2-intercept)/slope)
    print(x1,y1,x2,y2)
    return np.array([x1, y1, x2, y2])


    
gray = cv2.cvtColor(lane_img,cv2.COLOR_RGB2GRAY)
blur = cv2.GaussianBlur(gray, (5, 5), 0)

# ROI 과정에서 np.zeroslike 때문에 색이 바뀌니까 ROI 는 맨 마지막에
right_lane = right_ROI(cv2.Canny(blur,50,150))

left_lane = left_ROI(cv2.Canny(HSV_yellow(lane_img),50,150))
###################################################################


# bitwise_or 연산으로 두 이미지 합침
lanedtc = cv2.bitwise_or(right_lane,left_lane)
###############################################


lines = cv2.HoughLinesP(lanedtc, 2, np.pi/180, 100, np.array([]), minLineLength=10, maxLineGap=30)

averaged_lines = average_slope(lane_img,lines)
line_image = display_square(lane_img,averaged_lines)

combo_image = cv2.addWeighted(lane_img, 0.6, line_image, 1, 1)
# 기울기 맞는지 확인용.

cv2.imshow("result",combo_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
#plt.imshow(image)
#plt.show()
