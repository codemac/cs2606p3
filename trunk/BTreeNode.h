#ifndef BTREENODE_H
#define BTREENODE_H

/**
 * This class serves as an abstract superclass to the node classes used
 * in a B+ Tree.  It contains methods that all nodes need to implement, such
 * as a print method to print out a node to cout, and an isLeaf method to 
 * determine whether a node is a leaf or internal node.
 * 
 * @author braundui @ codemac
 * 
 * @version December 6th, 2006
 */

template <typename R>
class BTreeNode {
	
	public:
    /**
     * Default constructor.
     */
    BTreeNode() {};
    
    /**
     * Destructor.
     */
    virtual ~BTreeNode() {};
    
    /**
     * This method returns the block number of the node.
     * @return int the block number.
     */
    virtual int blockNum() = 0;
    
    /**
     * This method is used to set the block number of a node
     * @param int the block number to set.
     */
    virtual void setBlockNum(int theBlock) = 0;
    
    /**
     * This method is used to determine whether or not a node is a leaf
     * or internal node.
     * @return bool true if a leaf, else false.
     */
    virtual bool isLeaf() = 0;
    
    /**
     * This method is used to print out the contents of a node, including
     * the block number, whether or not it is an internal or leaf node
     * and either key pointer pairs or records depending on the type of
     * node.
     */
    virtual void print() = 0;
    
};
#endif
