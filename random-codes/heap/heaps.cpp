#include "MyHeap.h"

int main(){
    MyHeap myHeap = MyHeap();
    myHeap.insert(10);
    myHeap.insert(12);
    myHeap.insert(28);
    myHeap.print();
    std::cout<< myHeap.pop() << std::endl;
    myHeap.print();
    myHeap.pop();
    myHeap.insert(15);
    myHeap.insert(24);
    myHeap.insert(220);
    myHeap.insert(7);
    myHeap.print();
    return 0;
}
