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

#endif //BTREEINTERNALNODE_H
