/*
 *  CircularBuffer.cpp
 */

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer()
{
	start = 0;
    end   = 0;
	elements = NULL;
}



void CircularBuffer::setup(int size)
{
    this->size  = size + 1; /* include empty elem */
    elements = new Element();
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
void CircularBuffer::write(Element *elem)
{
	elements[end] = *elem;
    end = (end + 1) % size;
    if (end == start)
	{
		start = (start + 1) % size; /* full, overwrite */
	}
}

/* Read oldest element. App must ensure !cbIsEmpty() first. */
void CircularBuffer::read(Element *elem)
{
    *elem = elements[start];
    start = (start + 1) % size;
}