/*
 *  CircularBuffer.cpp
 *  CircularBufferExample
 *
 *  Created by jason van cleave on 10/1/12.
 *  Copyright 2012 jasonvancleave.com. All rights reserved.
 *
 */

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer()
{
	start = 0;
    end   = 0;
	elems = NULL;
}



void CircularBuffer::setup(int size)
{
    this->size  = size + 1; /* include empty elem */
    elems = new ElemType();
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
void CircularBuffer::write(ElemType *elem)
{
	elems[end] = *elem;
    end = (end + 1) % size;
    if (end == start)
	{
		start = (start + 1) % size; /* full, overwrite */
	}
}

/* Read oldest element. App must ensure !cbIsEmpty() first. */
void CircularBuffer::read(ElemType *elem)
{
    *elem = elems[start];
    start = (start + 1) % size;
}