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
}

template <typename R, typename C>
BTreeNode* BTree<R,C>::findFirstRecord(bool debug, R* record, R* root) {
}

template <typename R, typename C>
bool BTree<R,C>::delete(R* record) {
}

template <typename R, typename C>
bool BTree<R,C>::insert(R* record) {

}

