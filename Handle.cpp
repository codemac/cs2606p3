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
