#include "Buffer.h"


int Buffer::write(char* str, int block) {
    cout << "A" << endl;
	strcpy(buffer+(block - startBlock),str);
    cout << "B" << endl;
	dirty = true;
    cout << "C" << endl;
	return BLOCKSIZE - block - strlen(str);
}

char* Buffer::read(int block, int length) {
	char* whoa = new char[length];
	memcpy(whoa, buffer+(block - startBlock), length);
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
