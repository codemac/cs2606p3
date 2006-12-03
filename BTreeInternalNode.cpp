#include "BTreeInternalNode.h"

BTreeInternalNode::BTreeInternalNode()
{
    keys = new int[SIZE];
    pointers = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        keys[i] = -1;
        pointers[i] = -1;
    }
    childcount = 0;
    blockNums = -1;
}

int* BTreeInternalNode::pointer()
{
    return pointers;
}

int* BTreeInternalNode::key()
{
    return keys;
}

int BTreeInternalNode::blockNum()
{
    return blockNums;
}

int BTreeInternalNode::childCount()
{
    return childcount;
}

void BTreeInternalNode::addKey(int theKey)
{
    for (int i=0; i < SIZE; i++)
    {
        if(keys[i] == -1)
        {
            keys[i] = theKey;
            return;
        }
    }
}

void BTreeInternalNode::addPointer(int block)
{
    for (int i=0; i < SIZE; i++)
    {
        if(pointers[i] == -1)
        {
            pointers[i] = block;
            return;
        }
    }
}

void BTreeInternalNode::setBlockNum(int theBlock)
{
    blockNums = theBlock;
}

void BTreeInternalNode::print()
{
    cout << "Internal Node: Block " << blockNum() << " - " << childCount() << " children: ";
    for (int i = 0; i < SIZE; i++)
    {
        if (keys[i] != -1 && pointers[i] != -1)
        {
            cout << keys[i] << " " << pointers[i] << ", ";
        }
        else
        {
            return;
        }
    }
}
