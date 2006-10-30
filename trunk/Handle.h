#ifndef HANDLE_H_
#define HANDLE_H_

Class Handle
{
    public:
    Handle(int length, int location);
    ~Handle();
    int getLocation();
    int getLength();
    
    private:
    int strLength;
    int strLocation;
};

Handle::Handle(int length, int location)
{
    strLength = length;
    strLocation = location;
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
    return strLength();
}

#endif //HANDLE_H_