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
    Handle insert(int ID, string name);
    void release(int ID);
    char* get(Handle handle);
    
    private:
    const static int BLOCKSIZE = 512;
    int insertHelper(char* description);
    Handle* handler[1000];
    BufferPool buffer;
    int fileLoc;
    list<Handle*> freeList;
};
#endif //MEMORYMANAGER_H_
