"""
==============================================================================
File:            [LED.py]
Owner:           [Hassan Bahnasy]
Brief:           [This file contains function to interface Led with RPI ]
==============================================================================
"""

import RPi.GPIO as GPIO
def led_on(gpio_pin):
    GPIO.output(gpio_pin, GPIO.HIGH)
    
def led_off(gpio_pin):
    GPIO.output(gpio_pin, GPIO.LOW)