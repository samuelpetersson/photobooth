#pragma once

#include "PhotoboothApp.h"
#include "ofAppEGLWindow.h"
#include "ofxRPiCameraVideoGrabber.h"
#include "wiringPi.h"

class LinuxApp : public PhotoboothApp {

	public:
		void setup();
		void update();
		void drawCamera();
		void saveCameraImage(string path);

		ofxRPiCameraVideoGrabber videoGrabber;
		ofTexture videoTexture;
};
