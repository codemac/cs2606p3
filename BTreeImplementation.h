#include "BTree.h"

template <typename R, typename C>
void BTree<R,C>::dump() {
	dumpHelper(root);
}

template <typename R, typename C>
void BTree<R,C>::dumpHelper(BTreeNode* root) {
	if ( root == 0 )
		return;

	root->print();
	if (! root->isLeaf() ) {
		//	do the children thing
		int* child = root->pointer();
		for (int i = 0; child[i] != -1; i++) {
			dumpHelper(makeNode(child[i]));
		}
	}
}

template <typename R, typename C>
void BTree<R,C>::search(bool debug, R* record1, R* record2 = 0 ) {
	//	find first node that contains the first record
	//	if record2 == 0, stop
	//	else loop through records to see if record2 limit is there
	//		if compare.lt(records[i], record2) fails, check if equal, then print or no print
	//		else go to node->right() and search it's records, etc...
	printSearch(debug, findNode(debug, record1, root), record1, record2);
}

template <typename R, typename C>
BTreeNode* BTree<R,C>::findNode(bool debug, R* record, R* root) {
	if ( root ) {
		if ( debug ) root->print();
		if ( root->isLeaf() ) {
			return root;
		} else if ( record ) {
			int* key = root->key();
			int* pointer = root->pointer();

			for ( int i = 0; key[i] != -1; i++) {
				if ( key[i] > compare.getDiscrim(record) )
					findNode(debug,record,makeNode(pointer[i-1]));
			}

		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

template <typename R, typename C>
void printSearch(bool debug, BTreeNode* node, R* record1, R* record2) {
	if ( debug ) node->print();

	if ( record2 ) {
		R** records = node->record();
		int i = 0;
		for ( i = 0; records[i] != 0 && i != -1; i++ ) {
			if ( compare.equal(records[i], record1) ||
					( compare.lt(records[i], record2) ||
					  compare.equal(records[i], record2) ) )
				records[i]->print();
			else
				i = -1;
		}
		if (i != -1) {
			printSearch(debug, makeNode(node->right()), record1, record2);
		}
	}
}

template <typename R, typename C>
bool BTree<R,C>::delete(R* record) {
}

template <typename R, typename C>
bool BTree<R,C>::insert(R* record) {
	if ( record ) {
		BTreeNode* node = findNode(false, record, root);
		node->addRecord(record);
		char* node = charstar(node);
		if ( strlen(node) > BLOCKSIZE ) {
			if ( node->removeRecord(record) ) {
				
			} else {
				return false;
			}
		} else {
			return true;
		}
	} else {
		return false;
	}
}

