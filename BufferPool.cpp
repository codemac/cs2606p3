#include "BufferPool.h"


int BufferPool::write(char* towrite, int fileOffset) {
    for( int i = 0; i < total && memory[i] != 0; i++) {
		if (memory[i]->inRange(fileOffset)) {
			int i = memory[i]->write(towrite, fileOffset);
            return i;
		}
	}
	rotateCleanNew(fileOffset);
	int i = memory[0]->write(towrite, fileOffset);
    return i;

}

bool BufferPool::read(char* toread, int fileOffset, int length) {
	for( int i = 0; i < total; i++) {
		if ( memory[i]->inRange(fileOffset)) {
            cout << "OFFSET: " << fileOffset << " LENGTH: " << length << endl;
			memcpy(toread, memory[i]->read(fileOffset, length), length);
			return true;
		}
	}
	
	rotateCleanNew(fileOffset);
	

	memcpy(toread, memory[0]->read(fileOffset, length), length);
	return true;
}

void BufferPool::rotateCleanNew(int offset) {
    if ( total > 0 ) {
		Buffer* lastbuf = memory[0];
		Buffer* nextbuf = 0;
		for( int i = 1; i < total; i++) {
			nextbuf = memory[i];
			memory[i] = lastbuf;
			lastbuf = nextbuf;
		}
		if ( lastbuf != 0) {
		  stream.seekp(lastbuf->block());
		  stream.write(lastbuf->read(), BLOCKSIZE);
		  stream.flush();
		  delete lastbuf;
		}
		int bufferedOffset = (offset / BLOCKSIZE)*BLOCKSIZE;
		
		memory[0] = new Buffer( bufferedOffset );
		struct stat results;
		if (stat(filename.c_str(), &results) == 0) {
			if( bufferedOffset+512 > results.st_size) {
				stream.seekp(results.st_size);
				char* str = new char[BLOCKSIZE];
				memset(str, ' ', BLOCKSIZE);
				stream.write(str, strlen(str));
				stream.flush();
				delete[] str;
			}
		}
		stream.seekg(bufferedOffset);
		
		char* toRead = new char[BLOCKSIZE];
		stream.read(toRead, BLOCKSIZE);

		memory[0]->write(toRead, bufferedOffset);
		delete[] toRead;
	}
}

void BufferPool::init(char* theFile, int numBuffs) {
	stream.open(theFile, ios::binary | ios::out | ios::in);
	filename = theFile;
	memory = new Buffer*[numBuffs];
	total = numBuffs;
	current = 0;
}
