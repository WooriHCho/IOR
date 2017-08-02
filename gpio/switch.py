import RPi.GPIO as GPIO
from time import sleep

LED = 23
Button = 18

GPIO.setmode(GPIO.BCM)

GPIO.setup(LED,GPIO.OUT)
GPIO.setup(Button,GPIO.IN)

print 'start the gpio app'

try:
	while True:
		if GPIO.input(Button) == 0:
			GPIO.output(LED, True)
			print " Button was pressed!"
		else:
			GPIO.output(LED, False)
			print "Button was not pressed!"
		sleep(1)
except KeyboardInterrupt:
	GPIO.cleanup()
		
