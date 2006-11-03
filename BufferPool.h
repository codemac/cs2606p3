#ifndef BUFFERPOOL_H
#define BUFFERPOOL_H

#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include "Handle.h"
#include "Buffer.h"

using namespace std;

class BufferPool {
	private:
		const static int BLOCKSIZE = 512;
		fstream stream;
		string filename;
		int current;
		int total;
		Buffer** memory;
		
		void rotateCleanNew(int offset, int length);

	public:
		BufferPool() {
			total = 0;
			current = 0;
			memory = 0;
		}
		BufferPool(char* theFile, int numBuffs) {
			stream.open(theFile, ios::binary | ios::out | ios::in);
			filename = theFile;
			memory = new Buffer*[numBuffs];
			total = numBuffs;
			current = 0;
		}
		~BufferPool() {
		}
		void init(char* theFile, int numBuffs);
		int write(char* towrite, int fileOffset, int length);
		bool read(char* tostore, int fileOffset, int length);
};
#endif
