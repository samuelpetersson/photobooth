#pragma once

#include "ofMain.h"

class PhotoboothApp : public ofBaseApp {

	public:
		void setup();
		
		void update();
		void beginCountdown();
		virtual void saveCameraImage(string path) = 0;

		void draw();
		virtual void drawCamera() = 0;
		void drawCountDown();
		void drawFlash();

		void keyPressed(int key);

		float countdown;
		float flash;

		ofTrueTypeFont headline;
};
