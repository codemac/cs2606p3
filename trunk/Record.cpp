#include "Record.h"
/**
 * This is all getters and setters, it's self explanitory
 */
Record::Record() {
}
Record::~Record() {
}

string Record::title() {
	return ttitle;
}

void Record::title(const string& t) {
	ttitle = t;
}

string Record::date() {
	return ddatetime;
}

void Record::date(const string& d) {
	ddatetime = d;
}

int Record::length() {
	return llength;
}

void Record::length(const unsigned int& l) {
	llength = l;
}

int Record::cost() {
	return ccost;
}

void Record::cost(const unsigned int& c) {
	ccost = c;
}

int Record::ID() {
	return IID;
}

char* Record::dump() {
	char* final = new char[dumpLength()];
	int offset = 0;
	int length = records[i]->length();
	int cost = records[i]->cost();
	int id = records[i]->ID();
	
	char* title = records[i]->title().c_str();
	char* datetime = records[i]->date().c_str();
	
	memcpy(final+offset, &length, sizeof(int));
	offset += sizeof(int);
	memcpy(final+offset, &cost, sizeof(int));
	offset += sizeof(int);
	memcpy(final+offset, &id, sizeof(int));
	offset += sizeof(int);

	memcpy(final+offset, title, strlen(title)+1);
	offset += strlen(title)+1;
	memcpy(final+offset, datetime, strlen(datetime)+1);
	offset += strlen(datetime)+1;

	return final;
}

int Record::dumpLength() {
	return (sizeof(int) * 3) + strlen(title)+1 + strlen(datetime)+1;
}

void Record::ID(const unsigned int& i) {
	IID = i;
}

