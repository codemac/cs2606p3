#ifndef HANDLE_H_
#define HANDLE_H_

class Handle
{
    public:
    Handle(int length, int location, int ID);
    ~Handle();
    unsigned int getLocation();
    unsigned int getLength();
    unsigned int getID();
    
    private:
    unsigned int strLength;
    unsigned int strLocation;
    unsigned int strID;
};
#endif //HANDLE_H_
