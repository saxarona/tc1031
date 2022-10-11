/**
 * @file trees.cpp
 * @author Sax (mail@tec.mx)
 * @brief The trees example of my BST structure
 * @version 0.1
 * @date 2020-10-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "searchTree.h"
#include <iostream>

int main()
{
    searchTree myTree = searchTree();
    std::cout << myTree.getSize() << std::endl;
    myTree.insert(24);
    std::cout << myTree.getSize() << std::endl;
    myTree.insert(26);
    myTree.insert(20);
    myTree.printPreOrder();
    myTree.insert(15);
    myTree.printPreOrder();
    return 0;
}
