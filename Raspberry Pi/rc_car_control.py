"""
=======================================================================================
File:            [rc_car_control.py]
Owner:           [Karim Aql & Hassan Bahnasy]
Brief:           [This file contains the code to control the car using bluetooth, ACC]
=======================================================================================
"""

import HAL.motor_control as motors
import RPi.GPIO as GPIO
import data_handler as data_handler
import time
import os

# Define the path to the HAL folder
hal_folder_path = os.path.join(os.path.dirname(__file__), 'HAL')

# Define the path to the distance.txt file inside the HAL folder
distance_file_path = os.path.join(hal_folder_path, 'distance_fifo')
RIGHT_SENSOR_PIN = 16
LEFT_SENSOR_PIN = 26

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
        
def read_char_and_clear_file(filename):
    with open(filename, 'r+') as file:
        # Read a single character from the file
        char = file.read(1)
        if char:
            file.truncate(0)
            return char

            
def read_distance_from_file(filename):
    try:
        with open(filename, 'r') as file:
            distance = float(file.readline().strip())
            return distance
    except FileNotFoundError:
        print(f"File '{filename}' not found.")
    except ValueError:
        print(f"Invalid data format in '{filename}'. Distance must be a float.")
    return None


last_valid_distance = None  # Initialize last valid distance globally

def read_distance_from_fifo(fifo_path):
    global last_valid_distance  # Access the global variable

    try:
        # Open the FIFO in read mode
        with open(fifo_path, 'r') as fifo:
            # Read the distance data from the FIFO
            distance_str = fifo.readline().strip()
            if distance_str:
                # Convert the distance data to float
                last_valid_distance = float(distance_str)
                return last_valid_distance
            else:
                # FIFO is empty, return the last valid distance
                return last_valid_distance
    except FileNotFoundError:
        print(f"FIFO '{fifo_path}' not found.")
    except ValueError:
        print(f"Invalid data format in '{fifo_path}'. Distance must be a float.")
    
    return last_valid_distance


def read_char_and_clear_fifo(fifo_path):
    try:
        # Open the FIFO in read mode and non-blocking mode
        with open(fifo_path, 'r') as fifo:
            # Read a single character from the FIFO
            char = fifo.read(1)
            if char:
                # FIFO has data, clear it by performing a non-blocking read
                os.read(fifo.fileno(), 4096)
                return char
            # else:
                # FIFO is empty
    except FileNotFoundError:
        print("FIFO not found.")
    return None

def slow_down():
    write_speed_to_file("speed.txt", 50)
    
def car_braking(pwmA,pwmB): 
    while (float(read_distance_from_fifo(distance_file_path)) < 20):
        motors.stop(pwmA, pwmB)  
        
def normal():
    write_speed_to_file('speed.txt',100)
    
def fix_right(speed, pwmA, pwmB):
    motors.turn_right(speed, pwmA, pwmB)
    time.sleep(0.5)
    motors.forward(speed, pwmA, pwmB)
    time.sleep(0.5)
    motors.turn_left(speed, pwmA, pwmB)
    time.sleep(0.5)
    print("Turn Right")
    
def fix_left(speed, pwmA, pwmB):
    motors.turn_left(speed, pwmA, pwmB)
    time.sleep(0.5)
    motors.forward(speed, pwmA, pwmB)
    time.sleep(0.5)
    motors.turn_right(speed, pwmA, pwmB)
    time.sleep(0.5)
    print("Turn Left")
    
def rc_car_control (data, pwmA, pwmB):
    speed = read_speed_from_file('speed.txt')
    received_data = data_handler.handle(data)
    # ===============================================================
    # Lane Keeping System
    # LKS.Start_LKS(pwmA,pwmB, right_sensor, left_sensor, speed)
    char = read_char_and_clear_file('lanes.txt')
    if char == 'R':
        fix_right(speed, pwmA, pwmB)
    elif char == 'L':
        fix_left(speed, pwmA, pwmB)
    # =================================================================
    
    # Adaptive Cruise Control (ACC):
    char = read_char_and_clear_fifo('acc_action_fifo')
    if char == 'B':
        car_braking(pwmA, pwmB)
    elif char == 'S':
        slow_down()
    elif char == 'N':
        normal()
  # ======================================================================== 
  # Handle Bluetooth commands 
    if isinstance(received_data, int):
        write_speed_to_file('speed.txt', received_data)
        
    elif received_data == 'F':
        motors.forward(speed, pwmA, pwmB)
        
    elif received_data == 'B':
        motors.backward(speed, pwmA, pwmB)
        
    elif received_data == 'R':
        motors.turn_right(speed, pwmA, pwmB)
        
    elif received_data == 'L':
        motors.turn_left(speed, pwmA, pwmB)
        
    elif received_data == 'S':
        motors.stop(pwmA, pwmB)
        
    elif received_data == 'I':
        car_type = CAR_TYPE_EMERGENCY
        print("Changed To Emergency")
        
    elif received_data == 'G':
        car_type = CAR_TYPE_NORMAL
        print("Changed To Normal")
        
    else:
        pass
    return speed
    