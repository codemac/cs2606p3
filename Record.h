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

		Record();

		~Record();

		string title();
		void title(const string& t);

		string date();
		void date(const string& d);

		int length();
		void length(const unsigned int& l);

		void dump();
		int dumpLength();

		int cost();
		void cost(const unsigned int& c);

		int ID();
		void ID(const unsigned int& i);

		char* charstar();
};
#endif
