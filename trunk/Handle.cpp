#include "Handle.h"

Handle::Handle(int length, void* location, int ID)
{
    strLength = length;
    strLocation = location;
    strID = ID;
}

Handle::~Handle()
{
    if(strLocation != 0)
    {
        delete strLocation;
    }
}

void* Handle::getLocation()
{
    return strLocation;
}

int Handle::getLength()
{
    return strLength;
}

int Handle::getID()
{
    return strID;
}
