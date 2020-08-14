import cv2
import numpy as np
import matplotlib.pyplot as plt


# grayscaling blur edge_detect 까지 끝난걸 canny 함수로 깔끔하게 묶어줌
def canny(lane_image):
    # cv2의 convert color를 이용해 grayscaling.
    gray = cv2.cvtColor(lane_image, cv2.COLOR_RGB2GRAY)

    # cv2.GaussianBlur(파일이름, (행렬크기), 편차설정)
    # (5,5)행렬 사이즈로 가우시안블러. (3,3) or (5,5) 대중적.
    blur = cv2.GaussianBlur(gray, (5, 5), 0)

    # cv2.Canny(파일이름, low_threshold, high_threshold)
    # 인접픽셀값의 차이의 기울기(gradient == 변화량)를 사용.
    # 인접한 픽셀값의 차의 기울기가 high_threshold보다 높으면 edge. 낮으면 edge가 아니라 판단
    # 최대최소 임계값은 1:2 1:3 비율이 권장됨
    canny = cv2.Canny(blur, 50, 150)

    return canny


# plt.imshow(이미지)를 통해 ROI를 설정할 좌표값을 확인한 후 그 좌표대로 폴리곤 생성
# zeros_like를 통해 검정바탕 생성 후, cv2.fillPoly를 통해 바탕에 폴리곤을 흰색으로 덧대어 마스크 생성
# 검정은 픽셀값이0, 흰색은 255 를 이용하여, 마스크와 원본이미지와의 bitwise_and(논리곱연산)을 통해 원본이미지에서 검정은 죽이고 폴리곤만큼의 영역은 살림. ROI설정 완료
def region_of_interest(image):
    # height 는 이미지 전체의 높이를 나타내는 변수로 설정할것.
    # 이미지.shape() 하게되면 (높이,너비,채널) 을 반환. 이미지가 grayscailed 라면 채널은 공란.
    # 이미지.shape[0] 은 튜플의 첫번째 인덱스인 '높이'를 반환! 이미지.shape[1] 은 너비를 반환할것.
    height = image.shape[0]

    # cpu의 부담을 덜어주기 위해 확인해야만 하는 구역을 설정해줌. 이는 이번 예제에서는 삼각형
    # 순서대로, 1,2번째는 밑변의 양 꼭지점. 마지막 3번째는 삼각형의 높이에 있는 꼭지점
    # 각각의 좌표는 ##plt.imshow(이미지)## 에서 확인할 수 있음
    # !!! 기존의 [(x1,y1),(x2,y2),(x3,y3)] 는 3개의 좌표가 별개로 있는 상태
    # 예시를 들기 위해 (x1,y1) 튜플을 c1이라하자. 그럼 [c1,c2,c3] 이런 별개의 배열이 된다.
    # c들이 하나의 좌표로써 움직여 배열에 담기기 위해서는 [[c1,c2,c3]] 이렇게 해주어야 한다!
    triangle_polygon = np.array([
        [(200, height), (1100, height), (550, 250)]
    ])

    # zeros 에서 유추할 수 있듯이, 지정한 이미지의 사이즈대로 안의 픽셀값을 전부 0 == 검정 으로 바꿔줌
    background = np.zeros_like(image)

    # cv2.fillPoly(이미지1, 집어넣을이미지, 집어넣을 이미지를 채울 픽셀값. 255==흰색)
    # 이 함수가 끝나면 이미지1이 이미지1에 집어넣은 이미지가 색상대로 덧대어진 형태로 저장됨
    cv2.fillPoly(background, triangle_polygon, 255)

    # cv2.bitwise_and(이미지1, 이미지2) 이미지1,2 순서는 상관없다
    # 이미지1과 이미지2의 각각의 픽셀들을 논리곱(&&)하는것
    # bitwise = 비트연산, bitwise_or 도 가능하지않을까?
    # 현재 마스크는 검정바탕에 흰색폴리곤이 덧대어진 모양. 검정은 픽셀값이0이므로 논리곱 하면 검정부분은 다 지워지는걸 이용해서 마스킹
    masked_image = cv2.bitwise_and(image, background)
    return masked_image


