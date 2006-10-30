#include "Handle.h"

Handle::Handle(int length, void* location)
{
    strLength = length;
    strLocation = location;
}

Handle::~Handle()
{
    
}

void* Handle::getLocation()
{
    return strLocation;
}

int Handle::getLength()
{
    return strLength;
}
