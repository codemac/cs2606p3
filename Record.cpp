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

void Record::ID(const unsigned int& i) {
	IID = i;
}

