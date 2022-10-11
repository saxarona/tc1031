/**
 * @file searchTree.h
 * @author Sax (mail@tec.mx)
 * @brief The binary search tree container.
 * @version 0.1
 * @date 2020-10-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "treeNode.h" 
#include <iostream>

class searchTree
{
private:
    treeNode *root;
    int size;
    treeNode* recursiveSearch(treeNode *where, int datum);
    treeNode* recursiveInsert(treeNode *where, int datum);
    void printPreOrderRecursive(treeNode *which);
public:
    searchTree();
    void insert(int datum);
    treeNode* search(int datum);
    void printPreOrder();
    int getSize();

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
 * @brief User-friendly version of recursive insertion
 * 
 * @param datum An integer to insert to the tree
 */
void searchTree::insert(int datum){
    this->root = recursiveInsert(this->root, datum);
}

/**
 * @brief Inserts a Node at the correct position
 * 
 * @param where A pointer to a treeNode object in which to insert the element
 * @param datum An integer number to be inserted into the tree
 * @return treeNode* A pointer to a root ( )
 */
treeNode* searchTree::recursiveInsert(treeNode *where, int datum){
    if (where == nullptr){
        //if there's no root
        where = new treeNode(datum);
        this->size++;
    }
    else if(datum < where->content){
        //if smaller, insert into left branch
        where->leftBoy = recursiveInsert(where->leftBoy, datum);
    }
    else if(datum > where->content){
        //if greater, insert into right branch
        where->rightBoy = recursiveInsert(where->rightBoy, datum);
    }
    else
    {
        //The element already exists
        std::cout << "The element already exists. Aborting insertion." << std::endl;
    }
    return where;
}

/**
 * @brief User-friendly version of recursive search.
 * 
 * @param datum An integer to search for inside the tree
 * @return treeNode* 
 */
treeNode* searchTree::search(int datum){
    return recursiveSearch(this->root, datum);
}

/**
 * @brief Searches recursively throughout the tree structure
 * 
 * @param where A pointer to a treeNode object: the haystack
 * @param datum An integer which is being searched: the needle
 * @return treenode* A pointer to a treeNode object containing the found needle!
 */
treeNode* searchTree::recursiveSearch(treeNode *where, int datum){
    if(where == nullptr){
        return nullptr;
    }
    else if(datum < where->content){
        //search left
        recursiveSearch(where->leftBoy, datum);
    }
    else if(datum > where->content){
        //search right
        recursiveSearch(where->rightBoy, datum);
    }
    else{
        //found it
        return where;
    }
}

/**
 * @brief User-friendly version of In-Order printing
 * 
 */
void searchTree::printPreOrder(){
    printPreOrderRecursive(this->root);
}

/**
 * @brief Printing the tree In-Order
 * 
 * @param which A pointer to a treeNode object which should be printed
 */
void searchTree::printPreOrderRecursive(treeNode* which){
    if(which != nullptr){
        //print root
        std::cout << '[' << which->content << ' ';
        //print left
        printPreOrderRecursive(which->leftBoy);
        //print right
        printPreOrderRecursive(which->rightBoy);
        std::cout << ']';
    }
    else{
        std::cout << "[]";
    }
    
}

int searchTree::getSize(){
    return this->size;
}
