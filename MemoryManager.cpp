#include "MemoryManager.h"

MemoryManager::MemoryManager()
{
    count = 0;
}

void MemoryManager::init(char* fileLocation, int numBuffers)
{
    buffer.init(fileLocation, numBuffers);
}

MemoryManager::~MemoryManager()
{
}

bool MemoryManager::insert(int location, char* record)
{
    count++;
    buffer.write(record, location, BLOCKSIZE);
    return true;
}

char* MemoryManager::get(int fileOffset)
{
    char* description = new char[BLOCKSIZE];
    buffer.read(description, fileOffset, BLOCKSIZE);
    return description;
}

int MemoryManager::freeList()
{
    list<int>::iterator iter = fList.begin();
    int firstSlot = -1;
    int temp;
    while(iter != fList.end())
    {
        temp = *iter;
        if(firstSlot == -1)
        {
            firstSlot = temp;
        }
        else if(temp < firstSlot)
        {
            firstSlot = temp;
        }
        iter++;
    }
    if (firstSlot == -1)
    {
        return (count * 512);
    }
    else
    {
        fList.remove(temp);
        return temp;
    }
}

void MemoryManager::addFreeList(int fileOffset)
{
    fList.push_back(fileOffset);
}
