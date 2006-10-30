#include "BufferPool.h"

BufferPool::insert(string str, void* location) {
	
}

BufferPool::getNextBuffer(void) {
	if ( count == total ) {
		count = 0;
		//	reset count
		//	write top buffer to disk
		//	reuse old memory
	}
	return memory[(count++)%total];
}


