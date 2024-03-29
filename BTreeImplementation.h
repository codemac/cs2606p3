#include "BTree.h"

template <typename R, typename C>
BTree<R,C>::BTree()
{
    root = NULL;
}

template <typename R, typename C>
BTree<R,C>::~BTree()
{
}

template <typename R, typename C>
void BTree<R,C>::init(char* fileLocation, int numBuffers)
{
    mm.init(fileLocation, numBuffers);
}

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
		BTreeInternalNode<R>* r = dynamic_cast<BTreeInternalNode<R>*>(root);
		//	do the children thing
		int* child = r->pointer();
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
BTreeNode<R>* BTree<R,C>::findNode(bool debug, R* record, BTreeNode<R>* root) {
    if ( root ) 
    {
		if ( debug ) 
        { 
            root->print(); 
        }
		if ( root->isLeaf() ) 
        {
			return root;
		} 
        else if ( record ) 
        {
			int* key = dynamic_cast<BTreeInternalNode<R>*>(root)->key();
			int* pointer = dynamic_cast<BTreeInternalNode<R>*>(root)->pointer();

			for ( int i = 0; key[i] != -1; i++) 
            {
				if ( key[i] > compare.getDiscrim(record) )
                {
					findNode(debug,record,makeNode(pointer[i-1]));
                }
			}
		} 
        else 
        {
			return 0;
		}
	} 
    else 
    {
		return 0;
	}
	return 0;
}

template <typename R, typename C>
BTreeNode<R>* BTree<R,C>::findParent(BTreeNode<R>* node, BTreeNode<R>* rot) {
	if ( !rot->isLeaf() ) {
		BTreeInternalNode<R>* root = dynamic_cast<BTreeInternalNode<R>*>(rot);
		int* pointer = root->pointer();
		for ( int i = 0; i < root->childCount(); i++ ) {
			if ( pointer[i] == node->blockNum() )
				return root;
		}
		for ( int i = 0; i < root->childCount(); i++ ) {
			findParent(node, makeNode(pointer[i]));
		}
	} else {
			return 0;
	}
    return 0;
}


template <typename R, typename C>
void BTree<R,C>::printSearch(bool debug, BTreeNode<R>* node, R* record1, R* record2) {
	if ( debug ) node->print();

	if ( ! node->isLeaf() ) return;

	if ( record2 ) {
		BTreeLeafNode<R>* nod = dynamic_cast<BTreeLeafNode<R>*>(node);
		R** records = nod->record();
		int i = 0;
		for ( i = 0; i < nod->numRecords() && i != -1; i++ ) {
			if ( compare.equal(records[i], record1) ||
					( compare.lt(records[i], record2) ||
					  compare.equal(records[i], record2) ) )
            {
				records[i]->print();
            }
			else
            {
				i = -1;
            }
		}
		if (i != -1 && nod->right() != -1) {
			printSearch(debug, makeNode(nod->right()), record1, record2);
		}
	}
}

template <typename R, typename C>
bool BTree<R,C>::remove(R* record) {
    return true;
}

template <typename R, typename C>
bool BTree<R,C>::insert(R* record) {
	if ( record ) 
    {
        if (root == NULL)
        {
            root = new BTreeLeafNode<R>();
            int blockNum = mm.freeList();
            dynamic_cast<BTreeLeafNode<R>*>(root)->setBlockNum(blockNum);
        }
		BTreeLeafNode<R>* node = dynamic_cast<BTreeLeafNode<R>*>(findNode(false, record, root));
        R** rec = dynamic_cast<BTreeLeafNode<R>*>(node)->record();
        for(int i = 0; i < dynamic_cast<BTreeLeafNode<R>*>(node)->numRecords(); i++)
        {
            if(rec[i]->ID() == record->ID())
            {
                return false;
            }
        }
        node->addRecord(record);

		char* nodedata = charstar(node);
		
		if ( strlen(nodedata) > BLOCKSIZE ) 
        {
			if ( node->removeRecord(compare.getDiscrim(record)) ) 
            {
				R** records = node->record();
				
				int half = node->numRecords() / 2;

				R* secondRecords[node->numRecords() - half];
				for ( int i = 0; i < (node->numRecords() - half); i++ )
					secondRecords[i] = records[i + half];
				
				for ( int i = 0; i < (node->numRecords() - half); i++ )
					node->removeRecord(compare.getDiscrim(records[i + half]));

				//BTreeNode<R>* newnode = newLeaf(secondRecords, half, node);
				//BTreeNode<R>* parent = findParent(newnode, root);
			} 
            else 
            {
				return false;
			}
		} 
        else 
        {
			return true;
		}
	} 
    else 
    {
		return false;
	}
	return false;
}

