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
    videoSettings.framerate = 30;
    videoSettings.isUsingTexture = true;
    videoSettings.enablePixels = true;

    videoGrabber.setup(videoSettings);
    videoGrabber.toggleLED();

    videoTexture.allocate(kVideoWidth, kVideoHeight, GL_RGBA);
}

void LinuxApp::update(){
	PhotoboothApp::update();

    videoTexture.loadData(videoGrabber.getPixels(), kVideoWidth, kVideoHeight, GL_RGBA);

    if(digitalRead(22) == 0) {   
        PhotoboothApp::beginCountdown();
    } 
}

void LinuxApp::drawCamera(){

    videoTexture.draw(310, 200, kVideoWidth, kVideoHeight);
    /*
    float centerX = ofGetWindowWidth() / 2;
    float centerY = ofGetWindowHeight() / 2;
    
    float ratio = ofGetWindowWidth() / kVideoWidth;
        
    ofPushMatrix();
    
    ofTranslate(centerX, centerY);
    ofScale(ratio, ratio);
    
    ofScale(-1.0, 1.0);
    video.draw(kVideoWidth * -0.5, kVideoHeight * -0.5);

    ofPopMatrix();
    */
}


void LinuxApp::saveCameraImage(string path) {
    ofBuffer buffer((const char*)videoGrabber.getPixels(), kVideoWidth * kVideoHeight * 4);
    ofBufferToFile(path, buffer, true);
}
