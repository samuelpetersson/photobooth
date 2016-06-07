#!/usr/bin/python

import RPi.GPIO as GPIO
import picamera
import pygame
import time
import framebuffer
from pygame.locals import *
from PIL import Image, ImageDraw, ImageFont

print picamera.__file__

class Photobooth:

	def setup(self):
		GPIO.setmode(GPIO.BCM)
		GPIO.setup(22, GPIO.IN, pull_up_down=GPIO.PUD_UP)

		pygame.init()
		pygame.mouse.set_visible(False)
		self.screen = framebuffer.createScreen()

		self.camera = picamera.PiCamera()
		self.camera.led = False

		self.cameraOverlay = None;

		self.idle()

	def update(self):
		if GPIO.input(22) == False:
			self.countdown()
			self.snap()
			self.idle()

		time.sleep(0.1)

	def idle(self):
		self.screen.fill((255, 255, 255))
		image = pygame.image.load("idle.jpg")
		self.screen.blit(image, (120, 0))
		pygame.display.flip()

	def countdown(self):
		self.camera.hflip = True
		self.camera.start_preview()
		self.updateOverlay("")
		time.sleep(1)
		self.updateOverlay("3")
		time.sleep(1)
		self.updateOverlay("2")
		time.sleep(1)
		self.updateOverlay("1")
		time.sleep(1)
		self.clearOverlay()

	def updateOverlay(self, text):
		canvasW, canvasH = (1440, 256)

		canvas = Image.new("RGB", (canvasW, canvasH))
		draw = ImageDraw.Draw(canvas)
		draw.font = ImageFont.truetype("/usr/share/fonts/truetype/freefont/FreeSansBold.ttf", 250)
		textW, textH = draw.textsize(text)

		draw.text(((canvasW - textW) / 2, 20 + (canvasH - textH) / 2), text, (255, 255, 255))

		if not self.cameraOverlay:
			self.cameraOverlay = self.camera.add_overlay(canvas.tostring(), layer=3, size=canvas.size, alpha=76);
		else:
			self.cameraOverlay.update(canvas.tostring())

	def clearOverlay(self):
		self.camera.remove_overlay(self.cameraOverlay)
		self.cameraOverlay = None

	def snap(self):
		self.screen.fill((255, 255, 255))
		pygame.display.flip()
		self.camera.stop_preview()
		self.camera.hflip = False
		path = "photos/" + time.strftime("%Y%m%d-%H%M%S") + ".jpg"
		self.camera.capture(path, format='jpeg',quality=100)
		image = pygame.image.load(path)
		self.screen.blit(image, (0,0))
		pygame.display.flip()
		time.sleep(4)

	def quit(self):
		GPIO.cleanup()
		pygame.quit()

	def run(self):
		self.setup();
		self.running = True;
		while self.running:
			for event in pygame.event.get():
				if event.type == pygame.KEYDOWN:
					if event.key == K_ESCAPE:
						self.running = False
			self.update();
		self.quit();

if __name__ == "__main__" :
    app = Photobooth()
    app.run()
