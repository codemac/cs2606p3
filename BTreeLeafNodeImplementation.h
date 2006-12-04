template <typename Rec>
BTreeLeafNode::BTreeLeafNode()
{
    records[SIZE] = 0;
    leftNode = -1;
    rightNode = -1;
    blockNums = -1;
    numRecs = 0;
}

template <typename Rec>
int BTreeLeafNode::left()
{
    return leftNode;
}

template <typename Rec>
int BTreeLeafNode::right()
{
    return rightNode;
}

template <typename Rec>
Rec** BTreeLeafNode::record()
{
    return records;
}

template <typename Rec>
int BTreeLeafNode::blockNum()
{
    return blockNums;
}

template <typename Rec>
void BTreeLeafNode::addRecord(Rec* record)
{
    Rec* tempRec = record;
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
            if(records[i]->getID() > tempRec->getID())
            {
                Rec* storeRec = records[i];
                records[i] = tempRec;
                tempRec = storeRec;
            }
        }
    }
}

template <typename Rec>
bool BTreeLeafNode::removeRecord(int ID)
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
            if(records[i]->getID() == ID)
            {
                records[i] = 0;
                numRecs-1;
                removed = true;
            }
        }
    }
    return removed;
}

template <typename Rec>
void BTreeLeafNode::numRecords()
{
    return numRecs;
}

template <typename Rec>
void BTreeLeafNode::setBlockNum(int theBlock)
{
    blockNums = theBlock;
}

template <typename Rec>
void BTreeLeafNode::setLeft(int theLeft)
{
    leftNode = theLeft;
}

template <typename Rec>
void BTreeLeafNode::setRight(int theRight)
{
    rightNode = theRight;
}

template <typename Rec>
void BTreeLeafNode::print()
{
    cout << "Leaf Node: Block " << blockNum() << " - " << numRecs() << " records: ";
    for (int i = 0; i < SIZE; i++)
    {
        if (records[i] != 0)
        {
            records[i]->dump();
            cout << ", ";
        }
    }
}