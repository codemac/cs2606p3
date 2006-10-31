#ifndef HANDLE_H_
#define HANDLE_H_

class Handle
{
    public:
    Handle(int length, int location, int ID);
    Handle();
    ~Handle();
    int getLocation();
    int getLength();
    int getID();
    
    private:
    int strLength;
    int strLocation;
    int strID;
};
#endif //HANDLE_H_
