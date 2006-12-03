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
	findFirstRecord(debug, record1, root);
}

template <typename R, typename C>
void BTree<R,C>::findFirstRecord(bool debug, R* record, R* root) {
	if (root == 0 || record == 0)
		return;
	if (compare.equal(root, record)) {
		root->print();
	} else {
		int* key = root->key();
		int* pointer = root->pointer();

		for (int i = 0; pointer[i] != -1; i++) {
			if (key[i] == compare.getDiscrim(record))
				return mm->nodeat(pointer[i]*BLOCKSIZE);
		}
	}

}

template <typename R, typename C>
bool BTree<R,C>::delete(R* record) {
}

template <typename R, typename C>
bool BTree<R,C>::insert(R* record) {
}

