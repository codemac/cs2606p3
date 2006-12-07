#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>

using namespace std;

class Record {
	private:
		string ttitle,				///	record title
			   ddatetime;			///	date in format YYMMDDHHmm

		int llength,		///	length in minutes
			ccost,			///	cost in whole dollar amounts
			IID;			///	unique ID

	public:

        /**
         * Default Constructor.
         */
		Record();

        /**
         * Destructor.
         */
		~Record();
        
        /**
         * This method returns the title field for the record.
         * @return string the title.
         */
		string title();
        
        /**
         * This method is used to set the title field for the record.
         * @param t the title to set.
         */
		void title(const string& t);

        /**
         * This method returns the date field for the record.
         * @return string the date.
         */
		string date();
        
        /**
         * This method is used to set the date field for the record
         * @param d the date to set.
         */
		void date(const string& d);

        /**
         * This method returns the length field for the record.
         * @return int the length field.
         */
		int length();
        
        /**
         * This method is used to set the length field for the record
         * @param l the length to set.
         */
		void length(const unsigned int& l);

        /**
         * This method is used to print to cout the ID field for this record
         * along with the length of a char* holding all the fields of this
         * record.
         */
		void dump();
        
        /**
         * This method is used to return the length of the char* holding all
         * the fields of the record to be used in the dump method
         * @return int the length
         */
		int dumpLength();

        /**
         * This method returns the cost field for the record
         * @return int the cost field.
         */
		int cost();
        
        /**
         * This method is used to set the cost field of the record
         * @param c the cost to set.
         */
		void cost(const unsigned int& c);

        /**
         * This method returns the ID field of the record
         * @return int the ID
         */
		int ID();
        
        /**
         * This method sets the ID field of the record
         * @param i the ID to set
         */
		void ID(const unsigned int& i);

        /**
         * This method makes a char* of the fields of the record to be used
         * in storing it on file.
         * @return char* the char* created.
         */
		char* charstar();
};
#endif
