#ifndef PARSER_H_
#define PARSER_H_

using namespace std;
#include "MemoryManager.h"

/**
 * Class Parser
 * 
 * This class takes an input, parses it, and calls resulting functions
 * to either insert a string into the file, print the string corresponding
 * to an ID in the file, dump the freeList stored in the MemoryManager class
 * or remove the string from the file that corresponds to an ID.
 * 
 * @author codemac @ braundui
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
     * to be stored in the file to pass down to the Memory Manager.
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
	MemoryManager memory;
    
    /**
     * This method takes an ID and a string that have been parsed from input
     * and calls the insert method in the MemoryManager class with those values
     * @param ID the ID of the string to be inserted.
     * @param name the string to be inserted into file.
     */
    void insert(int ID, string name);
    
    /**
     * this method calls the dump method of the Memory Manager and prints out
     * a list of the blocks in the freeList.
     */
    void dump();
    
    /**
     * This method calls the release method of the Memory Manager class.  It
     * takes an ID and removes the resulting string that corresponds to that
     * ID from the file.
     * @param ID the ID to remove.
     */
    void remove(int ID);
    
    /**
     * This method calls the print method of the MemoryManager class.  It takes
     * and ID and prints out the corresponding string for that ID.
     * @param ID the ID to print out.
     */
    void print(int ID);
};
#endif //PARSER_H_
