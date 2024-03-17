import RPi.GPIO as GPIO
import time

def init():
    # Set GPIO mode
    GPIO.setmode(GPIO.BCM)
    # Setup GPIO pins
    GPIO.setup(12, GPIO.OUT)
    GPIO.setup(17, GPIO.OUT)
    GPIO.setup(22, GPIO.OUT)
    GPIO.setup(13, GPIO.OUT)
    GPIO.setup(23, GPIO.OUT)
    GPIO.setup(24, GPIO.OUT)
    # Setup PWM pins
    pwmA = GPIO.PWM(12, 1000)  # PWM frequency set to 1000Hz
    pwmB = GPIO.PWM(13, 1000)
    # Start PWM with 0% duty cycle
    pwmA.start(0)
    pwmB.start(0)

    return pwmA, pwmB

def set_speed(pwmA, pwmB, speedA, speedB):
    pwmA.ChangeDutyCycle(speedA)  # Change speed of motor A
    pwmB.ChangeDutyCycle(speedB)  # Change speed of motor B
    print(f"Speed is set to {speedA} %")

def forward(seconds, speed):
    pwmA, pwmB = init()

    GPIO.output(17, True)
    GPIO.output(22, False)
    GPIO.output(23, True)
    GPIO.output(24, False)
    set_speed(pwmA, pwmB, speed, speed)
    print ("Going forward...")
    time.sleep(seconds)
    set_speed(pwmA, pwmB, 0, 0)
    GPIO.cleanup()

def backward(seconds, speed):
    pwmA, pwmB = init()
    GPIO.output(17, False)
    GPIO.output(22, True)
    GPIO.output(23, False)
    GPIO.output(24, True)
    set_speed(pwmA, pwmB, speed, speed)
    print ("Going backward...")
    time.sleep(seconds)
    set_speed(pwmA, pwmB, 0, 0)
    GPIO.cleanup()

def turn_right(seconds, speed):
    pwmA, pwmB = init()
    GPIO.output(17, True)
    GPIO.output(22, False)
    GPIO.output(23, False)
    GPIO.output(24, True)
    set_speed(pwmA, pwmB, speed, speed)
    print ("Turning right...")
    time.sleep(seconds)
    set_speed(pwmA, pwmB, 0, 0)
    GPIO.cleanup()

def turn_left(seconds, speed):
    pwmA, pwmB = init()
    GPIO.output(17, False)
    GPIO.output(22, True)
    GPIO.output(23, True)
    GPIO.output(24, False)
    set_speed(pwmA, pwmB, speed, speed)
    print ("Turning left...")
    time.sleep(seconds)
    set_speed(pwmA, pwmB, 0, 0)
    GPIO.cleanup()