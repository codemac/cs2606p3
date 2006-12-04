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
    child = 0;
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
    return child;
}

void BTreeInternalNode::addChild(int theKey, int block)
{
    int tempKey = theKey;
    int tempBlock = block;
    for (int i=0; i < SIZE; i++)
    {
        if(keys[i] == -1)
        {
            keys[i] = theKey;
            pointers[i] = block;
            child++;
            return;
        }
        else
        {
            if(keys[i] > tempKey)
            {
                int storeKey = keys[i];
                int storeBlock = pointers[i];
                keys[i] = tempKey;
                pointers[i] = tempBlock;
                tempKey = storeKey;
                tempBlock = storeBlock;
            }
        }
    }
}

bool BTreeInternalNode::removeChild(int ID)
{
    bool removed = false;
    for (int i = 0; i < SIZE; i++)
    {
        if(removed == true)
        {
            if(keys[i] != -1)
            {
                keys[i-1] = keys[i];
                pointers[i-1] = pointers[i];
                keys[i] = -1;
                pointers[i] = -1;
            }
        }
        else if(keys[i] != -1)
        {
            if(keys[i] == ID)
            {
                keys[i] = -1;
                pointers[i] = -1;
                child--;
                removed = true;
            }
        }
    }
    return removed;
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
