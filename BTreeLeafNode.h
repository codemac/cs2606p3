#ifndef BTREELEAFNODE_H
#define BTREELEAFNODE_H

/**
 * This class represents a leaf node to be stored at the bottom layer of
 * a B+ tree.  The node contains record objects and pointers to the nodes
 * to the left and right of it in the tree.  It also contains a method to 
 * print out it's values to cout.
 * 
 * @author braundui @ codemac
 * 
 * @version December 6th, 2006
 */

#include <iostream>
#include "BTreeNode.h"

using namespace std;

template <typename R>
class BTreeLeafNode : public BTreeNode<R>
{
    public:
    
    /**
     * Default Constructor.
     */
    BTreeLeafNode();
    
    /**
     * Destructor.
     */
	virtual ~BTreeLeafNode() {}
    
    /**
     * This method returns the block number of the leaf node to the left
     * of this one.
     * @return int the block number.  Returns -1 if there isn't one.
     */
    int left();
    
    /**
     * This method returns the block number of the leaf node to the right
     * of this one.
     * @return int the block number.  Returns -1 of there isn't one.
     */
    int right();
    
    /**
     * This method returns an array that stores the record objects held in
     * this leaf node.
     * @return R** the record array.
     */
    R** record();
    
    /**
     * This method is used to return the block number of this node so that
     * it's contents can be found in the file
     * @return int the block number
     */
    virtual int blockNum();
    
    /**
     * This method is used to return the number of records stored in this
     * leaf node.
     * @return int the number of records.
     */
    int numRecords();
    
    /**
     * This method is used to add a record to the leaf node.  The records are
     * ordered in ascending order based on their ID field.
     * @param R* a pointer to the record to be added.
     */
    void addRecord(R* Record);
    
    /**
     * This method is used to remove a record from the leaf node.
     * @param ID the ID field of the record to be removed
     * @return bool true if the remove was successful, else false.
     */
    bool removeRecord(int ID);
    
    /**
     * This method is used to set the block number of this node.
     * @param theBlock the number of the block to set.
     */
    virtual void setBlockNum(int theBlock);
    
    /**
     * This method is used to set the pointer to the block number of the 
     * leaf node to the left of this one in the tree.
     * @param theLeft the block number of the left node.
     */
    void setLeft(int theLeft);
    
    /**
     * This method is used to set the pointer to the block number of the 
     * leaf node to the right of this one in the tree.
     * @param theRight the block number of the right node.
     */
    void setRight(int theRight);
    
    /**
     * This method is used to print out the node by printing to cout first it's 
     * block number, whether or not it's a leaf node or internal node, and 
     * finally printing the ID values and length of the char* of the records
     * stored in this node.
     */
    virtual void print();
    
    /**
     * This method is used to determine whether or not this node is a leaf
     * or an internal node.  In this case, it's an leaf node.
     * @return bool true if a leaf, else false.
     */
    virtual bool isLeaf();
    
    private:
    
    R** records;  //array storing records
    int leftNode;  //pointer to the block number of the node to the left
    int rightNode;  //pointer to the block number of the node to the right
    int blockNums;  //the block number of this node
    int numRecs;   //The number of records stored in this node.
    const static int SIZE = 60;
};

#include "BTreeLeafNodeImplementation.h"

#endif //BTREELEAFNODE_H
