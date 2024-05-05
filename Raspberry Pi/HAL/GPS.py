"""
==============================================================================
File:            [GPS.py]
Owner:           [Karim Aql & Hassan Bahnasy]
Brief:           [This file contains Send Location from GPS]
==============================================================================
"""

import serial
import pynmea2

def send_location():
    port = "/dev/ttyAMA3"  # Corrected port name

    ser = serial.Serial(port, baudrate=9600, timeout=0.5)

    dataout = pynmea2.NMEAStreamReader()

    newdata = ser.readline().decode('utf-8')  # Decoding the data to string

    if newdata[0:6] == "$GPRMC":
        newmsg = pynmea2.parse(newdata)
        lat = newmsg.latitude
        lng = newmsg.longitude
        gps = "Latitude={} and Longitude={}".format(lat, lng)  # Updated formatting
        print(gps)
        return gps

