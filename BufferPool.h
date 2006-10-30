#ifndef BUFFERPOOL_H
#define BUFFERPOOL_H

#include <stdio>
#include <string>
#include <fstream>

#define BLOCKSIZE 512

class BufferPool {
	private:
		string file;
		fstream stream;
	public:
		BufferPool();
		BufferPool(string theFile)
			:file (theFile),
			stream(fstream(theFile, ios::binary | ios::out | ios::in))
			{}
		int insert(string str, int id, void* location);
};
#endif
