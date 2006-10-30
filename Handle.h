#ifndef HANDLE_H_
#define HANDLE_H_

class Handle
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
#endif //HANDLE_H_
