#pragma once

#include "PhotoboothApp.h"

class OSXApp : public PhotoboothApp {

	public:
		void setup();
		void update();
		void drawCamera();
		void saveCameraImage(string path);

		ofVideoGrabber video;

};
