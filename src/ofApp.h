#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofAppEGLWindow.h"
#include "ofxRPiCameraVideoGrabber.h"
#include "wiringPi.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

	 	ofxPanel gui;
		ofxFloatSlider radius;

		ofxRPiCameraVideoGrabber videoGrabber;
		ofTexture videoTexture;
		bool doSaveImage;
};
