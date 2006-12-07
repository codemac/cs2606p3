#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

/**
 * Class MemoryManager
 * 
 * Purpose: This class is designed to interact with the Buffer Pool to read
 * and write strings to a file while minimizing the number of disk accesses
 * needed, thus speeding up the program speed.  This class directs the Buffer
 * Pool on where to read in the file as well as where to write to the file.
 * Strings are placed in the file in an empty space determined by the Best Fit
 * Algorithm.  This class also stores and returns Handle objects which can be 
 * used by the client to request the string found with the designated length and
 * location determined by the Handle object.
 * 
 * @author codemac @ braundui
 * @version 11/02/06
 * @edited 12/06/06 braundui @ codemac
 */

#include "BufferPool.h" 
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <list>
#include <iterator>
using namespace std;

class MemoryManager
{
    
    public:
    /**
     * Default constructor.  Initializes the starting file location to zero
     * and sets the values in the Handle array to null.
     */
    MemoryManager();
    
    /**
     * Destructor.  Deletes the array of Handle objects.
     */
    ~MemoryManager();
    
    /**
     * Method to be run as soon as a MemoryManager object is created.  This
     * method is used to pass the File Location to store the strings in, and the
     * number of buffers in the buffer pool on to the buffer pool class.
     * @param fileLocation a char* that contains the name of the file to write
     * the strings to
     * @param numBuffers an int that contains the number of buffers to be held
     * in the buffer pool.
     */
    void init(char* fileLocation, int numBuffers);
    
    /**
     * This method is used to insert the contents of a node from the B+ tree
     * into a block of size 512 at the designated location in the file.
     * @param location the location of the block to write to.
     * @param record the char* that represents the node to be written to file.
     * @return bool whether or not the insert was successful.
     */
    bool insert(int location, char* record);
    
    /**
     * This method returns the 512 byte char* that is found at the location in
     * the file determined by the file offset.
     * @param fileOffset the file offset to use in finding the char*
     * @return char* the contents of the node at that location.
     */
    char* get(int fileOffset);
    
    /**
     * This method returns the first element of the free list used to store
     * empty blocks where a new node can be written to.
     * @return int the file offset where the first block is found.
     */
    int freeList();
    
    /**
     * This method is used to add a file offset to the free list of open blocks.
     * @param fileOffset the offset to be added.
     */
    void addFreeList(int fileOffset);
    
    private:
    
    const static unsigned int BLOCKSIZE = 512;
    BufferPool buffer;
    unsigned int count;
    list<int> fList;
};
#endif //MEMORYMANAGER_H_
