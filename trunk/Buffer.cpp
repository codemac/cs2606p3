#include "Buffer.h"


int Buffer::write(char* str, int block) {
	strcpy(buffer+(block - startBlock),str);
	dirty = true;
	return startBlock+block;
}

char* Buffer::read(int block, int length) {
	char* whoa = new char[length];
	memcpy(whoa, buffer+(block - startBlock), length);
	return whoa;
}

bool Buffer::isDirty() {
	return dirty;
}

bool Buffer::inRange( int block ) {
	return ( (block <= startBlock + BLOCKSIZE) || (block >= startBlock));
}
