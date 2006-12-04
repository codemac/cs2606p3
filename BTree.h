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
		BTreeNode<R>* root;				///	 root node of btree
		C compare;
		MemoryManager mm(512);
		void dumpHelper(BTreeNode<R>* root);
		BTreeNode<R>* findNode(bool debug, R* record, R* root);
		void printSearch(bool debug, BTreeNode<R>* node, R* record1, R* record2);
		BTreeNode<R>* makeNode( int fileOffset );
		BTreeNode<R>* newLeaf(R** records,int length, BTreeNode<R>* node);
	public:
		bool insert(R* record);
		bool delete(R* record);
		void search(bool debug, R* record1, R* record2 = 0);
		void dump();
};

#include "BTreeImplementation.h"

#endif

