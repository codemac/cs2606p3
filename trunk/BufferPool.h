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
		int current;
		int total;
		//char**[BLOCKSIZE] memory;
		char*** memory;
	public:
		BufferPool() {
			total = 0;
			current = 0;
			memory = 0;
		}
		BufferPool(string theFile, int numBuffs) {
			//stream = fstream(theFile, ios::binary | ios::out | ios::in);
			//memory = new char[numBuffs][BLOCKSIZE];
			total = numBuffs;
			current = 0;
		}
		~BufferPool() {
			
		}

		int insert(string str, int* location);
		
		int* getNextBuffer();


};
#endif
