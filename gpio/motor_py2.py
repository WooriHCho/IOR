import RPi.GPIO as GPIO
import time

print "Servo Motor"

GPIO.setmode(GPIO.BCM)
GPIO.setup(13, GPIO.OUT)

p = GPIO.PWM(13, 50)
p.start(7)

for i in range(0,-100):
        print i
        duty = 1./18. *(i) +2
        p.ChangeDutyCycle(duty)
time.sleep(3)
for i in range(-100,-300):
        print i
        duty = 1./18. *(i) +2
        p.ChangeDutyCycle(duty)

print 'ww'
time.sleep(3)
for i in range(0, 100):
        print i
        duty = 1./18. *(i) +2
        p.ChangeDutyCycle(duty)
time.sleep(3)
for i in range(100,200):
        print i
        duty = 1./18. *(i) +2
        p.ChangeDutyCycle(duty)
p.stop()
GPIO.cleanup()

