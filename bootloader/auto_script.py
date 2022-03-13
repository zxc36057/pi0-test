#!/usr/bin/python3
import serial
import sys
import time


ser = serial.Serial("/dev/ttyUSB0",115200)
k = b""
with open(sys.argv[1], "rb") as f:
    byte = f.read(1)
    k += byte
    while byte != b"":
        byte = f.read(1)
        k += byte

ser.write(len(k).to_bytes(4, 'little')+k)
#print(ser.read(19))
ser.close()