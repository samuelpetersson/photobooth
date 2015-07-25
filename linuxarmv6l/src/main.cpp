#include "ofMain.h"
#include "ofGLProgrammableRenderer.h"
#include "LinuxApp.h"

//========================================================================
int main( ){
	ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
	ofSetupOpenGL(1024, 768, OF_FULLSCREEN);
	ofRunApp(new LinuxApp());
}
