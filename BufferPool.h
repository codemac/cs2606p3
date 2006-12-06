#ifndef BUFFERPOOL_H
#define BUFFERPOOL_H

#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
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
		
        /**
         * Loops through the array of buffers, pushing them down 1.  The buffer
         * that falls out from this is written to the file, deleted, and then a
         * new one is put into the array.
         * @param offset, the offset you need.
         * @param length the length you need.
         */
		void rotateCleanNew(int offset, int length);

	public:
    
        /**
         * Default constructor.  Sets the total, current and memory fields to
         * zero.
         */
		BufferPool() {
			total = 0;
			current = 0;
			memory = 0;
		}
        
        /**
         * Constructor.  Takes the filename and number of buffers in the buffer
         * pool as paramaters.
         * @param theFile the file to write to
         * @param numBuffs the number of buffers in the buffer pool.
         */
		BufferPool(char* theFile, int numBuffs) {
			stream.open(theFile, ios::binary | ios::out | ios::in);
			filename = theFile;
			memory = new Buffer*[numBuffs];
			total = numBuffs;
			current = 0;
		}
        
        /**
         * Deconstructor.
         */
		~BufferPool() {
		}
        
        /**
         * This method should be called first when a BufferPool object is
         * created.  This method takes the filename and number of buffers as
         * parameters.
         * @param theFile the file you will write to
         * @param numBuffs the number of buffers in the pool.
         */
		void init(char* theFile, int numBuffs);
        
        /**
         * This method writes the given character to the file at the given
         * offset and for the designated length.
         * @param towrite the string to write to file
         * @param fileOffset the location to write to
         * @param length the length of the string you are writing
         * @return int the amount of remaining space in the buffer.
         */
		int write(char* towrite, int fileOffset, int length);
        
        /**
         * This method reads from the file starting at the given offset and 
         * reading for the given length.  The string read is put into the
         * tostore parameter.
         * @param tostore the string that will hold the string read
         * @param fileOffset the location to start reading from
         * @param length how many characters to read in
         * @return bool true if successful, else false.
         */
		char* read(int fileOffset, int length);
};
#endif
