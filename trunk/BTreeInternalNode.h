#ifndef BTREEINTERNALNODE_H
#define BTREEINTERNALNODE_H

#include "BTreeNode.h"

template <typename R>
class BTreeInternalNode : public BTreeNode<R>
{
    public: 
    BTreeInternalNode();
	virtual ~BTreeInternalNode() {}
    int* pointer();
    virtual int blockNum();
    int* key();
    int childCount();
    void addChild(int key, int block);
    bool removeChild(int ID);
    virtual void setBlockNum(int theBlock);
    virtual void print();
    virtual bool isLeaf();
    
    
    private:
    int* keys;
    int* pointers;
    const static int SIZE = 60;
    int child;
    int blockNums;
};

#include "BTreeInternalNodeImplementation.h"

#endif //BTREEINTERNALNODE_H
