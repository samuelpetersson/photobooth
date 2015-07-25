#include "ofMain.h"
#include "OSXApp.h"

int main(){
	ofSetupOpenGL(1024, 768, OF_FULLSCREEN);
	ofRunApp(new OSXApp());
}
