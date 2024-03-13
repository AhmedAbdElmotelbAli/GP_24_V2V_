import rc_car_move as move
import receive_serial as recv
seconds = 3
while True:
    data = recv.receive_serial_data()
    if data == 'F':
        move.forward(seconds)
    if data == 'B':
        move.backward(seconds) 
    if data == 'R':
        move.right_turn(0.25)  
    if data == 'L':
        move.left_turn(0.25)     
    