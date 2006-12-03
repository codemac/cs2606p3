#ifndef BTREEINTERNALNODE_H
#define BTREEINTERNALNODE_H

#include <iostream>
using namespace std;

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
    int* keys;
    int* pointers;
    const static int SIZE = 60;
    int childcount;
    int blockNums;
};

#endif //BTREEINTERNALNODE_H
