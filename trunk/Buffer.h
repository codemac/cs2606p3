#ifndef BUFFER_H
#define BUFFER_H

#include <cstring>

class Buffer {
	private:
		char* buffer;
		int startBlock;
		bool dirty;
		const static int BLOCKSIZE = 512;
	public:
		Buffer() {
			buffer = new char[BLOCKSIZE];
			startBlock = 0;
			dirty = false;
		}

		bool write(char* str, int block);
		char* read(int block, int length);
		bool isDirty();
};
#endif
