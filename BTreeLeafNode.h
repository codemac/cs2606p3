#ifndef BTREELEAFNODE_H
#define BTREELEAFNODE_H

#include <iostream>
using namespace std;

template <typename R>
class BTreeLeafNode : public BTreeNode<R>
{
    public:
    BTreeLeafNode();
    int left();
    int right();
    R** record();
    int blockNum();
    int numRecords();
    void addRecord(R* Record);
    bool removeRecord(int ID);
    void setBlockNum(int theBlock);
    void setLeft(int theLeft);
    void setRight(int theRight);
    void print();
    bool isLeaf();
    
    private:
    
    R** records;
    int leftNode;
    int rightNode;
    int blockNums;
    int numRecs;
    const static int SIZE = 60;
};

#include "BTreeLeafNodeImplementation.h"

#endif //BTREELEAFNODE_H
