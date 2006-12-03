#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include "BTreeNode.h"
#include "BTreeLeafNode.h"
#include "BTreeInternalNode.h"
#include "MemoryManager.h"

using namespace std;

const static int BLOCKSIZE = 512;

template <typename R, typename C>
class BTree {
	private:
		BTreeNode* root;				///	 root node of btree
		C compare;
		MemoryManager mm(512);
		void dumpHelper(BTreeNode* root);
		BTreeNode* findFirstRecord(bool debug, R* record, R* root);
	public:
		bool insert(R* record);
		bool delete(R* record);
		void search(bool debug, R* record1, R* record2 = 0);
		void dump();
};

#include "BTreeImplementation.h"

#endif