template <typename R, typename C>
BTreeNode<R>* BTree<R,C>::newLeaf(R** records,int length,  BTreeNode<R>* node) {
	BTreeLeafNode<R>* newnode = new BTreeLeafNode<R>();
	for( int i = 0; i < length; i++ )
		newnode->addRecord(records[i]);
	newnode->setRight(dynamic_cast<BTreeLeafNode<R>*>(node)->right());
	newnode->setLeft(node->blockNum());
	dynamic_cast<BTreeLeafNode<R>*>(node)->setRight(newnode->blockNum());

	newnode->setBlockNum(mm.freeList() / BLOCKSIZE);
	mm.insert(newnode->blockNum()*BLOCKSIZE,charstar(newnode));
	return dynamic_cast<BTreeNode<R>*>(newnode);
}

template <typename R, typename C>
BTreeNode<R>* BTree<R,C>::makeNode( int fileOffset ) {
	char* node = mm.get(fileOffset * BLOCKSIZE);
	char isleaf[] = "n";
	int offset = 0;

	memcpy(isleaf, node+offset, strlen(isleaf)+1);
	offset += strlen(isleaf)+1;
	
	if ( isleaf == "y" ) {
		BTreeLeafNode<R>* result = new BTreeLeafNode<R>();
		int next = 0;
		memcpy(&next, node+offset, sizeof(int));
		offset += sizeof(int);
		result->setLeft(next);
		
		memcpy(&next, node+offset, sizeof(int));
		offset += sizeof(int);
		result->setRight(next);

		memcpy(&next, node+offset, sizeof(int));
		offset += sizeof(int);
		result->setBlockNum(next);

		int numrecord = 0;
		memcpy(&numrecord, node+offset, sizeof(int));
		offset += sizeof(int);
		
		for ( int i = 0; i < numrecord; i++ )
		{
			R* nrec = new R();
			memcpy(&next, node+offset, sizeof(int));
			offset+=sizeof(int);
			nrec->length(next);
			memcpy(&next, node+offset, sizeof(int));
			offset+=sizeof(int);
			nrec->cost(next);
			memcpy(&next, node+offset, sizeof(int));
			offset+=sizeof(int);
			nrec->ID(next);
			char* nexts = new char[512];
			strcpy(nexts, node+offset);
			offset += strlen(nexts)+1;
			nrec->title(string(nexts));
			strcpy(nexts, node+offset);
			offset += strlen(nexts)+1;
			nrec->date(string(nexts));

			result->addRecord(nrec);
		}
		return dynamic_cast<BTreeNode<R>*>(result);
	} else {
		BTreeInternalNode<R>* result = new BTreeInternalNode<R>();
		int next = 0;
		
		memcpy(&next, node+offset, sizeof(int));
		offset += sizeof(int);
		result->setBlockNum(next);
		
		memcpy(&next, node+offset, sizeof(int));
		offset += sizeof(int);

		for ( int i = 0; i < next; i++ ) {
			int key = 0;
			int pointer = 0;

			memcpy(&key, node+offset, sizeof(int));
			offset += sizeof(int);
			memcpy(&pointer, node+offset, sizeof(int));
			offset += sizeof(int);

			result->addChild(key,pointer);
		}
		return dynamic_cast<BTreeNode<R>*>(result);
	}
	return 0;
}

template <typename R, typename C>
char* BTree<R,C>::charstar(BTreeNode<R>* nod) {
	char* final = new char[512];
	memset(final, ' ', 512);
	if ( nod->isLeaf() ) {
		BTreeLeafNode<R>* node = dynamic_cast<BTreeLeafNode<R>*>(nod);
		char isleaf[] = "y";
		int lefty = node->left();
		int righty = node->right();
		int block = node->blockNum();
		int numrecord = node->numRecords();
		int offset = 0;
		
		memcpy(final+offset, isleaf, strlen(isleaf)+1);
		offset += strlen(isleaf)+1;
		memcpy(final+offset, &lefty, sizeof(int));
		offset += sizeof(int);
		memcpy(final+offset, &righty, sizeof(int));
		offset += sizeof(int);
		memcpy(final+offset, &block, sizeof(int));
		offset += sizeof(int);
		memcpy(final+offset, &numrecord, sizeof(int));
		offset += sizeof(int);
		
		R** records = node->record();

		for( int i = 0; i < numrecord; i++ ) {
			memcpy(final+offset, records[i]->charstar(), records[i]->dumpLength());
		}
		
		return final;
	} else {
		BTreeInternalNode<R>* node = dynamic_cast<BTreeInternalNode<R>*>(nod);
		int offset = 0;
		char isleaf[] = "n";
		int block = node->blockNum();
		int childs = node->childCount();
		
		memcpy(final+offset, isleaf, strlen(isleaf)+1);
		offset += strlen(isleaf)+1;
		memcpy(final+offset, &block, sizeof(int));
		offset += sizeof(int);
		memcpy(final+offset, &childs, sizeof(int));
		offset += sizeof(int);

		int* pointers = node->pointer();
		int* keys = node->key();
		for ( int i = 0; i < childs; i++ ) {
			memcpy(final+offset, &keys[i], sizeof(int));
			offset+=sizeof(int);
			memcpy(final+offset, &pointers[i], sizeof(int));
			offset+=sizeof(int);
		}

		return final;
	}
}
