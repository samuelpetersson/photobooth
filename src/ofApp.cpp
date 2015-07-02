#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

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


	videoTexture.draw(0, 0, 1920, 1200);

	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == ' ') {
		doSaveImage = true;
	}
}
