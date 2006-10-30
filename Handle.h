#ifndef HANDLE_H_
#define HANDLE_H_

class Handle
{
    public:
    Handle(int length, void* location, int ID);
    ~Handle();
    void* getLocation();
    int getLength();
    int getID();
    
    private:
    int strLength;
    void* strLocation;
    int strID;
};
#endif //HANDLE_H_
