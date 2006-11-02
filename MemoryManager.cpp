#include "MemoryManager.h"

MemoryManager::MemoryManager()
{
    fileLoc = 0;
}

void MemoryManager::init(char* fileLocation, int numBuffers)
{
    //buffer.init(fileLocation, numBuffers);
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
    
    int location = insertHelper(final);
}

void MemoryManager::release(int ID)
{
    Handle* handle = handler[ID];
    freeList.push_back(handle);
    handler[ID] = NULL;
}

char* MemoryManager::get(Handle handle)
{
    int length = handle.getLength();
    int location = handle.getLocation();
    char* description = new char[length];
    buffer.read(description, location, length);
    return description;
}

int MemoryManager::insertHelper(char* description)
{
    list::iterator iter = freeList.begin();
    if(iter != NULL)
    {
        if (*iter.getLength() > strlen{description))
        {
            Handle bestFit = *iter;
        }
    }
}
