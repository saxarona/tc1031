#include "LinkedList.h"
#include <iostream>

int main(){
    LinkedList mylist = LinkedList();
    mylist.push(19);
    mylist.push(25);
    mylist.push(42);
    std::cout << mylist.getSize() << std::endl;
    mylist.append(69);
    std::cout << mylist.getSize() << std::endl;
    return 0;
}
