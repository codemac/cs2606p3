#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

#include "Handle.h"
#include "BufferPool.h" 
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <list>
using namespace std;

class MemoryManager
{
    
    public:
    MemoryManager();
    ~MemoryManager();
    Handle insert(int ID, string name);
    void release(Handle handle);
    char* get(Handle handle);
    
    private:
    Handle* handler[1000];
    
};
#endif //MEMORYMANAGER_H_
