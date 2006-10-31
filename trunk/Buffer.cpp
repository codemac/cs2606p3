#include "Buffer.h"


bool Buffer::write(char* str, int block) {
	if ((block > startBlock + BLOCKSIZE) || (block < startBlock))
		return false;
	else {
		strcpy(buffer+(block - startBlock),str);
		dirty = true;
		return true;
	}
}

char* Buffer::read(int block, int length) {
	char* whoa = new char[length];
	memcpy(whoa, buffer+(block - startBlock), length);
	return whoa;
}

bool Buffer::isDirty() {
	return dirty;
}
