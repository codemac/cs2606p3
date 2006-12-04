#ifndef BTREEINTERNALNODE_H
#define BTREEINTERNALNODE_H

template <typename T>
class BTreeInternalNode : BTreeNode<T>
{
    public: 
    BTreeInternalNode();
    int* pointer();
    int blockNum();
    int* key();
    int childCount();
    void addChild(int key, int block);
    bool removeChild(int ID);
    void setBlockNum(int theBlock);
    void print();
    
    
    private:
    int* keys;
    int* pointers;
    const static int SIZE = 60;
    int child;
    int blockNums;
};

#include "BTreeInternalNodeImplementation.h"

#endif //BTREEINTERNALNODE_H
