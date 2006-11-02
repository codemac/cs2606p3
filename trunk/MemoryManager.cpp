#include "MemoryManager.h"

MemoryManager::MemoryManager()
{
    fileLoc = 0;
    for (unsigned int i = 0; i < NUMIDS; i++)
    {
        handler[i] = NULL;
    }
}

void MemoryManager::init(char* fileLocation, int numBuffers)
{
    buffer.init(fileLocation, numBuffers);
}

MemoryManager::~MemoryManager()
{
    delete handler;
}

Handle* MemoryManager::insert(int ID, string name)
{
    release(ID);
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
    if (handle != NULL)
    {
        merge(handle);
    }
    handler[ID] = NULL;
}

char* MemoryManager::get(Handle* handle)
{
    if(handle != NULL)
    {
        int length = handle->getLength();
        int location = handle->getLocation();
        char* description = new char[length];
        buffer.read(description, location, length);
        return description;
    }
    else
    {
        char* temp;
        return temp;
    }
}

void MemoryManager::insertHelper(char* description, unsigned int location)
{
    if (strlen(description) + location%BLOCKSIZE <= BLOCKSIZE)
    {
        buffer.write(description, location);
    }
    else
    {
        unsigned int size = strlen(description);
        char* temp = new char[size - (BLOCKSIZE - (location%BLOCKSIZE))];
        char* tempDesc = new char[BLOCKSIZE - (location%BLOCKSIZE)];
        memcpy(tempDesc, description, BLOCKSIZE - (location%BLOCKSIZE));
        size = size - (BLOCKSIZE - (location%BLOCKSIZE));
        memcpy(temp, description + (BLOCKSIZE - (location%BLOCKSIZE)), size);
        buffer.write(tempDesc, BLOCKSIZE - (location%BLOCKSIZE));
        insertHelper(temp, location + (BLOCKSIZE - (location%BLOCKSIZE)));
    }
}

void MemoryManager::dump()
{
    list<Handle*>::iterator iter = freeList.begin();
    int count = 0;
    while(iter != freeList.end())
    {
        cout << "BLOCK " << count << endl;
        Handle* handle = *iter;
        cout << "Location: " << handle->getLocation() << " --- Size: " << handle->getLength() << endl;
        iter++;
        count++;
    }
    if (count == 0)
    {
        cout << "Free List is empty" << endl;
    }
}

void MemoryManager::print(int ID)
{
    Handle* handle = handler[ID];
    if (handle != NULL)
    {
        char* printString = new char[handle->getLength()];
        buffer.read(printString, handle->getLocation(), handle->getLength());
        cout << "ID: " << ID << endl;
        cout << printString << endl;
    }
    else
    {
        cout << "No such ID found" << endl;
    }
}

void MemoryManager::merge(Handle* handle)
{
    Handle* temp;
    Handle* merged = handle;
    list<Handle*>::iterator iter = freeList.begin();
    while(iter != freeList.end())
    {
        temp = *iter;
        if(handle->getLocation() + handle->getLength() == temp->getLocation())
        {
            merged = new Handle(handle->getLength() + temp->getLength(), handle->getLocation(), 0);
            freeList.remove(temp);
        }
        else if(temp->getLocation() + temp->getLength() == handle->getLocation())
        {
            merged = new Handle(temp->getLength() + handle->getLength(), temp->getLocation(), 0);
            freeList.remove(temp);
        }
    }
    if (handle->getLocation() + handle->getLength() == fileLoc)
    {
        fileLoc = fileLoc - handle->getLength();
    }
    else
    {
        freeList.push_back(merged);
    }
}
