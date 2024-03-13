import RPi.GPIO as gpio
import time
def init():    
    gpio.setmode(gpio.BCM)
    gpio.setup(17, gpio.OUT)
    gpio.setup(22, gpio.OUT)
    gpio.setup(23, gpio.OUT)
    gpio.setup(24, gpio.OUT)
def forward(sec):
    init()
    gpio.output(17, True)
    gpio.output(22, False)
    gpio.output(23, True)
    gpio.output(24, False)
    print("Going Forward..")
    time.sleep(sec)
    gpio.cleanup() 
def backward(sec):
    init()
    gpio.output(17, False)
    gpio.output(22, True)
    gpio.output(23, False)
    gpio.output(24, True)
    print("Going Backward..")
    time.sleep(sec)
    gpio.cleanup()
def left_turn(sec):
    init()
    gpio.output(17, False)
    gpio.output(22, True)
    gpio.output(23, True)
    gpio.output(24, False)
    print("Turning Left..")
    time.sleep(sec)
    gpio.cleanup()
def right_turn(sec):
    init()
    gpio.output(17, True)
    gpio.output(22, False)
    gpio.output(23, False)
    gpio.output(24, True)
    print("Turning Right..")
    time.sleep(sec)
    gpio.cleanup()
