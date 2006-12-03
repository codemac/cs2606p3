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
			dumpHelper(mm->nodeat(child[i]*BLOCKSIZE));
		}
	}
}

template <typename R, typename C>
void BTree<R,C>::search(bool debug, R* record1, R* record2 = 0 ) {
	BTreeNode* bt = findFirstRecord(debug, record1, root);
	if ( bt ) {
		bt->print();
		if ( record2 != 0 ) {
			next = mm->nodeat(bt->right()*BLOCKSIZE);
			while ( next != 0 ) {
				if ( debug )
					next->print();
				
				if ( )
				next = mm->nodeat(bt->right()*BLOCKSIZE);
			}
		}
	} else {
		cout << "No results found." << endl;
	}
}

template <typename R, typename C>
BTreeNode* BTree<R,C>::findFirstRecord(bool debug, R* record, R* root) {
	if (root == 0 || record == 0)
		return 0;
	} else if ( root->isLeaf() ) {
		if (debug)
			root->print();
		R** records = compare.splice(root);
		for ( int i=0; records[i] != 0; i++ )
			
	} else {
		int* key = root->key();
		int* pointer = root->pointer();

		for (int i = 0; pointer[i] != -1; i++) {
			BTreeNode* bt = mm->nodeat(pointer[i]*BLOCKSIZE);
			bt->findFirstRecord(debug,record,bt);
		}
	}
}

template <typename R, typename C>
bool BTree<R,C>::delete(R* record) {
}

template <typename R, typename C>
bool BTree<R,C>::insert(R* record) {
}

