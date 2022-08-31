import numpy as np
import cv2

        #colors
yellow=np.uint8([[[255,255,0]]])
purple=np.uint8([[[128,0,128]]])
red=np.uint8([[[255,0,0]]])
green=np.uint8([[[0,128,0]]])
orange=np.uint8([[[255,165,0]]])

hsvYellow=cv2.cvtColor(yellow, cv2.COLOR_BGR2HSV)
hsvPurple=cv2.cvtColor(purple, cv2.COLOR_BGR2HSV)
hsvRed=cv2.cvtColor(red, cv2.COLOR_BGR2HSV)
hsvGreen=cv2.cvtColor(green, cv2.COLOR_BGR2HSV)
hsvOrange=cv2.cvtColor(yellow, cv2.COLOR_BGR2HSV)

print(hsvYellow)
print(hsvPurple)
print(hsvRed)
print(hsvGreen)
print(hsvOrange)