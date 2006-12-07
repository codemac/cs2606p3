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
            dump();
        }
        else if (name == "delete")
        {
            cin >> ID;
            Record* rec = new Record();
            rec->ID(ID);
            remove(rec);
            
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
            Record* rec = new Record();
            rec->title(title);
            rec->ID(ID);
            rec->date(date);
            rec->length(length);
            rec->cost(cost);
            insert(rec);
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
                search(flag, ID);
            }
            else
            {
                search(flag, ID, range);
            }
        }
        else
        {
            cout << "Command Failed:  Incorrect Arguments" << endl;
        }                                                                      
    }
}


void Parser::insert(Record* record)
{
	tree.insert(record);
}

void Parser::remove(Record* record)
{
	tree.remove(record);
}

void Parser::dump()
{
	tree.dump();
    cout << "Dump Completed" << endl;
}

void Parser::search(string flag, int ID, int range)
{
    bool flagged = false;
    if (flag == "+")
    {
        flagged = true;
    }
    Record* low = new Record();
    low->ID(ID);
    Record* high = new Record();
    high->ID(range);
	tree.search(flagged, low, high);
    cout << "Search Completed" << endl;
}

void Parser::search(string flag, int ID)
{
    bool flagged = false;
    if (flag == "+")
    {
        flagged = true;
    }
    Record* low = new Record();
    low->ID(ID);
    tree.search(flagged, low);
    cout << "Search Completed" << endl;
}
