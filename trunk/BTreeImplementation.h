#include "BTree.h"

template <typename R, typename C>
void BTree<R,C>::dump() {
	dumpHelper(root);
}

template <typename R, typename C>
void BTree<R,C>::dumpHelper(BTreeNode<R>* root) {
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
void BTree<R,C>::search(bool debug, R* record1, R* record2 ) {
	//	find first node that contains the first record
	//	if record2 == 0, stop
	//	else loop through records to see if record2 limit is there
	//		if compare.lt(records[i], record2) fails, check if equal, then print or no print
	//		else go to node->right() and search it's records, etc...
	printSearch(debug, findNode(debug, record1, root), record1, record2);
}

template <typename R, typename C>
BTreeNode<R>* BTree<R,C>::findNode(bool debug, R* record, R* root) {
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
void BTree<R,C>::printSearch(bool debug, BTreeNode<R>* node, R* record1, R* record2) {
	if ( debug ) node->print();

	if ( record2 ) {
		R* records[node->numRecords()] = node->record();
		int i = 0;
		for ( i = 0; i < node->numRecords() && i != -1; i++ ) {
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
bool BTree<R,C>::remove(R* record) {
}

template <typename R, typename C>
bool BTree<R,C>::insert(R* record) {
	if ( record ) {
		BTreeNode<R>* node = findNode(false, record, root);
		node->addRecord(record);
		char* nodedata = charstar(node);
		
		if ( strlen(nodedata) > BLOCKSIZE ) {
			if ( node->removeRecord(record) ) {
				R* records[node->numRecords()] = node->record();
				
				int half = node->numRecords() / 2;

				R* secondRecords[node->numRecords() - half];
				for ( int i = 0; i < (node->numRecords() - half); i++ )
					secondRecords[i] = records[i + half];
				
				for ( int i = 0; i < (node->numRecords() - half); i++ )
					node->removeRecord(compare.getDiscrim(records[i + half]));

				newNode(secondRecords, half, node);

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

template <typename R, typename C>
BTreeNode<R>* BTree<R,C>::newLeaf(R** records, BTreeNode<R>* node) {
	BTreeNode<R>* newnode = new BTreeLeafNode();
	for( int i = 0; i < length; i++ )
		newnode->addRecord(records[i]);
	newnode->setRight(node->right());
	newnode->setLeft(node->blockNum());
	node->setRight(newnode->blockNum());
	newnode->setBlockNum(mm.insert(charstar(newnode)) / BLOCKSIZE);
}
