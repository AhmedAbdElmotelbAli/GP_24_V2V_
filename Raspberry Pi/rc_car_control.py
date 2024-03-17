import rc_car_move as move
import receive_serial as recv


seconds = 2
speed = 100

while True:
    data = recv.receive_serial_data()
    
    if data.isdigit():
        speed = int(data)
        if 1 <= speed <= 100:
            pass
        else:
            print("Invalid speed:", speed)
            continue
        
    if data == 'F':
        move.forward(seconds, speed)
    elif data == 'B':
        move.backward(seconds, speed) 
    elif data == 'R':
        move.turn_right(0.25, speed)  
    elif data == 'L':
        move.turn_left(0.25, speed)