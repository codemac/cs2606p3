#ifndef HANDLE_H_
#define HANDLE_H_

Class Handle
{
    public:
    Handle(int length, void* location);
    ~Handle();
    void* getLocation();
    int getLength();
    
    private:
    int strLength;
    void* strLocation;
};

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
    return strLength();
}

#endif //HANDLE_H_