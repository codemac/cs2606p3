#include "BufferPool.h"

int BufferPool::insert(string str, int* location) {
	
}

int* BufferPool::getNextBuffer() {
	if ( count == total ) {
		count = 0;
		//	reset count
		//	write top buffer to disk
		//	reuse old memory
	}
	//	return memory[(count++)%total];
	return 0;
}


