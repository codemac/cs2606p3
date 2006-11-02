#include "StringDB.h"

StringDB::StringDB(char* a, int b)
{
	memory.init(a, b);
}

StringDB::StringDB()
{
    
}

StringDB::~StringDB()
{
    
}

void StringDB::parse()
{
	string name;
    int ID;
    cout << "Start commands" << endl;
    while(cin)
    {
        cin >> name;
        cout << "Command:" << name << endl;
        if(name == "print")
        {
            cin >> ID;
            print(ID);
        }
        else if(name == "dump")
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
			string lines, line;
			string word;
			
			cin >> ID;
			getline(cin, line);
			
			bool ok = true;
			while(ok) {
				line = "";
				word = "";
				getline(cin, line);
				istringstream inn(line);
				inn >> word;
				cout << "Getting words..." << endl;
				if ( word.length() > 0 ) {
					cout << "Adding Line..." << word << endl;
					lines = lines + line + "\n";
				}
				else {
					lines.erase(lines.length()-1);
					insert(ID,lines);
                    ok = false;
				}
			}
        }
        else
        {
            cout << "Command Failed:  Incorrect Arguments" << endl;
        }                                                                      
    }
}

void StringDB::insert(int ID, string name)
{
	memory.insert(ID, name);
}

void StringDB::remove(int ID)
{
	memory.release(ID);
}

void StringDB::dump()
{
	memory.dump();
}

void StringDB::print(int ID)
{
	memory.print(ID);
}
