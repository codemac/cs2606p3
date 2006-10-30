#ifndef BUFFERPOOL_H
#define BUFFERPOOL_H

#include <cstdio>
#include <string>
#include <fstream>
#include "Handle.h"

#define BLOCKSIZE 512

using namespace std;

class BufferPool {
	private:
		fstream stream;
		char*** memory;
	public:
		BufferPool();
		BufferPool(string theFile, int numBuffs) {
			stream = fstream(theFile, ios::binary | ios::out | ios::in);
			memory = new char[numBuffs][BLOCKSIZE];
		}

		int insert(string str, void* location);

};
#endif
