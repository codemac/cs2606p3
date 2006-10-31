#include "MemoryManager.h"

MemoryManager::MemoryManager()
{
    //BufferPool buffer;
}

MemoryManager::~MemoryManager()
{
    
}

Handle MemoryManager::insert(int ID, string name)
{
    int size = name.size();
    char* description = new char[name.size()+1];
    strcpy(description, name.c_str());
    char* final = new char[strlen(description) + sizeof(int) + 1];
    memcpy(final, &size, sizeof(int));
    strcpy(final+sizeof(int), description);
    //search the linked list and add it in.
    
    
}

void MemoryManager::release(Handle handle)
{
    int ID = handle.getID();
    int length = handle.getLength();
    
}