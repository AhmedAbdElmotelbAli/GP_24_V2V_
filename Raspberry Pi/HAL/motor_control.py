"""
==============================================================================
File:            [motor_control.py]
Owner:           [Karim Aql]
Brief:           [This file interfaces the L298N motor driver with RPi ]
==============================================================================
"""
# import HAL.ultrasonic_sensor as ultrasonic
import RPi.GPIO as GPIO
import MCAL.GPIO_init as init
import HAL.LEDs as leds
from global_vars import speed
    

def set_speed(pwmA, pwmB, speedA = 100, speedB = 100):
    pwmA.ChangeDutyCycle(speedA)  # Change speed of motor A
    pwmB.ChangeDutyCycle(speedB)  # Change speed of motor B
    print(f"Speed is set to {speedA}%")

def forward(speed, pwmA, pwmB):
    init.GPIO_init()
    GPIO.output(17, True)
    GPIO.output(22, False)
    GPIO.output(23, True)
    GPIO.output(24, False)
    set_speed(pwmA, pwmB, speed, speed)
    leds.led_off(25)
    leds.led_off(8)
    print("Going forward...")

def backward(speed, pwmA, pwmB):
    init.GPIO_init()
    GPIO.output(17, False)
    GPIO.output(22, True)
    GPIO.output(23, False)
    GPIO.output(24, True)
    set_speed(pwmA, pwmB, speed, speed)
    leds.led_off(25)
    leds.led_off(8)
    print("Going backward...")

def turn_left(speed, pwmA, pwmB):
    init.GPIO_init()
    GPIO.output(17, True)
    GPIO.output(22, False)
    GPIO.output(23, False)
    GPIO.output(24, True)
    set_speed(pwmA, pwmB, speed, speed)
    leds.led_off(25)
    leds.led_off(8)
    print("Turning left...")

def turn_right(speed, pwmA, pwmB):
    init.GPIO_init()
    GPIO.output(17, False)
    GPIO.output(22, True)
    GPIO.output(23, True)
    GPIO.output(24, False)
    set_speed(pwmA, pwmB, speed, speed)
    leds.led_off(25)
    leds.led_off(8)
    print("Turning right...")

def stop(pwmA,pwmB):
    init.GPIO_init()
    set_speed(pwmA, pwmB, 0, 0)
    leds.led_on(25)
    leds.led_on(8)
    
# def ACC(pwmA, pwmB):
#     dist_cm = ultrasonic.distance()
    
#     if dist_cm < 20:
#         while (ultrasonic.distance() < 10):
#             stop(pwmA, pwmB)
            
#     if 20 <= dist_cm <= 50:
#         GPIO.cleanup()
#         init.GPIO_init()
#         set_speed(pwmA, pwmB, 70, 70)
        
#     if dist_cm > 50:
#         print("MAX")
