import RPi.GPIO as GPIO
import time

print "Servo Motor"

GPIO.setmode(GPIO.BCM)
GPIO.setup(13, GPIO.OUT)

p = GPIO.PWM(13, 48.5)
p.start(7)

for i in range(200,0):
        print i
        duty = 1./18. *(i) +2
        p.ChangeDutyCycle(duty)
time.sleep(3)

p.stop()
GPIO.cleanup()

