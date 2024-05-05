"""
==============================================================================
File:            [Lane_Keeping_System.py]
Owner:           [Karim Aql & Hassan Bahnasy]
Brief:           [This file contains code to implement LKS ADAS feature]
==============================================================================
"""
import time
import RPi.GPIO as GPIO
import HAL.motor_control as motors
import HAL.LEDs as leds
import MCAL.PWM as PWM
import HAL.IR_Sensor as IR
import MCAL.GPIO_init as GPIO_init

lane_file = 'lanes.txt'

def write_data_to_file(filename, data):
    with open(filename, 'w') as file:
        file.write(data)
        print(f"Data '{data}' written to {filename}")
        
def Start_LKS(pwmA, pwmB, right_sensor, left_sensor, speed):
    if (left_sensor == GPIO.HIGH) and (right_sensor == GPIO.HIGH):
        leds.led_off(18)
        leds.led_on(21)
        print("BLACK LANE")
    elif ( left_sensor == GPIO.LOW) and (right_sensor == GPIO.LOW):
        leds.led_off(21)
        leds.led_on(18)
        print("WHITE LANE")
    elif (left_sensor == GPIO.LOW) and (right_sensor == GPIO.HIGH):
        write_data_to_file(lane_file,'R')
        print("Turn Right")
    elif (left_sensor == GPIO.HIGH) and (right_sensor == GPIO.LOW):
        write_data_to_file(lane_file,'L')
        print("Turn Left")
        
GPIO_init.GPIO_init()
pwmA = GPIO.PWM(12, 1000)  # PWM frequency set to 1000Hz
pwmB = GPIO.PWM(13, 1000)  # PWM frequency set to 1000Hz
while True:
    right_sensor = IR.read_right_sensor()
    left_sensor = IR.read_left_sensor()
    Start_LKS(pwmA, pwmB, right_sensor, left_sensor, 100)