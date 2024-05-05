"""
==============================================================================
File:            [Adaptive_Cruise_Control.py]
Owner:           [Karim Aql & Hassan Bahnasy]
Brief:           [This file contains code to implement the ACC ADAS feature]
==============================================================================
"""
import HAL.motor_control as motors
import MQTT_Publish as MQTT
import sys
import time
import RPi.GPIO as GPIO
import MCAL.GPIO_init as gpio_init
import os

# Define the path to the HAL folder
hal_folder_path = os.path.join(os.path.dirname(__file__), 'HAL')

# Define the path to the distance.txt file inside the HAL folder
distance_file_path = os.path.join(hal_folder_path, 'distance.txt')

def write_data_to_file(filename, data):
    with open(filename, 'w') as file:
        file.write(data)
        print(f"Data '{data}' written to {filename}")

def read_speed_from_file(filename):
    try:
        with open(filename, 'r') as file:
            speed = int(file.readline().strip())
            return speed
    except FileNotFoundError:
        print(f"File '{filename}' not found.")
    except ValueError:
        print(f"Invalid data format in '{filename}'. Speed must be an integer.")
    return None

def read_distance_from_file(filename):
    # try:
    with open(filename, 'r') as file:
        distance = float(file.readline().strip())
        return distance
    
def write_speed_to_file(filename, new_speed):
    try:
        # Read the current speed
        current_speed = read_speed_from_file(filename)
        if current_speed is not None:
            # Replace the current speed with the new speed
            with open(filename, 'w') as file:
                file.write(str(new_speed))
                print(f"Speed '{new_speed}' written to {filename}")
    except IOError:
        print(f"Error writing to file '{filename}'.")

def Start_ACC(pwmA, pwmB):
    # Define the path to the distance FIFO inside the HAL folder
    distance_fifo_path = os.path.join(hal_folder_path, 'distance_fifo')

    while True:
        # Read distance from distance FIFO
        try:
            with open(distance_fifo_path, 'r') as distance_fifo:
                dist_cm = float(distance_fifo.readline().strip())
        except FileNotFoundError:
            print("Distance FIFO not found.")
            continue
        except ValueError:
            print("Invalid data format in distance FIFO.")
            continue

        if dist_cm < 20:
            action = 'B'  # Brake
        elif 20 <= dist_cm <= 50:
            action = 'S'  # Slow down
        else:
            action = 'N'  # Normal

        # Define the path to the action FIFO outside the HAL folder
        acc_action_fifo_path = 'acc_action_fifo'

        # Write action to action FIFO
        try:
            with open(acc_action_fifo_path, 'w') as action_fifo:
                action_fifo.write(action)
                print(action)
        except FileNotFoundError:
            print("Action FIFO not found.")
            continue

        time.sleep(0.1)  # Adjust sleep time as needed

    
gpio_init.GPIO_init()
pwmA = GPIO.PWM(12, 1000)
pwmB = GPIO.PWM(13, 1000)    
Start_ACC(pwmA,pwmB)
    