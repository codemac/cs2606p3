#include "Handle.h"

Handle::Handle(int length, int location, int ID)
{
    strLength = length;
    strLocation = location;
    strID = ID;
}

Handle::~Handle()
{
}

int Handle::getLocation()
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
