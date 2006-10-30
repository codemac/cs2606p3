#ifndef STRINGDB_H_
#define STRINGDB_H_

#include <string>
#include <iostream>
#include <sstream>
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

StringDB::StringDB()
{
    
}

StringDB::~StringDB()
{
    
}

void StringDB::parse()
{
    string line;
    string name;
    int ID;
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "Start commands" << endl;
    while(cin)
    {
        cin >> name;
        cout << "Command:" << name << endl;
        if(name == "dump")
        {
            dump();
        }
        else if (name == "remove")
        {
            cin >> ID;
            remove(ID);
            
        }
        else if(name == "insert")
        {
            cin >> ID;
            getline(cin, line);
            getline(cin, line);
            name = line;
            unsigned int index = line.find_first_of(letters,0);
            while(index != string::npos)
            {
                getline(cin, line);
                index = line.find_first_of(letters,0);
                name += line;
            }
            insert(ID, name);
        }
        else
        {
            cout << "Command Failed:  Incorrect Arguments" << endl;
        }                                                                      
    }
}

void StringDB::insert(int ID, string name)
{
    cout << "INSERT" << endl;
}

void StringDB::remove(int ID)
{
    cout << "REMOVE" << endl;
}

void StringDB::dump()
{
    cout << "DUMP" << endl;
}

#endif //STRINGDB_H_
