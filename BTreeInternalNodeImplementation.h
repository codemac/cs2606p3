template <typename R>
BTreeInternalNode::BTreeInternalNode()
{
    key = new int[SIZE];
    pointer = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        key[i] = -1;
        pointer[i] = -1;
    }
    childcount = 0;
    blockNum = -1;
}

template <typename R>
int* BTreeInternalNode::pointer()
{
    return pointer;
}

template <typename R>
int* BTreeInternalNode::key()
{
    return key;
}

template <typename R>
int BTreeInternalNode::blockNum()
{
    return blockNum;
}

template <typename R>
int BTreeInternalNode::childCount()
{
    return childcount;
}

template <typename R>
void BTreeInternalNode::addKey(int theKey)
{
    for (int i=0; i < SIZE; i++)
    {
        if(key[i] == -1)
        {
            key[i] = theKey;
            return;
        }
    }
}

template <typename R>
void BTreeInternalNode::addPointer(int block)
{
    for (int i=0; i < SIZE; i++)
    {
        if(pointer[i] == -1)
        {
            pointer[i] = block;
            return;
        }
    }
}

template <typename R>
void BTreeInternalNode::setBlockNum(int theBlock)
{
    blockNum = theBlock;
}

template <typename R>
void BTreeInternalNode::print()
{
    cout << "Internal Node: Block " << blockNum() << " - " << childCount() << " children: ";
    for (int i = 0; i < SIZE; i++)
    {
        if (key[i] != -1 && pointer[i] != -1)
        {
            cout << key[i] << " " << pointer[i] << ", ";
        }
        else
        {
            return;
        }
    }
}