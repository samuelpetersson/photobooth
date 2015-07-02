#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofHideCursor();

	gui.setup(); 
	gui.add(radius.setup("radius", 140, 10, 300));

	OMXCameraSettings videoSettings;
	videoSettings.width = 1280;
	videoSettings.height = 720;
	videoSettings.framerate = 30;
	videoSettings.isUsingTexture = true;
	videoSettings.enablePixels = true;

	videoGrabber.setup(videoSettings);

	videoTexture.allocate(videoSettings.width, videoSettings.height, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update(){
	if(doSaveImage) {
		string path = ofToDataPath(ofGetTimestampString() + ".png", true);
		
		
		ofBuffer buffer((const char*)videoGrabber.getPixels(), 1080 * 720 * 4);
		ofBufferToFile(path, buffer, true);

		//ofImage image;
		//image.setFromPixels(videoGrabber.getPixels(), 1080, 720, OF_IMAGE_COLOR_ALPHA);
		//image.saveImage(path);

		//ofSaveScreen(path);
		doSaveImage = false;
	}	

	videoTexture.loadData(videoGrabber.getPixels(), 1280, 720, GL_RGBA);

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	videoTexture.draw(0, 0, 1280, 720);

	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == ' ') {
		doSaveImage = true;
	}
}
