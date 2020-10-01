#include <iostream>
#include "Stack.h"

int main()
{
    Stack mystack = Stack();
    mystack.push(10);
    mystack.push(15);
    mystack.push(12);
    std::cout << mystack.pop() << std::endl;
    std::cout << "Size is " << mystack.getSize() << std::endl;
    mystack.push(420);
    std::cout << mystack.pop() << std::endl;
    std::cout << mystack.pop() << std::endl;
    std::cout << "Size is " << mystack.getSize() << std::endl;

}
