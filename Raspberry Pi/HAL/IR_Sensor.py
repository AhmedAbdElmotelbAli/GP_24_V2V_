"""
==============================================================================
File:            [IR_Sensor.py]
Owner:           [Karim Aql & Hassan Bahnasy]
Brief:           [This file contains Function to get reads from IR Sensors ]
==============================================================================
"""
import RPi.GPIO as GPIO
RIGHT_SENSOR_PIN = 16
LEFT_SENSOR_PIN = 26
GPIO.setmode(GPIO.BCM)
GPIO.setup(LEFT_SENSOR_PIN,GPIO.IN)
GPIO.setup(RIGHT_SENSOR_PIN,GPIO.IN)
def read_right_sensor():
    return GPIO.input(RIGHT_SENSOR_PIN)
def read_left_sensor():
    return GPIO.input(LEFT_SENSOR_PIN)