# def display_lines(image, lines):
#    line_image = np.zeros_like(image)
#    if lines is not None:
#        for line in lines:
#            print(line)
# 위에처럼 해주고 실행해보면 4열짜리 2차원배열이 13행으로 출력된다. [[704 418 927 641]] 이렇게
# 위 좌표들은 우리가 허프만 변환을 통해 얻은 직선들의 [x1,y1,x2,y2] 좌표값들이다.
# 이를 활용하기 위해 reshape(4) 를 통해 1차원 4열짜리 행렬들의 집합으로 바꿔보자.
# reshape(행,렬) 이렇게 해주면 특정 행렬 조건에 맞게 바꿔줌. -1넣으면 나머지 칸에 들어온 숫자에 따라 맞춰짐


def display_lines(image, lines):
    line_image = np.zeros_like(image)
    if lines is not None:
        # average 낼 떄 shape(4) 해주므로, for x1,y1,x2,y2 in Lines: 해줘도 됨
        for line in lines:
            # 1차원으로 풀어준 좌표값들 각각 저장해줌
            x1, y1, x2, y2 = line.reshape(4)
            #cv2.line(이미지, 좌표1, 좌표2, 색, 굵기)
            # 이미지에다가 좌표1과 좌표2를 통해 직선을 만들고 색과 굵기에 맞춰 이미지에 표시해주고
            # 그린 선을 이미지 위에 덧대어서 저장함. 함수 실행되면 이미지는 선이 그려져 있음.
            cv2.line(line_image, (x1, y1), (x2, y2), (255, 0, 0), 10)
    # 이 때 검정 캔버스 위에 그려진 line은 되게 너저분함. 그럴만도한게 선들이 13개가 있으니까...
    return line_image

# 허프만 변환을 통해 얻은 좌표를 파란선으로 이미지에 그려보았음. 이제 이 지저분한 선을 깔끔하게 하나로 합칠것


def average_slope_intercept(image, lines):
    # 현재 좌측차선, 우측차선 이렇게 2개있음. left와 right 은 각각의 차선
    left_fit = []
    right_fit = []
    for line in lines:
        x1, y1, x2, y2 = line.reshape(4)
        #polyfit(x좌표, y좌표, 차수)
        # x와 y좌표를 지나는 최소제곱의 함수를 찾을것...
        # 이 때 차수는 몇차수인지. 우리는 직선이니까 1차함수 1차수 1
        # polyfit은 기울기와 y절편을 배열형태로 반환 [기울기,y절편]
        parameters = np.polyfit((x1, x2), (y1, y2), 1)
        slope = parameters[0]
        intercept = parameters[1]
        # !!!!!!!plt.show 해서 보면 알겠지만 이미지의 y축이 뒤집어져있음.!!!!!!!!!!!
        # 고로 왼쪽의 차선의 기울기가 통상적으로는 양수겠지만, y축이 뒤집어졌으므로
        # 왼쪽차선의 기울기는 음수고, 오른쪽 차선의 기울기는 양수임. 이걸 이용해서 코드를 짜보자.
        # 이 if문 지나고 left와 right_fit print 해보면 왼쪽에있는거 오른쪽에 있는거 따로 직선들의 좌표값이 정렬되어있음.
        if slope < 0:
            left_fit.append((slope, intercept))
        else:
            right_fit.append((slope, intercept))

    #np.average(평균낼object, axis)
    # axis는 average 함수의 진행방향이다. 0이면 수직, 1이면 수평, 2면 3차원으로 넘어감.
    # 우리는 (x,y) 이므로 0을 넣어줘서 각각의 튜플들을 평균내게 해주자. 즉 수직으로 평균을 내어야 한다
    # 각각의 차선들을 평균내서 이쁜 하나의 라인으로 만들어보자.
    left_fit_average = np.average(left_fit, axis=0)
    right_fit_average = np.average(right_fit, axis=0)

    # 선을 길게 빼줌
    left_line = make_coordinates(image, left_fit_average)
    right_line = make_coordinates(image, right_fit_average)

    # print(left_fit_average, 'left') 해주면 출력될 때 옆에 left 라고 뜸

    return np.array([left_line, right_line])

