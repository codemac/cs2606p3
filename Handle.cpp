#include "Handle.h"

Handle::Handle(int length, int location, int ID)
{
    strLength = length;
    strLocation = location;
    strID = ID;
}

Handle::Handle()
{
    strLength = 0;
    strLocation = 0;
    strID = 0;
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
