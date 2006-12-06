#include "Parser.h"

Parser::Parser(char* a, int b)
{
	tree.init(a, b);
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
			string title, date = "";
            int length, cost = 0;
			
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
            if(range == 4202315)
            {
                //search(flag, ID);
            }
            else
            {
                //search(flag, ID, range);
            }
        }
        else
        {
            cout << "Command Failed:  Incorrect Arguments" << endl;
        }                                                                      
    }
}

/*
void Parser::insert(int ID, string title, string date, int length, int cost)
{
	tree.insert(ID, name);
}

void Parser::remove(int ID)
{
	tree.release(ID);
}

void Parser::dump()
{
	tree.dump();
}

void Parser::search(string flag, int ID, int range)
{
	tree.search
}

void Parser::search(string flag, int ID)
{
    
}
*/
