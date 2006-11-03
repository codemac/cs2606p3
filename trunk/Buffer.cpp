#include "Buffer.h"


int Buffer::write(char* str, int block, int length) {
	memcpy(buffer+(block - startBlock),str,length);
	dirty = true;
    cout << "BUFFER " << buffer << endl;
	return BLOCKSIZE - block - length;
}

char* Buffer::read(int block, int length) {
	char* whoa = new char[length];
    cout << "BUFFER IT UP" << &(buffer[block-startBlock]) << endl;
	memcpy(whoa, &(buffer[block - startBlock]), length);
	return whoa;
}

char* Buffer::read(void) {
	char whoa = new char[BLOCKSIZE];
	memcpy(whoa, &(buffer), BLOCKSIZE);
	return whoa;
}

const char* Buffer::read() const {
	return buffer;
}

bool Buffer::isDirty() {
	return dirty;
}

int Buffer::block() {
	return startBlock;
}

bool Buffer::inRange( int block ) {
    bool range = ( (block <= startBlock + BLOCKSIZE) || (block >= startBlock));
	return range;
}
