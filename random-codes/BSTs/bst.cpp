#include "searchTree.h"
#include <iostream>

int main(){
    searchTree myTree = searchTree();
    myTree.insert(10);
    std::cout << myTree.getSize() << std::endl;
    myTree.insert(15);
    std::cout << myTree.getSize() << std::endl;
    myTree.insert(12);
    std::cout << myTree.getSize() << std::endl;
    myTree.insert(8);
    std::cout << myTree.getSize() << std::endl;
    myTree.insert(16);
    std::cout << myTree.getSize() << std::endl;
    myTree.printPreOrder();
}
