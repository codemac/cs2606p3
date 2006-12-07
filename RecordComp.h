#ifndef RECORDCOMP_H
#define RECORDCOMP_H

/**
 * This is a comparator class used to compare ID variables in a record class.
 * This class is used in the B+ tree to make useful comparisons between various
 * records stored in leaf nodes.
 * 
 * @author braundui @ codemac
 * 
 * @version December 6th, 2006
 */

#include <iostream>
#include "BTreeNode.h"
#include "Record.h"

using namespace std;

class RecordComp {
	public:
/**
 * Logically a < operation on the records' ID variables
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs ID < rhs ID
 */
		bool lt(Record* lhs, Record* rhs);
/**
 * Logically a < operation on the record's ID variable and an unsigned int
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs ID < rhs
 */
		bool lt(Record* lhs, unsigned int rhs);
/**
 * Returns the discriminate of the sent in record based on this comparator
 * @param obj the record to get the discriminate from
 * @return the ID of the record
 */
		int getDiscrim(Record* obj);
/**
 * Logically a == operation on the records' ID variables
 * @param lhs the left hand side of the equation
 * @param rhs the right hand side of the equation
 * @return true if lhs ID == rhs ID
 */
		bool equal(Record* lhs, Record* rhs);
/**
 * Prints out the ID of the parameter twice
 * @param obj the record to print out
 */
		void dump(Record* obj);
/**
 * Returns an array of records for the btree to inspect
 * for comparison
 * @param bt Pointer to btree node of which to splice out records.
 * @return array of record pointers
 */
		Record** splice(BTreeNode<Record>* bt);
};
#endif
