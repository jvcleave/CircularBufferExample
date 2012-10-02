/*
 *  CircularBuffer.cpp
 */

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer()
{
	start = 0;
    end   = 0;
	width = 640;
	height = 480;
}



void CircularBuffer::setup(int size, int width, int height)
{
	// include empty element
    this->size  = size + 1; 
	this->width = width;
	this->height = height;
	for (int i=0; i<this->size; i++) 
	{
		ofImage* image = new ofImage();
		//image->setUseTexture(false);
		image->allocate(width, height, OF_IMAGE_COLOR);
		images.push_back(image);
	}
	loader.startThread(false, true);
	cout << "images.size(): " << images.size() << endl;
}


bool CircularBuffer::isFull()
{
    return (end + 1) % size == start;
}

bool CircularBuffer::isEmpty()
{
    return end == start;
}

// Write an element, overwriting oldest element if buffer is full. 
// App can choose to avoid the overwrite by checking isFull().
void CircularBuffer::write(string path)
{
	//cout << "path: " << path << endl;
	loader.lock();
		//images[end]->setUseTexture(false);
		loader.loadFromDisk(images[end], path);
	loader.unlock();
	//images[end]->loadImage(path);
    end = (end + 1) % size;
    if (end == start)
	{
		
		start = (start + 1) % size; 
	}
	cout << "write: start = " << start << endl;
}

//Read oldest element. App must ensure !isEmpty() first.
ofImage * CircularBuffer::read()
{
	ofImage* tempImage = images[start];
    start = (start + 1) % size;
	return tempImage;

}