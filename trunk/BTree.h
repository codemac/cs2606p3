#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <cstring>

#include "BTreeNode.h"
#include "BTreeLeafNode.h"
#include "BTreeInternalNode.h"
#include "MemoryManager.h"

using namespace std;

const static int BLOCKSIZE = 512;

template <typename R, typename C>
class BTree {
	private:
		BTreeNode<R>* root;				//	 root node of btree
		C compare;                      //   comparator object
		MemoryManager mm;               //   Memory Manager object
        
        /**
         * This method is a recursive helper method used by dump to go
         * through the tree and dump the resulting nodes and records.
         * @param root the root to start the dump
         */
		void dumpHelper(BTreeNode<R>* root);
		BTreeNode<R>* findNode(bool debug, R* record, BTreeNode<R>* root);
		BTreeNode<R>* findParent(BTreeNode<R>* node, BTreeNode<R>* root);
		void printSearch(bool debug, BTreeNode<R>* node, R* record1, R* record2);
		BTreeNode<R>* makeNode( int fileOffset );
		BTreeNode<R>* newLeaf(R** records,int length, BTreeNode<R>* node);
		char* charstar(BTreeNode<R>* node);
	public:
        BTree();
        ~BTree();
        void init(char* fileLocation, int numBuffers);
		bool insert(R* record);
		bool remove(R* record);
		void search(bool debug, R* record1, R* record2 = 0);
		void dump();
};

#include "BTreeImplementation.h"

#endif

