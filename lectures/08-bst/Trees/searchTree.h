/**
 * @file searchTree.h
 * @author Sax (mail@tec.mx)
 * @brief The Binary Search Tree Structure!
 * @version 0.1
 * @date 2020-10-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "treeNode.h"
#include <iostream>

class searchTree
{
private:
    treeNode* root;
    int size;
    treeNode* recursiveInsert(treeNode* where, int datum);
    void printPreOrderRecursive(treeNode* which);
public:
    searchTree();
    void insert(int datum);
    int getSize();
    void printPreOrder();
};


/**
 * @brief Construct a new search Tree::search Tree object
 * 
 */
searchTree::searchTree(){
    this->root = nullptr;
    this->size = 0;
}

/**
 * @brief User-friendly version of insertion
 * 
 * @param datum An integer value to insert into the tree
 */
void searchTree::insert(int datum){
    this->root = this->recursiveInsert(this->root, datum);
}

/**
 * @brief Inserts a Node at the correct position
 * 
 * @param where A pointer to a treeNode object in which to insert the element
 * @param datum An integer number to be inserted into the tree
 * @return treeNode* A pointer to the root (of the sublevel of insertion)
 */
treeNode* searchTree::recursiveInsert(treeNode* where, int datum){
    if (where == nullptr){
        //if there's no root
        where = new treeNode(datum);
        this->size++;
    }
    else if(datum < where->content){
        // if smaller, insert into left branch
        where->leftBoy = recursiveInsert(where->leftBoy, datum);
    }
    else if(datum > where->content){
        //if greater, insert into right branch
        where->rightBoy = recursiveInsert(where->rightBoy, datum);
    }
    else{
        //the element already exists
        std::cout << "The element already exists. Aborting insertion." << std::endl;
    }
    return where;
}

/**
 * @brief Returns the current size of the tree
 * 
 * @return int The size of the tree
 */
int searchTree::getSize(){
    return this->size;
}

/**
 * @brief User-friendly version of printing in pre-order
 * 
 */
void searchTree::printPreOrder(){
    printPreOrderRecursive(this->root);
    std::cout << std::endl;
}

/**
 * @brief Prints the tree in Pre-Order
 * 
 * @param which A pointer to a treeNode object which should be printed
 */
void searchTree::printPreOrderRecursive(treeNode* which){
    if(which != nullptr){
        //print root
        std::cout << '['<< which->content << ' ';
        //print what's on the left
        printPreOrderRecursive(which->leftBoy);
        //print what's on the right
        printPreOrderRecursive(which->rightBoy);
        std::cout << ']';
    }
}
