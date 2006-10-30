#include "Handle.h"

Handle::Handle(int length, void* location)
{
    strLength = length;
    strLocation = location;
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
