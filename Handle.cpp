#include "Handle.h"

Handle::Handle(int length = 0, int location = 0, int ID = 0)
{
    strLength = length;
    strLocation = location;
    strID = ID;
}

Handle::~Handle()
{
}

unsigned int Handle::getLocation()
{
    return strLocation;
}

unsigned int Handle::getLength()
{
    return strLength;
}

unsigned int Handle::getID()
{
    return strID;
}
