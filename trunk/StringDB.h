#ifndef STRINGDB_H_
#define STRINGDB_H_

using namespace std;
#include "MemoryManager.h"

class StringDB
{
    public:
    void parse();
    StringDB();
    ~StringDB();
    
    private:
    void insert(int ID, string name);
    void dump();
    void remove(int ID);
    void print(int ID);
};
#endif //STRINGDB_H_
