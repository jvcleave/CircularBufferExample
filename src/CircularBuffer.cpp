/*
 *  CircularBuffer.cpp
 */

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer()
{
	start = 0;
    end   = 0;
}



void CircularBuffer::setup(int size)
{
    this->size  = size + 1; /* include empty elem */
	for (int i=0; i<this->size; i++) 
	{
		ofImage* image = new ofImage();
		image->allocate(1024, 768, OF_IMAGE_COLOR);
		images.push_back(image);
	}
	cout << "images.size(): " << images.size() << endl;
}


bool CircularBuffer::isFull()
{
    return (end + 1) % size == start;
}

bool CircularBuffer::isEmpty() {
    return end == start;
}

/* Write an element, overwriting oldest element if buffer is full. App can
 choose to avoid the overwrite by checking cbIsFull(). */
void CircularBuffer::write(string path)
{
	//cout << "path: " << path << endl;
	images[end]->loadImage(path);
	images[end]->update();
    end = (end + 1) % size;
    if (end == start)
	{
		start = (start + 1) % size; /* full, overwrite */
	}
	cout << "write: start = " << start << endl;
}

/* Read oldest element. App must ensure !cbIsEmpty() first. */
ofImage * CircularBuffer::read()
{
	ofImage* tempImage = images[start];
	//image->draw(ofRandom(ofGetWidth()), 0);
    start = (start + 1) % size;
	return tempImage;

}