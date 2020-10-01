#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList mylist = LinkedList();
    mylist.push(10);
    mylist.push(12);
    mylist.append(420);
    std::cout << mylist.getSize() << std::endl;
    std::cout << mylist.getElement(2) << std::endl;
}
