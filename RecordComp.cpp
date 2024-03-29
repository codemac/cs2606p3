#include "RecordComp.h"

bool RecordComp::lt(Record* lhs, Record* rhs) {
	return lhs->ID() < rhs->ID();
}

bool RecordComp::lt(Record* lhs, unsigned int rhs) {
	return lhs->ID() < rhs;
}

int RecordComp::getDiscrim(Record* obj)
{
	return obj->ID();	
}

bool RecordComp::equal(Record* lhs, Record* rhs) {
	return lhs->ID() == rhs->ID();
}

void RecordComp::dump(Record* obj) {
	cout << "Record " << obj->ID() << ": " << obj->ID() << endl;
}

Record** RecordComp::splice(BTreeNode<Record>* bt) {
	//	TODO
}
