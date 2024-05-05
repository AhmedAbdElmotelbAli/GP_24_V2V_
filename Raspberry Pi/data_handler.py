"""
==============================================================================
File:            [data_handler.py]
Owner:           [Karim Aql]
Brief:           [This file contains code to handle data received by bluetooth]
==============================================================================
"""
def handle(data):
    if data.isdigit():
        received_speed = int(data) * 10 + 10
        if 10 <= received_speed < 90:
            return received_speed
        elif data == 'q':
            return 100
        else:
            print("Invalid speed:", received_speed)
            pass
    else:
        return data