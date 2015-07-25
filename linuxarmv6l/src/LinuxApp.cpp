#include "LinuxApp.h"

#define kVideoWidth 1280.0
#define kVideoHeight 800.0

void LinuxApp::setup(){
	PhotoboothApp::setup();

    wiringPiSetupGpio();
    pinMode(22, INPUT);
    pullUpDnControl(22, PUD_UP);


    OMXCameraSettings videoSettings;
    videoSettings.width = kVideoWidth;
    videoSettings.height = kVideoHeight;
    videoSettings.isUsingTexture = true;
    videoSettings.enablePixels = true;

    videoGrabber.setup(videoSettings);
    videoGrabber.toggleLED();
}

void LinuxApp::update(){
	PhotoboothApp::update();

    if(digitalRead(22) == 0) {   
        PhotoboothApp::beginCountdown();
    } 
}

void LinuxApp::drawCamera(){

    float centerX = ofGetWindowWidth() / 2;
    float centerY = ofGetWindowHeight() / 2;

    ofPushMatrix();

    ofTranslate(centerX + kVideoWidth * 0.5, centerY - kVideoHeight * 0.5);

    ofScale(-1.0, 1.0);

    videoGrabber.draw();
    ofPopMatrix();
}


void LinuxApp::saveCameraImage(string path) {
    ofBuffer buffer((const char*)videoGrabber.getPixels(), kVideoWidth * kVideoHeight * 4);
    ofBufferToFile(path, buffer, true);
}
