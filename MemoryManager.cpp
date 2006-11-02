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

Handle* MemoryManager::insert(int ID, string name)
{
    int size = name.size();
    char* description = new char[name.size()+1];
    strcpy(description, name.c_str());
    char* final = new char[strlen(description) + sizeof(int) + 1];
    memcpy(final, &size, sizeof(int));
    strcpy(final+sizeof(int), description);
    
    Handle* bestFit = NULL;
    Handle* handle;
    list<Handle*>::iterator iter = freeList.begin();
    if(iter != NULL)
    {
        handle = *iter;
        if (handle->getLength() > strlen(description))
        {
            bestFit = *iter;
        }
    }
    while(iter++ != freeList.end())
    {
        handle = *iter;
        if (bestFit != NULL)
        {
            if (handle->getLength() > strlen(description) && handle->getLength() < bestFit->getLength())
            {
                bestFit = handle;
            }
        }
        else
        {
            if (handle->getLength() > strlen(description))
            {
                bestFit = handle;
            }
        }
    }
    int location;
    if (bestFit == NULL)
    {
        location = fileLoc;
        handle = new Handle(strlen(final), location, ID);
        handler[ID] = handle;
        insertHelper(final, location);
        fileLoc += strlen(final);
    }
    else
    {
        location = bestFit->getLocation();
        handle = new Handle(strlen(final), location, ID);
        handler[ID] = handle;
        insertHelper(final, location);
        freeList.remove(bestFit);
    }
    return handle;
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

void MemoryManager::insertHelper(char* description, unsigned int location)
{
    if (strlen(description) + location%BLOCKSIZE <= BLOCKSIZE)
    {
        buffer.write(description, location);
    }
    else
    {
        char* temp = description;
        int size = strlen(description);
        int tempLoc = location;
        while(size + tempLoc%BLOCKSIZE > BLOCKSIZE)
        {
            char* tempDesc = new char[BLOCKSIZE - (tempLoc%BLOCKSIZE)];
            if (size > BLOCKSIZE - (tempLoc%BLOCKSIZE))
            {
                memcpy(tempDesc, description, BLOCKSIZE - (tempLoc%BLOCKSIZE)];
                size = size - (BLOCKSIZE - (tempLoc%BLOCKSIZE));
                tempLoc = 0;
            }
            else
            {
                
            }
            
        }
    }
}
