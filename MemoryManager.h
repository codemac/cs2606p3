#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

#include "Handle.h"
#include <string>
#include <iostream>
#include <sstream>

class MemoryManager
{
    
    public:
    MemoryManager(int ID, string);
    ~MemoryManager();
    Handle insert(void* space, int length);
    void release(Handle handle)'
    int get(void* space, Handle handle);
    
    private:
    int[1000] handler;
};