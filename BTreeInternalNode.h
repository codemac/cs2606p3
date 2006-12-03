#ifndef BTREEINTERNALNODE_H
#define BTREEINTERNALNODE_H

#include <iostream>
using namespace std;

template <typename R>
class BTreeInternalNode
{
    public: 
    BTreeInternalNode();
    int* pointer();
    int blockNum();
    int* key();
    int childCount();
    void addKey(int theKey);
    void addPointer(int block);
    void setBlockNum(int theBlock);
    void print();
    
    
    private:
    int* key;
    int* pointer;
    const static int SIZE = 60;
    int childcount;
    int blockNum;
};

#include BTreeInternalNodeImplementation.h

#endif //BTREEINTERNALNODE_H