#  직선의 시작점을 잡아서 길게 빼주는 함수


def make_coordinates(image, line_parameters):
    # line_parameter배열 인덱스0,1 값이 차례대로 slope intercept에 저장
    slope, intercept = line_parameters
    # print(image,shape)
    # image.shape 하면 (높이,너비,채널 값)  반환.
    # 차선이 밑에서 부터 시작해야 하는데 이 때 사진이 뒤집어져있으므로 사진상으로는 밑이지만, 좌표상으로는 y의 최대값인 걸 찾기 위해 image.shape 함
    y1 = image.shape[0]  # 순서대로 높이 너비 채널값. 그냥 숫자로 써도 댐
    y2 = int(y1*(3/5))  # 더 길게 빼고싶으면 4/5 해도 댐. 니맘대로
    # y = m*x + b 이므로  x = (y-b)/m
    x1 = int((y1-intercept)/slope)
    x2 = int((y2-intercept)/slope)
    return np.array([x1, y1, x2, y2])


image = cv2.imread('test_image.jpg')  # 이미지 들여오기
lane_image = np.copy(image)  # 들여온 이미지를 직접 지정해주지 않고 복사해서 사용

edge_detected_image = canny(lane_image)
cropped_image = region_of_interest(edge_detected_image)

#cv2.HoughLinesP(image, rho, theta, threshold, minLineLength, maxLineGap)
# rho는 픽셀을 몇개의 단위로 묶어서 볼것인지 정해주는것입니다. 1은 말 그대로 한개한개의 픽셀= 픽셀 전부를 다 따져보는것이고
# rho가 2라면 2x2사이즈의 픽셀을 하나의 픽셀로 본다는 것 입니다. 낮을수록 정밀하지만 걸리는 시간은 제곱만큼 늘어납니다
# theta 는 세타. 허프스페이스에서 각도를 몇도씩 돌려가면서 선을 그을껀지 결정. 작을수록 촘촘한 각도로 돌려보므로 정확성 up
# threshold는 임계값. 허프 스페이스에서 정해준 1픽셀에서 몇개의 접점이 있어야 신뢰도가 있다고 판단할껀지 정해줌
# minLineLength은 선이 몇 픽셀길이여야지 이걸 나뭇가지같은 방해물이 아닌 차선으로 인식할껀지 최소의 길이를 정해주는것
# maxLineGap은 라인이 중간에 끊겨도 이정도 픽셀길이는 영상처리 오류값이라 하고 라인으로 이어줄껀지 최대값을 정해주는것
# 리턴값은 직선의 좌표들.
lines = cv2.HoughLinesP(cropped_image, 2, np.pi/180, 100,
                        np.array([]), minLineLength=40, maxLineGap=5)

averaged_lines = average_slope_intercept(lane_image, lines)

line_image = display_lines(lane_image, averaged_lines)

# cv2.addweight(이미지1, 이미지1의 투명도, 이미지2, 이미지2의 투명도, 감마)
# 이미지 1,2 를 합치는데, 이 때 각각의 이미지의 채도를 조절해서 더 선명하게 보여주고 싶은 이미지 강조 가능
# 감마값은 픽셀 덧셈에 추가하는 값이라는데 일단 1
combo_image = cv2.addWeighted(lane_image, 0.8, line_image, 1, 1)

cv2.imshow("result", combo_image)  # 왼쪽의 'result'는 열리는 창 이름
cv2.waitKey(0)  # 밀리세컨드 단위로 처리를 실행
cv2.destroyAllWindows()  # 실행창 종료하고나면 터미널 복구 안되는거 해결해줌
