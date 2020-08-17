#include "List.h"

using namespace std;

int main(){
    List myList;

    myList.insert(25);
    myList.insert(42);
    myList.insert(69);
    myList.insert(420);
    myList.erase();
    cout << "Size is " << myList.getSize() << endl;
    myList.print();

    return 0;
}