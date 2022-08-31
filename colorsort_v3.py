import numpy as np
import cv2
import time
import subprocess

steady = "steady.exe"
track1 = "track1.exe"
track2 = "track2.exe"
track3 = "track3.exe"

webcam = cv2.VideoCapture(1)

while(1):

    outYellow = 0
    outPurple = 0
    outGreen = 0
    outRed = 0
    outOrange = 0

    _, imageFrame = webcam.read()
    hsvFrame = cv2.cvtColor(imageFrame, cv2.COLOR_BGR2HSV)

    yellow_lower = np.array([20, 50, 100], np.uint8)
    yellow_upper = np.array([42, 255, 255], np.uint8)
    yellow_mask = cv2.inRange(hsvFrame, yellow_lower, yellow_upper)

    green_lower = np.array([25, 52, 72], np.uint8)
    green_upper = np.array([102, 255, 255], np.uint8)
    green_mask = cv2.inRange(hsvFrame, green_lower, green_upper)

    purple_lower = np.array([160,255,255], np.uint8)
    purple_upper = np.array([140,255,128], np.uint8)
    purple_mask = cv2.inRange(hsvFrame, purple_lower, purple_upper)

    red_lower = np.array([-10, 245, 214], np.uint8)
    red_upper = np.array([10, 265, 294], np.uint8)
    red_mask = cv2.inRange(hsvFrame, red_lower, red_upper)

    orange_lower = np.array([5, 50, 50], np.uint8)
    orange_upper = np.array([15, 255, 255], np.uint8)
    orange_mask = cv2.inRange(hsvFrame, orange_lower, orange_upper)


    cv2.imshow("mask", yellow_mask)
    outYellow = cv2.countNonZero(yellow_mask)
    outPurple = cv2.countNonZero(purple_mask)
    outGreen = cv2.countNonZero(green_mask)
    outRed = cv2.countNonZero(red_mask)
    outOrange = cv2.countNonZero(orange_mask)


    # if outpurple > 10000:
    #     subprocess.run(track1)
    # elif outGreen > 10000:
    #     subprocess.run(track2)
    # elif outYellow > 10000:
    #     subprocess.run(track3)

    print(outPurple)
    time.sleep(1)

