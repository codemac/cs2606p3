template <typename R>
BTreeLeafNode<R>::BTreeLeafNode()
{
    records[SIZE] = 0;
    leftNode = -1;
    rightNode = -1;
    blockNums = -1;
    numRecs = 0;
}

template <typename R>
int BTreeLeafNode<R>::left()
{
    return leftNode;
}

template <typename R>
int BTreeLeafNode<R>::right()
{
    return rightNode;
}

template <typename R>
bool BTreeLeafNode<R>::isLeaf()
{
    return true;
}

template <typename R>
R** BTreeLeafNode<R>::record()
{
    return records;
}

template <typename R>
int BTreeLeafNode<R>::blockNum()
{
    return blockNums;
}

template <typename R>
void BTreeLeafNode<R>::addRecord(R* record)
{
    R* tempRec = record;
    for (int i = 0; i < SIZE; i++)
    {
        if(records[i] == 0)
        {
            records[i] = tempRec;
            numRecs++;
            return;
        }
        else
        {
            if(records[i]->ID() > tempRec->ID())
            {
                R* storeRec = records[i];
                records[i] = tempRec;
                tempRec = storeRec;
            }
        }
    }
}

template <typename R>
bool BTreeLeafNode<R>::removeRecord(int ID)
{
    bool removed = false;
    for (int i = 0; i < SIZE; i++)
    {
        if(removed == true)
        {
            if(records[i] != 0)
            {
                records[i-1] = records[i];
                records[i] = 0;
            }
        }
        else if(records[i] != 0)
        {
            if(records[i]->ID() == ID)
            {
                records[i] = 0;
                numRecs--;
                removed = true;
            }
        }
    }
    return removed;
}

template <typename R>
int BTreeLeafNode<R>::numRecords()
{
    return numRecs;
}

template <typename R>
void BTreeLeafNode<R>::setBlockNum(int theBlock)
{
    blockNums = theBlock;
}

template <typename R>
void BTreeLeafNode<R>::setLeft(int theLeft)
{
    leftNode = theLeft;
}

template <typename R>
void BTreeLeafNode<R>::setRight(int theRight)
{
    rightNode = theRight;
}

template <typename R>
void BTreeLeafNode<R>::print()
{
    cout << "Leaf Node: Block " << blockNum() << " - " << numRecs << " records: ";
    for (int i = 0; i < SIZE; i++)
    {
        if (records[i] != 0)
        {
            records[i]->dump();
            cout << ", ";
        }
    }
}
