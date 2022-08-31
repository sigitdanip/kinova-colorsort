import serial
import subprocess
import time

while True:
    pixy = serial.Serial("COM5", 115200, timeout=.1)
    if pixy.isOpen():
        line = pixy.readline()
        string = line.decode("uint8")
        print(string)
    else:
        pixy.isOpen()
