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
 */

#include "Handle.h"
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
     * This method is used to insert the string into the file at the location
     * determined by the best fit algorithm.  This method also creates a handle
     * object and stores that handle into the array in the place designated by 
     * the ID.
     * @param ID the ID used to store the handle in the array
     * @param name the string that is to be put into the file
     * @return Handle* the newly created Handle object containing the location
     * and length of the string in the file.
     */
    Handle* insert(int ID, string name);
    
    /**
     * This method removes the Handle from the Handle array, making it
     * impossible to access the string at the location of that handle, which in
     * turn effectively removes it.
     * @param ID the ID of the handle to remove
     */
    void release(int ID);
    
    /**
     * This method returns the char* that is found with the length and location
     * in the file determined by the Handle.
     * @param handle the handle to use in finding the char*
     * @return char* the string that is found.
     */
    char* get(Handle* handle);
    
    /**
     * This method prints out in order the blocks held in the Free List.
     */
    void dump();
    
    /**
     * This method is used to print the char* found at the location given
     * by the handle found in the array at location ID
     * @param ID the location in the array for the designated handle
     */
    void print(int ID);
    
    private:
    /**
     * This method is used to merge adjacent blocks in the free list to one
     * larger free list block.
     * @param handle the handle to insert into the free list
     */
    void merge(Handle* handle);
    
    /**
     * The size of one block in the buffer pool
     */
    const static unsigned int BLOCKSIZE = 512;
    
    /**
     * The number of ID's allowed and subsequently the size of the handle array.
     */
    const static unsigned int NUMIDS = 1000;
    
    /**
     * This method is recursively called to deal with the writing of a string
     * to the file, including code to deal with the string if it spans the
     * length of two or more block sizes.
     * @param description the char* to be written to file
     * @param location the location to write it to file
     */
    void insertHelper(char* description, unsigned int location);
    
    /**
     * This array is used to hold the handle objects.  Each handle in the array
     * is in the spot designated by it's ID.
     */
    Handle* handler[NUMIDS];
    
    /**
     * The BufferPool object to be used.
     */
    BufferPool buffer;
    
    /**
     * This int is used to store the location of the furthest available location
     * in the file
     */
    unsigned int fileLoc;
    
    /**
     * This linked list is used to hold Handle objects that designate free
     * space in the file.
     */
    list<Handle*> freeList;
};
#endif //MEMORYMANAGER_H_
