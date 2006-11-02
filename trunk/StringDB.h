#ifndef STRINGDB_H_
#define STRINGDB_H_

using namespace std;
#include "MemoryManager.h"

class StringDB
{
    public:
    void parse();
    StringDB(char* file, int buffernumber);
    StringDB();
    ~StringDB();
    
    private:
	MemoryManager memory;

    void insert(int ID, string name);
    void dump();
    void remove(int ID);
    void print(int ID);
};
#endif //STRINGDB_H_
