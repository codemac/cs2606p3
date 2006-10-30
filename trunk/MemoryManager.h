#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

#include "Handle.h"
#include "BufferPool.h" 
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class MemoryManager
{
    
    public:
    MemoryManager();
    ~MemoryManager();
    Handle insert(int ID, string name);
    void release(Handle handle);
    int get(void* space, Handle handle);
    
    private:
    int handler[1000];
    
};
#endif //MEMORYMANAGER_H_
