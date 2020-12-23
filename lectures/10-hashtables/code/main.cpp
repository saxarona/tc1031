#include "myhashtable.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Hashtable myhashtable = Hashtable(256);

    myhashtable.insert(25);
    myhashtable.insert(77);
    std::cout << myhashtable.contains(25) << std::endl;
    std::cout << myhashtable.contains(34) << std::endl;
    myhashtable.remove(25);
    std::cout << myhashtable.contains(25) << std::endl;
    myhashtable.printTable();
    return 0;
}
