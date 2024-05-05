"""
=====================================================================================
File:            [receive_serial.py]
Owner:           [Karim Aql]
Brief:           [This file receives serial data from the HC-05 bluetooth module
                  on the serial interface of the RPi]
=====================================================================================
"""

import serial

data = ""

# Open serial port
def receive_serial_data(port='/dev/serial0', baudrate=9600, timeout=1):
    global received_data
    try:
        # Open serial port
        ser = serial.Serial(port, baudrate, timeout=timeout)
        print(f"Listening for data on {port} at {baudrate} baud...")

        while True:
            # Read data from serial port one character at a time
            if ser.in_waiting > 0:
                data = ser.read().decode('utf-8')
                print("Received:", data)
                return data
            
    except KeyboardInterrupt:
        pass
    
    except serial.SerialException as e:
        print("Serial port error:", e)
    finally:
        if ser.is_open:
            ser.close()

