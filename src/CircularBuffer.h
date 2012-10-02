#pragma once

#include "ofMain.h"
#include "ofxThreadedImageLoader.h"


class CircularBuffer
{
public:
	CircularBuffer();
    int         size;   /* maximum number of images           */
    int         start;  /* index of oldest element              */
    int         end;    /* index at which to write new element  */
	
    vector<ofImage*>images;  /* vector of images                   */
	int width;
	int height;
	
	void setup(int size, int width, int height);
	bool isFull();
	bool isEmpty();
	void write(string path);
	ofImage* read();
	ofxThreadedImageLoader loader;
};