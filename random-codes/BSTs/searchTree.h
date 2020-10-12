/**
 * @file searchTree.h
 * @author Sax (sax@tec.mx)
 * @brief The binary search tree container.
 * @version 0.1
 * @date 2020-10-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "treeNode.h"

class searchTree
{
private:
    treeNode *root;
    int size;
public:
    searchTree();
    ~searchTree();
    void add(int datum);
};

searchTree::searchTree(){
    this->root = nullptr;
    this->size = 0;
}

void searchTree::add(int datum){
    treeNode *pnewboy = new treeNode(datum);
    if (this->size == 0){
        this->root = pnewboy;
    }
    else{
        //What happens if we already have something?
    }
}


