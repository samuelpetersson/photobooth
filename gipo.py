import RPi.GPIO as GPIO

from time import sleep

GPIO.setmode(GPIO.BCM)

GPIO.setup(22, GPIO.IN, pull_up_down=GPIO.PUD_UP)

try:
	while True:
		if GPIO.input(22) == False:
			print "Tjoho!"
		sleep(0.1)
finally:
	GPIO.cleanup()
