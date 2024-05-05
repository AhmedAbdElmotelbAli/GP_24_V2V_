"""
==============================================================================
File:            [main.py]
Owner:           [Karim Aql]
Brief:           [This file contains the main control loop for the rc car]
==============================================================================
"""
import MCAL.PWM as PWM
import MCAL.GPIO_init as gpio_init
import rc_car_control as control
import HAL.motor_control as motors
import sys
import HAL.receive_serial as recv
import MQTT_Publish as MQTT
gpio_init.GPIO_init()
pwmA, pwmB = PWM.pwm_init()

speed = 100

while True:
    data = recv.receive_serial_data()
    speed = control.rc_car_control(data, pwmA, pwmB)
     