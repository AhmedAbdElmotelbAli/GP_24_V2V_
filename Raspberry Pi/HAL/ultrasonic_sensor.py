"""
================================================================================================================================
File:            [ultrasonic_sensor.py]
Owner:           [Hassan Bahnasy]
Brief:           [This file contains the function to read distances in cm using the HC_SR04 ultrasonic sensor]
================================================================================================================================
"""
import time
import RPi.GPIO as GPIO
import os

# Define TRIG and ECHO pins
GPIO.setwarnings(False)
TRIG_PIN = 6
ECHO_PIN = 5
GPIO.setmode(GPIO.BCM)
GPIO.setup(TRIG_PIN, GPIO.OUT)
GPIO.setup(ECHO_PIN, GPIO.IN)


# Define the FIFO path
FIFO_PATH = 'distance_fifo'

def distance():
    # Ensure the trigger pin is low
    GPIO.output(TRIG_PIN, False)
    time.sleep(0.1)

    # Send a 10us pulse to trigger
    GPIO.output(TRIG_PIN, True)
    time.sleep(0.00001)
    GPIO.output(TRIG_PIN, False)

    # Measure the time from sending the pulse to receiving the echo
    start_time = time.time()
    while GPIO.input(ECHO_PIN) == 0:
        start_time = time.time()
    while GPIO.input(ECHO_PIN) == 1:
        end_time = time.time()

    # Calculate distance in centimeters
    pulse_duration = end_time - start_time
    distance_cm = pulse_duration * 17150
    distance_cm = round(distance_cm, 2)

    return distance_cm

while True:
    dist = distance()

    # Write the distance to the FIFO
    try:
        with open(FIFO_PATH, 'w') as fifo:
            fifo.write(str(dist))
            fifo.write('\n')
            print("Distance written to FIFO:", dist)
    except IOError as e:
        print("Error writing to FIFO:", e)

    time.sleep(0.1)
