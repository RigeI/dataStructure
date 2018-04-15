import cv2
import math


def length(point1, point2):
    return math.sqrt((point1[0]-point2[0])**2+(point1[1]-point2[1])**2)


img = cv2.imread('D2.png')

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
gray = cv2.GaussianBlur(gray, (3, 3), 0)
# 霍夫变换圆检测
circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT,
                           3, 50, minRadius=25, maxRadius=30)


points = []
mids = []
# 遍历所有检测出来的圆
for circle in circles[0]:
    x = circle[0]
    y = circle[1]
    r = circle[2]
    for point in points:
        # 找出所有圆心距离小于75(经验值)像素的圆，
        # 其一定为同一个零件里距离最近的两个圆，
        # 记录两个圆心的中点,圆心连线(线可以不连,连上好看)
        if length(point, [x, y]) < 75:
            mids.append([(x+point[0])/2, (y+point[1])/2])
            cv2.line(img, (point[0], point[1]), (x, y), (0, 255, 0), 1)
    # 记录第一次扫描的圆的圆心
    points.append([x, y])
    img = cv2.circle(img, (x, y), r, (0, 0, 255), 2)

# 遍历所有的圆心
# 寻找与刚才记录的中点距离小于75(经验值)的圆心
# 中点到该圆心的向量为方向向量
# 中点到圆心线段的中点恰巧为零件的中点
for point in points:
    for mid in mids:
        if 60 < length(point, mid) < 75:
            center = (int(round((point[0]+mid[0])/2)),
                      int(round((point[1]+mid[1])/2)))
            cv2.circle(img, center, 2, (0, 0, 256), 2)
            print("中心为,{}".format(center))
            print("方向为,({},{})".format(point[0]-mid[0], point[1]-mid[1]))
            cv2.line(img, (int(mid[0]), int(mid[1])),
                     (point[0], point[1]), (0, 255, 0), 1)

cv2.imwrite('Image.png', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
