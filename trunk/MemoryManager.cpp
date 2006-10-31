#include "MemoryManager.h"

MemoryManager::MemoryManager()
{
    //BufferPool buffer;
}

MemoryManager::~MemoryManager()
{
    delete handler;
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
    handler[ID] = NULL;
}

char* MemoryManager::get(Handle handle)
{
    int length = handle.length();
    int location = handle.location();
    char* description = new char[length]
    buffer.read(description, location, length);
    return description;
}