/**
 * @file treeNode.h
 * @author Sax (sax@tec.mx)
 * @brief The BST basic node
 * @version 0.1
 * @date 2020-10-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

class treeNode
{
private:
    /* data */
    int content;
    treeNode *leftBoy;
    treeNode *rightBoy;
public:
    treeNode(int datum);
    ~treeNode();
};

treeNode::treeNode(int datum){
    this->content = datum;
    this->leftBoy = nullptr;
    this->rightBoy = nullptr;
}
