#include "testApp.h"






//--------------------------------------------------------------
void testApp::setup()
{
	elem.value  = 0;
	testBufferSize = 10;
	circularBuffer.setup(testBufferSize);
}

//--------------------------------------------------------------
void testApp::update()
{
	/* Fill buffer with test elements n times */
	int n = ofRandom(5);
	
    for (elem.value = 0; elem.value < (n * testBufferSize); ++ elem.value)
	{
		circularBuffer.write(&elem);
	}
    while (!circularBuffer.isEmpty())
	{
        circularBuffer.read(&elem);
        cout << "elem.value: " << elem.value << endl;
    }  
}

//--------------------------------------------------------------
void testApp::draw(){
	
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