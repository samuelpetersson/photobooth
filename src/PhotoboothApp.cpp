#include "PhotoboothApp.h"

void PhotoboothApp::setup(){

	countdown = -1;
	flash = -1;


	ofHideCursor();

	headline.loadFont("headline.ttf", 240);

}

void PhotoboothApp::update(){

	if(flash > 0) {
		if(flash == 1) {
			saveCameraImage(ofToDataPath(ofGetTimestampString() + ".png", true));
		}
		flash -= ofGetLastFrameTime();
	}

	if(countdown > 0) {
		countdown -= ofGetLastFrameTime();
		if(countdown <= 0) {
			countdown = -1;
			flash = 1;
		}
	}
}

void PhotoboothApp::beginCountdown(){
	if(countdown == -1) {
		countdown = 3;
	}
}

void PhotoboothApp::draw(){
    	
    ofSetupGraphicDefaults();

    ofBackground(0, 0, 0);
    
    drawCamera();

    if(countdown >= 0) {
    	drawCountDown();
    }
    if(flash >= 0) {
    	drawFlash();
    }

}

void PhotoboothApp::drawCountDown(){
	float centerX = ofGetWindowWidth() / 2;
    float centerY = ofGetWindowHeight() / 2;

	ofPushMatrix();
	ofTranslate(centerX, centerY);    

	int second = (int)ceil(countdown);
	float t = second - countdown;

	string message = ofToString(second, 0);
	float messageScale = 0.5 + t * 1.2;
	float messageAlpha = 255.0 - t * 255.0;

	ofScale(messageScale, messageScale);
	ofSetColor(255, 255, 255, messageAlpha);
	headline.drawString(message, headline.stringWidth(message) * -0.5, headline.stringHeight(message) * 0.5);

	ofPopMatrix();
}

void PhotoboothApp::drawFlash(){

	float t = flash / 1.0;

	ofSetColor(255, 255, 255, 255 * t);
	//ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

}

void PhotoboothApp::keyPressed(int key){
	if(key == ' ') {
		beginCountdown();
	}
}
