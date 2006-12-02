#ifndef BTREE_H
#define BTREE_H

#include "Record.h"

using namespace std;

template <typename R>
class BTree {
	private:
	public:
		bool insert(R* record);
		bool delete(R* record);
		void search(R* record, bool debug = true);
		void searchRange(R* record1, R* record2, bool debug = true);
		void dump();
};

#include "BTreeImplementation.h"

#endif