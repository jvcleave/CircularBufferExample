#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	element.value  = 0;
	testBufferSize = 10;
	circularBuffer.setup(testBufferSize);
}

//--------------------------------------------------------------
void testApp::update()
{
	/* Fill buffer with test elements n times */
	
    for (element.value = 0; element.value < (n * testBufferSize); ++element.value)
	{
		circularBuffer.write(&element);
	}
    while (!circularBuffer.isEmpty())
	{
        circularBuffer.read(&element);
        cout << "element.value: " << element.value << endl;
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