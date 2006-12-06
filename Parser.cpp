#include "Parser.h"

Parser::Parser(char* a, int b)
{
	memory.init(a, b);
}

Parser::Parser()
{
    
}

Parser::~Parser()
{
    
}

void Parser::parse()
{
	string name;
    int ID;
    cout << "Start commands" << endl;
    while(cin)
    {
        cin >> name;
        cout << "Command:" << name << endl;
        if(name == "dump")
        {
            //dump();
        }
        else if (name == "delete")
        {
            cin >> ID;
            //remove(ID);
            
        }
        else if(name == "insert")
        {
			string title, date, length, cost= "";
			
			cin >> ID;
            cin >> title;
            cin >> date;
            cin >> length;
            cin >> cost;
            //insert(ID, title, date, length, cost);
        }
        else if(name == "search")
        {
            string line, flag = "";
            int range;
            
            getline(cin, line);
            istringstream inn(line);
            
            inn >> flag;
            inn >> ID;
            inn >> range;
            cout << range;
        }
        else
        {
            cout << "Command Failed:  Incorrect Arguments" << endl;
        }                                                                      
    }
}

/*
void Parser::insert(int ID, string name)
{
	memory.insert(ID, name);
}

void Parser::delete(int ID)
{
	memory.release(ID);
}

void Parser::dump()
{
	memory.dump();
}

void Parser::search(string flag, int ID, int range)
{
	memory.print(ID);
}
*/
