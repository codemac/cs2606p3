#ifndef BUFFERPOOL_H
#define BUFFERPOOL_H

#include <cstdio>
#include <string>
#include <fstream>
#include "Handle.h"
#include "Buffer.h"

using namespace std;

class BufferPool {
	private:
		const static int BLOCKSIZE = 512;
		//fstream stream;
		int current;
		int total;
		Buffer** memory;
		

	public:
		BufferPool() {
			total = 0;
			current = 0;
			//memory = 0;
		}
		BufferPool(string theFile, int numBuffs) {
			//stream = fstream(theFile.c_str(), ios::binary | ios::out | ios::in);
			memory = new Buffer*[numBuffs];
			total = numBuffs;
			current = 0;
		}
		~BufferPool() {
		}

		int write(char* towrite, int fileOffset);
		int read(char* tostore, int fileOffset);
		
};
#endif
