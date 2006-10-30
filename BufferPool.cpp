#include "BufferPool.h"

BufferPool::insert(string str, void* location) {
	
}

BufferPool::getNextBuffer(void) {
	return memory[(count++)%total];
}


