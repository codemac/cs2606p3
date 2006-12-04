#include <iostream>
using namespace std;

template <typename T>
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

template <typename T>
int* BTreeInternalNode::pointer()
{
    return pointers;
}

template <typename T>
int* BTreeInternalNode::key()
{
    return keys;
}

template <typename T>
int BTreeInternalNode::blockNum()
{
    return blockNums;
}

template <typename T>
int BTreeInternalNode::childCount()
{
    return child;
}

template <typename T>
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

template <typename T>
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

template <typename T>
void BTreeInternalNode::setBlockNum(int theBlock)
{
    blockNums = theBlock;
}

template <typename T>
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
