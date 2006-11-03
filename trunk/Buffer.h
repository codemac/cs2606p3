#ifndef BUFFER_H
#define BUFFER_H

#include <cstring>
#include <iostream>

using namespace std;

class Buffer {
	private:
		char* buffer;
		int startBlock;
		bool dirty;
		const static int BLOCKSIZE = 512;
	public:
		Buffer() {
			buffer = new char[BLOCKSIZE];
            memset(buffer, ' ', BLOCKSIZE);
			startBlock = 0;
			dirty = false;
		}

		Buffer(int block) {
			buffer = new char[BLOCKSIZE];
			startBlock = block;
			dirty = false;
		}

		int write(char* str, int block, int length);
		char* read(int block, int length);
		const char* read() const;
		bool isDirty();
		int block();
		bool inRange( int block );
};
#endif
