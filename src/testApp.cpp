#include "testApp.h"

int loadCounter = 0;
//--------------------------------------------------------------
void testApp::setup()
{
	ofDirectory dir(ofToDataPath("/Volumes/PHOTOS/BUNBURY/recordings", true));
	dir.listDir();
	files = dir.getFiles();
	image = new ofImage();
	image->allocate(1024, 768, OF_IMAGE_COLOR);
	
	testBufferSize = 100;
	circularBuffer.setup(testBufferSize);
}

//--------------------------------------------------------------
void testApp::update()
{
	if (loadCounter<files.size()-1) 
	{
		loadCounter++;
	}else {
		loadCounter = 0;
	}
	circularBuffer.write(files[loadCounter].path());
	
	cout << "loadCounter---------------------->" << loadCounter << endl;
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void testApp::draw(){
	
	if (!circularBuffer.isEmpty())
	{
		image = circularBuffer.read();
		//image->setUseTexture(true);
		//image->reloadTexture();
		image->draw(0, 0, 1024, 768);
		//image->setUseTexture(false);
		//image->getTextureReference().clear();
		
    }
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}