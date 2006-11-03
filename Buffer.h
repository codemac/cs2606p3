#ifndef BUFFER_H
#define BUFFER_H

#include <cstring>
#include <iostream>

using namespace std;

/**
 * Class Buffer
 * 
 * Data structure that contains a single buffer and information about it to
 * serve as a helper class for BufferPool.
 * 
 * @author codemace @ braundui
 * @version 10/02/06
 */

class Buffer {
	private:
        
		char* buffer;
		int startBlock;
		bool dirty;
		const static int BLOCKSIZE = 512;
	public:
    
        /**
         * Default Constructor.  Initializes a buffer char* to be the size of the buffer,
         * sets all of it's values to ' ' or a blank space, and initializes the
         * startBlock int to 0 as well as the dirty flag to false.
         */
		Buffer() {
			buffer = new char[BLOCKSIZE];
            memset(buffer, ' ', BLOCKSIZE);
			startBlock = 0;
			dirty = false;
		}

        /**
         * Constructor, takes in a block value to initialize the startBlock
         * field to it.
         */
		Buffer(int block) {
			buffer = new char[BLOCKSIZE];
            memset(buffer, ' ', BLOCKSIZE);
			startBlock = block;
			dirty = false;
		}
        
        /**
         * this method writes the string at the block position of the given
         * length to the file.
         * @param str the string to write
         * @param block the starting position
         * @param length the length of the string to write
         * @return int the remaning space in the buffer.
         */
		int write(char* str, int block, int length);
        
        /**
         * This method reads from the file starting at the block position
         * and reading for the length
         * @param block the position to start reading
         * @param length the amount of bytes to read.
         * @return char* the string that has been read.
         */
		char* read(int block, int length);
        
        /**
         * reads the whole buffer.
         * @return char* the entire buffer.
         */
		char* read() const;
        
        /**
         * returns true if the buffer has been altered and must be written to
         * the file or false if the buffer is not dirty and doesn't need to be
         * written to the file.
         * @return bool true means it's dirty and false means clean
         */
		bool isDirty();
        
        /**
         * returns the location of the starting block.
         * @return int the starting block
         */
		int block();
        
        /**
         * Checks to see if an integer is in the range of possible file offsets
         * for the buffer.
         * @param block the int to check
         * @param bool returns bool if the buffer is in range, else false.
         */
		bool inRange( int block );
};
#endif
