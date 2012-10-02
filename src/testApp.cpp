#include "testApp.h"

int loadCounter = 0;


//--------------------------------------------------------------
void testApp::setup()
{
	ofSetBackgroundAuto(false);
	width = 1280;
	height = 768;
	string workPath = "/Volumes/EXTERNAL_JVC/BUNBURY/FOOTAGE/Bunbury/WebcamTwitchCaptures";
	string homePath = "/Volumes/PHOTOS/BUNBURY/recordings";
	string dirPath = workPath;
	
	ofDirectory dir(ofToDataPath(dirPath, true));
	dir.listDir();
	files = dir.getFiles();
	image = new ofImage();
	image->allocate(width, height, OF_IMAGE_COLOR);
	
	testBufferSize = 120;
	circularBuffer.setup(testBufferSize, width, height);
	texture.allocate(width, height, GL_RGB);
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
	ofSetWindowTitle(ofToString(ofGetFrameRate()) + " circularBuffer.isFull(): " + ofToString(circularBuffer.isFull()));
}

//--------------------------------------------------------------
void testApp::draw(){
	
	if (!circularBuffer.isEmpty())
	{
		circularBuffer.loader.lock();
		image = circularBuffer.read();
		
		//image->setUseTexture(true);
		//image->reloadTexture();
		texture.loadData(image->getPixelsRef());
		texture.draw(ofRandom(-ofGetWidth(), ofGetWidth()), 0, width, height);
		//image->setUseTexture(false);
		//image->getTextureReference().clear();
		circularBuffer.loader.unlock();
		
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