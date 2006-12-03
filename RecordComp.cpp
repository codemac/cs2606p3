#include "RecordComp.h"

bool RecordComp::lt(Record* lhs, Record* rhs) {
	return lhs->ID() < rhs->ID();
}

bool RecordComp::lt(Record* lhs, unsigned int rhs) {
	return lhs->ID() < rhs;
}

unsigned int* RecordComp::getDiscrim(Record* obj)
{
	return new unsigned int(obj->ID());	
}

bool RecordComp::equal(Record* lhs, Record* rhs) {
	return lhs->ID() == rhs->ID();
}

void RecordComp::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << obj->ID() << endl;
}

BTreeNode* RecordComp::splice(BTreeNode* bt) {
	//	TODO
}
