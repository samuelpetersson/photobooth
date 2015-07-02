#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	wiringPiSetupGpio();
	pinMode(22, INPUT);
	pullUpDnControl(22, PUD_UP);

	ofHideCursor();

	gui.setup(); 
	gui.add(radius.setup("radius", 140, 10, 300));

	OMXCameraSettings videoSettings;
	videoSettings.width = 1280;
	videoSettings.height = 800;
	videoSettings.framerate = 30;
	videoSettings.isUsingTexture = true;
	videoSettings.enablePixels = true;

	videoGrabber.setup(videoSettings);

	videoTexture.allocate(videoSettings.width, videoSettings.height, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update(){

	
	if(digitalRead(22) == 0) {
		doSaveImage = true;
	}

	if(doSaveImage) {
		string path = ofToDataPath(ofGetTimestampString() + ".raw", true);

		ofBuffer buffer((const char*)videoGrabber.getPixels(), 1280 * 800 * 4);
		ofBufferToFile(path, buffer, true);

		doSaveImage = false;
	}

	videoTexture.loadData(videoGrabber.getPixels(), 1280, 800, GL_RGBA);

}

//--------------------------------------------------------------
void ofApp::draw(){

	videoTexture.draw(310, 200, 1280, 800);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == ' ') {
		doSaveImage = true;
	}
}
