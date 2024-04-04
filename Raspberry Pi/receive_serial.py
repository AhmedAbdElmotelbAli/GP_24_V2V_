import serial

# Open serial port
def receive_serial_data(port='/dev/serial0', baudrate=9600, timeout=1):
    try:
        # Open serial port
        ser = serial.Serial(port, baudrate, timeout=timeout)
        print(f"Listening for data on {port} at {baudrate} baud...")

        while True:
            # Read data from serial port
            data = ser.readline().decode('utf-8').strip()
            
            # Check if data is not empty
            if data:
                print("Received:", data)
                return data

    except serial.SerialException as e:
        print("Serial port error:", e)
        return None
    finally:
        if ser.is_open:
            ser.close()