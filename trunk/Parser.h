#ifndef PARSER_H_
#define PARSER_H_

using namespace std;
#include "BTree.h"
#include "Record.h"
#include "RecordComp.h"

/**
 * Class Parser
 * 
 * This class takes an input, parses it, and calls resulting functions
 * to either insert a record into the BTree, dump the contents of the BTree,
 * search for records in the BTree, or delete records from the BTree.
 * 
 * @author codemac @ braundui
 * 
 * @version December 6th, 2006
 */

class Parser
{
    public:
    /**
     * This method parses the input and calls the resulting function based
     * on the command called from the input.  Provides useful information
     * to the person giving commands via cout.
     */
    void parse();
    
    /**
     * Constructor.  Takes in the file to write to and the number of buffers
     * to be stored in the file to pass down to the B+ Tree.
     */
    Parser(char* file, int buffernumber);
    
    /**
     * Default Constructor.
     */
    Parser();
    
    /**
     * Destructor.
     */
    ~Parser();
    
    private:
    
	BTree<Record, RecordComp> tree;  //the B+ tree that stores the records.
    
    /**
     * This method takes a record that has been parsed from input
     * and calls the insert method in the BTree class with that record
     * @param record the record to be inserted into the tree.
     */
    void insert(Record* record);
    
    /**
     * this method calls the dump method of the BTree, which prints out a 
     * list of nodes and records in the tree.
     */
    void dump();
    
    /**
     * This method calls the remove method of the B+ Tree and is used to 
     * delete a record out of the tree.
     * @param record the record to remove from the tree.
     */
    void remove(Record* record);
    
    /**
     * This method calls the search method of the B+ Tree.  It is used to
     * search through the tree to try and find a record with the same ID
     * as the parameter.
     * @param flag a flag used in the B+ tree to determine what to print.
     * @param ID the ID to search for.
     */
    void search(string flag, int ID);
    
    /**
     * This method calls the search method of the B+ Tree.  It is used to
     * search through the tree to try and find a list of records within
     * the range of the ID and range parameters.
     * @param flag a flag used in the B+ tree to determine what to print.
     * @param ID the first ID of the search rangeS
     * @param range the second ID of the search range
     */
    void search(string flag, int ID, int range);
};
#endif //PARSER_H_
