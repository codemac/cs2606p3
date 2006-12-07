#ifndef BTREEINTERNALNODE_H
#define BTREEINTERNALNODE_H

/**
 * This class represents an internal node to be stored in a B+ tree.  This
 * node contains a list of key values and pointers that represent the ID's
 * and block numbers of child nodes to be stored under this one in the
 * tree structure.  This class also contains a method to print out the
 * list of key values and pointers to cout
 * 
 * @author braundui @ codemac
 * 
 * @version December 6th, 2006
 */

#include <iostream>
#include "BTreeNode.h"

template <typename R>
class BTreeInternalNode : public BTreeNode<R>
{
    public:
    /**
     * Default constructor.
     */
    BTreeInternalNode();
    
    /**
     * Destructor.
     */
	virtual ~BTreeInternalNode() {}
    
    /**
     * this method is used to return an array of the block numbers
     * of the child nodes to this node.
     * @return int* the array
     */
    int* pointer();
    
    /**
     * This method is used to return the block number of this node so that
     * it's contents can be found in the file
     * @return int the block number
     */
    virtual int blockNum();
    
    /**
     * This method is used to return an array of the key values of the child
     * nodes to this node.
     * @return int* the array
     */
    int* key();
    
    /**
     * This method is used to return a count of the number of children
     * that this node currently has.
     * @return int the number of children
     */
    int childCount();
    
    /**
     * This method is used to add a child to the node by adding a key value
     * that represents the ID of the child and a block number of the child
     * so that it's contents can be accessed.  The values are ordered in
     * ascending order.
     * @param key the key value or ID
     * @param block the child's block number
     */
    void addChild(int key, int block);
    
    /**
     * This method is used to remove a child from the list of children
     * stored in this node by removing it's key value and block number
     * @param ID the key value of the child to remove
     * @return bool true if successful, else false.
     */
    bool removeChild(int ID);
    
    /**
     * This method is used to set the block number of this node.
     * @param theBlock the number of the block to set.
     */
    virtual void setBlockNum(int theBlock);
    
    /**
     * This method is used to print out the node by printing to cout first it's 
     * block number, whether or not it's a leaf node or internal node, and 
     * finally printing the array of key values and block numbers representing 
     * it's children.
     */
    virtual void print();
    
    /**
     * This method is used to determine whether or not this node is a leaf
     * or an internal node.  In this case, it's an internal node.
     * @return bool true if a leaf, else false.
     */
    virtual bool isLeaf();
    
    
    private:
    int* keys;   // array stores key values
    int* pointers;  // array stores block numbers of children
    const static int SIZE = 60;
    int child;  //counts the number of children
    int blockNums;  //the block number of this node.
};

#include "BTreeInternalNodeImplementation.h"

#endif //BTREEINTERNALNODE_H
