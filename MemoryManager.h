#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

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
    MemoryManager();
    ~MemoryManager();
    void init(char* fileLocation, int numBuffers);
    Handle* insert(int ID, string name);
    void release(int ID);
    char* get(Handle handle);
    void dump();
    void print(int ID);
    
    private:
    const static unsigned int BLOCKSIZE = 512;
    const static unsigned int NUMIDS = 1000;
    void insertHelper(char* description, unsigned int location);
    Handle* handler[NUMIDS];
    BufferPool buffer;
    int fileLoc;
    list<Handle*> freeList;
};
#endif //MEMORYMANAGER_H_
