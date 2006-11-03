#include "Buffer.h"


int Buffer::write(char* str, int block, int length) {
	memcpy(&buffer[block-startBlock],str,length);
	dirty = true;
	return BLOCKSIZE - block - length;
}

char* Buffer::read(int block, int length) {
	char* whoa = new char[length];
	memcpy(whoa, &(buffer[block-startBlock]), length);
	return whoa;
}

char* Buffer::read() const {
	return buffer;
}

bool Buffer::isDirty() {
	return dirty;
}

int Buffer::block() {
	return startBlock;
}

bool Buffer::inRange( int block ) {
    return ( (block <= startBlock + BLOCKSIZE) || (block >= startBlock));
}
