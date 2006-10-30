#ifndef STRINGDB_H_
#define STRINGDB_H_

using namespace std;

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
};
#endif //STRINGDB_H_
