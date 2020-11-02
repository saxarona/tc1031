/**
 * @file treeNode.h
 * @author Sax (sax@tec.mx)
 * @brief The basic node structure of my Binary Search Tree
 * @version 0.1
 * @date 2020-10-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

class treeNode
{

public:
    int content;
    treeNode *leftBoy;
    treeNode *rightBoy;
    treeNode(int datum);
};

/**
 * @brief Construct a new tree Node::tree Node object
 * 
 * @param datum An integer value which is its content
 */
treeNode::treeNode(int datum){
    this->content = datum;
    this->leftBoy = nullptr;
    this->rightBoy = nullptr;
}