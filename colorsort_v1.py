import cv2
import numpy as np
import subprocess
import time

cam = cv2.VideoCapture(1)

steady = "steady.exe"
track1 = "track1.exe"
track2 = "track2.exe"
track3 = "track3.exe"
trajectory = 0

# subprocess.run(steady)
# time.sleep(5)


looprun = 0
while 1:
    if looprun == 0:

        outRed = 0
        outBlue = 0
        outGreen = 0

        _, imgFrame = cam.read()

        hsvFrame = cv2.cvtColor(imgFrame, cv2.COLOR_BGR2HSV)

        #red color range
        redLower = np.array([136, 87, 111], np.uint8)
        redUpper = np.array([180, 255, 255], np.uint8)
        redMask = cv2.inRange(hsvFrame, redLower, redUpper)

        #green color range
        greenLower = np.array([25, 52, 72], np.uint8)
        greenUpper = np.array([102, 255, 255], np.uint8)
        greenMask = cv2.inRange(hsvFrame, greenLower, greenUpper)

        #blue color range
        blueLower = np.array([94, 80, 2], np.uint8)
        blueUpper = np.array([120, 255, 255], np.uint8)
        blueMask = cv2.inRange(hsvFrame, blueLower, blueUpper)

        morphTrans = np.ones((5, 5), "uint8")

        redMask = cv2.dilate(redMask, morphTrans)
        redResource = cv2.bitwise_and(imgFrame, imgFrame, mask=redMask)

        greenMask = cv2.dilate(greenMask, morphTrans)
        greenResource = cv2.bitwise_and(imgFrame, imgFrame, mask=greenMask)

        blueMask = cv2.dilate(blueMask, morphTrans)
        blueResource = cv2.bitwise_and(imgFrame, imgFrame, mask=blueMask)

        # Creating contour to track red color
        contours, hierarchy = cv2.findContours(redMask,
                                               cv2.RETR_TREE,
                                               cv2.CHAIN_APPROX_SIMPLE)

        for pic, contour in enumerate(contours):
            area = cv2.contourArea(contour)
            if (area > 300):
                x, y, w, h = cv2.boundingRect(contour)
                imageFrame = cv2.rectangle(imgFrame,(x,y),
                                           (x + w, y + h),
                                           (0, 0, 255), 2)

                cv2.putText(imageFrame, "Red Detected",(x,y),
                            cv2.FONT_HERSHEY_SIMPLEX, 1.0,
                            (0, 0, 255))


        # Creating contour to track green color
        contours, hierarchy = cv2.findContours(greenMask,
                                               cv2.RETR_TREE,
                                               cv2.CHAIN_APPROX_SIMPLE)

        for pic, contour in enumerate(contours):
            area = cv2.contourArea(contour)
            if (area > 300):
                x, y, w, h = cv2.boundingRect(contour)
                imageFrame = cv2.rectangle(imgFrame, (x, y),
                                           (x + w, y + h),
                                           (0, 255, 0), 2)

                cv2.putText(imageFrame, "Greed Detected", (x,y),
                            cv2.FONT_HERSHEY_SIMPLEX,
                            1.0, (0, 255, 0))


        #Creating contour to track blue color
        contours, hierarchy = cv2.findContours(blueMask,
                                               cv2.RETR_TREE,
                                               cv2.CHAIN_APPROX_SIMPLE)
        for pic, contour in enumerate(contours):
            area = cv2.contourArea(contour)
            if (area > 300):
                x, y, w, h = cv2.boundingRect(contour)
                imageFrame = cv2.rectangle(imgFrame, (x, y),
                                           (x + w, y + h),
                                           (255, 0, 0), 2)
                cv2.putText(imageFrame, "Blue Detected",(x,y),
                            cv2.FONT_HERSHEY_SIMPLEX,
                            1.0, (255, 0, 0))


        cv2.imshow("Multiple Color Detection in Real-TIme", imgFrame)
        outRed = cv2.countNonZero(redMask)
        outBlue = cv2.countNonZero(blueMask)
        outGreen = cv2.countNonZero(greenMask)

        if outBlue > 5000:
            subprocess.run(track1)
            time.sleep(22)
        elif outGreen > 5000:
            subprocess.run(track2)
            time.sleep(22)
        elif outRed> 5000:
            subprocess.run(track3)
            time.sleep(22)

        looprun=1







