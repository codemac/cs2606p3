#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <cstring>

#include "BTreeNode.h"
#include "BTreeLeafNode.h"
#include "BTreeInternalNode.h"
#include "MemoryManager.h"

using namespace std;

const static unsigned int BLOCKSIZE = 512;

template <typename R, typename C>
class BTree {
	private:
		BTreeNode<R>* root;				//!<	root node of btree
		C compare;                      //!<	comparator object
		MemoryManager mm;               //!<	Memory Manager object
        
        /**
         * This method is a recursive helper method used by dump to go
         * through the tree and dump the resulting nodes and records.
         * @param root the root to start the dump
         */
		void dumpHelper(BTreeNode<R>* root);
		
		/**
		 * A recursive method to find a record in the tree by searching
		 * through it's internal node
		 * @param debug print debug method?
		 * @param record record to find
		 * @param root root of tree to search
		 * @return BTreeNode<R>* Node that contains the record
		 */
		BTreeNode<R>* findNode(bool debug, R* record, BTreeNode<R>* root);

		/**
		 * Finds the parent of the current node.
		 * @param node node to find parent of
		 * @param root root of btree to find parent in
		 * @return BTreeNode<R>* BTreeNode that is the parent of node
		 */
		BTreeNode<R>* findParent(BTreeNode<R>* node, BTreeNode<R>* root);

		/**
		 * recursive helper for search to traverse the tree,
		 * printing nodes along the way.
		 * @param bedug print debug info?
		 * @param node node to start searching on
		 * @param record1 first record of search
		 * @param record2 optional second record of search
		 */
		void printSearch(bool debug, BTreeNode<R>* node, R* record1, R* record2);

		/**
		 * Return the node at the given fileoffset.
		 * @param fileOffset integer of the fileoffset to begin the node
		 * @return BTreeNode<R>* node made
		 */
		BTreeNode<R>* makeNode( int fileOffset );

		/**
		 * Create a new leaf with the given records and insert
		 * it into the tree.
		 * @param records records to add to the node
		 * @param length length of the records
		 * @param node node to add to the right of
		 * @return BTreeNode<R>* node created
		 */
		BTreeNode<R>* newLeaf(R** records,int length, BTreeNode<R>* node);

		/**
		 * Creates a char* of the given node.
		 * @param node node to make a char* of
		 * @return char* BLOCKSIZE-sized char* of the node
		 */
		char* charstar(BTreeNode<R>* node);

	public:

		/**
		 * default constructor.
		 */
        BTree();

		/**
		 * default destructor.
		 */
        ~BTree();

		/**
		 * initialize the BTree.
		 * @param fileLocation path to file to write to
		 * @param numBuffers number of buffers to use
		 */
        void init(char* fileLocation, int numBuffers);

		/**
		 * Adds a record to the BTree.
		 * @param record record to insert
		 * @return bool successful insert?
		 */
		bool insert(R* record);

		/**
		 * Deletes a record from the BTree.
		 * @param record record to delete
		 * @return bool successful delete?
		 */
		bool remove(R* record);

		/**
		 * search the tree for a record, or a range of records
		 * when given the optional second parameter.
		 * @param debug print debug info?
		 * @param record1 record to find
		 * @param record2 last record in range to find if given
		 */
		void search(bool debug, R* record1, R* record2 = 0);

		/**
		 * dumps the tree as output to the screen.
		 */
		void dump();
};

#include "BTreeImplementation.h"

#endif

