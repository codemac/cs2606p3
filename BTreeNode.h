#ifndef BTREENODE_H
#define BTREENODE_H

//	For internal nodes:
//
//	they need to store:
//		Array of key/pointer pairs. 
//		Pointer is the block of the child node. 
//		Flag if internal node.
//		Block number.
//		How many children.
//
//	for each leaf node:
//

template <typename R>
class BTreeNode {
	private:
	public:
    void Print();
    
};
#endif
