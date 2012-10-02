#pragma once

#include "ofMain.h"



class CircularBuffer
{
public:
	CircularBuffer();
    int         size;   /* maximum number of images           */
    int         start;  /* index of oldest element              */
    int         end;    /* index at which to write new element  */
	
    vector<ofImage*>images;  /* vector of images                   */
	
	void setup(int size);
	bool isFull();
	bool isEmpty();
	void write(string path);
	ofImage* read();
};