#include "OSXApp.h"

// void OSXApp::saveCameraImage(){
	
// }
#define kVideoWidth 1280.0
#define kVideoHeight 720.0

void OSXApp::setup(){
	PhotoboothApp::setup();

    video.setDeviceID(0);
    video.initGrabber(kVideoWidth, kVideoHeight);
    
    ofSetVerticalSync(true);
}

void OSXApp::update(){
    video.update();
    
	PhotoboothApp::update();
}

void OSXApp::drawCamera(){
    float centerX = ofGetWindowWidth() / 2;
    float centerY = ofGetWindowHeight() / 2;
    
    float ratio = ofGetWindowWidth() / kVideoWidth;
        
    ofPushMatrix();
    
    ofTranslate(centerX, centerY);
    ofScale(ratio, ratio);
    
    ofScale(-1.0, 1.0);
    video.draw(kVideoWidth * -0.5, kVideoHeight * -0.5);

    ofPopMatrix();

}


void OSXApp::saveCameraImage(string path) {
	ofSaveImage(video.getPixelsRef(), path);
}
