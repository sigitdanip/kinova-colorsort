import numpy as np
import cv2
import time
import subprocess

steady = "steady.exe"
track1 = "track1.exe"
track2 = "track2.exe"
track3 = "track3.exe"
track4 = "track4.exe"
track5 = "track5.exe"

webcam = cv2.VideoCapture(0)

while(1):

    outYellow = 0
    outBlue = 0
    outGreen = 0
    outRed = 0
    outOrange = 0

    _, imageFrame = webcam.read()
    hsvFrame = cv2.cvtColor(imageFrame, cv2.COLOR_BGR2HSV)

    yellow_lower = np.array([20, 100, 100], np.uint8)
    yellow_upper = np.array([30, 255, 255], np.uint8)
    yellow_mask = cv2.inRange(hsvFrame, yellow_lower, yellow_upper)

    green_lower = np.array([25, 52, 72], np.uint8)
    green_upper = np.array([102, 255, 255], np.uint8)
    green_mask = cv2.inRange(hsvFrame, green_lower, green_upper)

    blue_lower = np.array([110,50,50], np.uint8)
    blue_upper = np.array([130,255,255], np.uint8)
    blue_mask = cv2.inRange(hsvFrame, blue_lower, blue_upper)

    red_lower = np.array([136, 87, 111], np.uint8)
    red_upper = np.array([180, 255, 255], np.uint8)
    red_mask = cv2.inRange(hsvFrame, red_lower, red_upper)

    cv2.imshow("mask", yellow_mask)
    outYellow = cv2.countNonZero(yellow_mask)
    outBlue = cv2.countNonZero(blue_mask)
    outGreen = cv2.countNonZero(green_mask)
    outRed = cv2.countNonZero(red_mask)

    if outBlue > 50000:
        print("blue")
        print(outBlue)
        subprocess.run(track2)
        time.sleep(15)

    elif outGreen > 50000:
        print("green")
        print(outGreen)
        subprocess.run(track3)
        time.sleep(15)

    elif outYellow > 5000:
        print("yellow")
        print(outGreen)
        subprocess.run(track1)
        time.sleep(15)

    elif outRed > 80000:
        print("red")
        print(outRed)
        subprocess.run(track4)
        time.sleep(15)

    #print(outYellow)
    #print(outBlue)
    #print(outGreen)
    #print(outRed)
