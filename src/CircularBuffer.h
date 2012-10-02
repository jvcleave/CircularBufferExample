#pragma once

#include "ofMain.h"

struct Element
{
	Element()
	{
		value = 0;
	}
	int value;
};

class CircularBuffer
{
public:
	CircularBuffer();
    int         size;   /* maximum number of elements           */
    int         start;  /* index of oldest element              */
    int         end;    /* index at which to write new element  */
	
    Element* elements;  /* vector of elements                   */
	
	void setup(int size);
	bool isFull();
	bool isEmpty();
	void write(Element *elem);
	void read(Element *elem);
};