#ifndef BTREELEAFNODE_H
#define BTREELEAFNODE_H

#include <iostream>
using namespace std;

template <typename Rec>
class BTreeLeafNode
{
    public:
    BTreeLeafNode();
    int left();
    int right();
    Rec** record();
    int blockNum();
    int numRecords();
    void addRecord(Rec* Record);
    bool removeRecord(int ID);
    void setBlockNum(int theBlock);
    void setLeft(int theLeft);
    void setRight(int theRight);
    void print();
    
    private:
    
    Rec** records;
    int leftNode;
    int rightNode;
    int blockNums;
    int numRecs;
    const static int SIZE = 60;
};

#include "BTreeLeafNodeImplementation.h"

#endif //BTREELEAFNODE_H
