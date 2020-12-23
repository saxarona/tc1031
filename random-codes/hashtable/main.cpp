#include "Hash.h"
#include <iostream>

main(){
    Hash myh = Hash(256);

    myh.insert(25);
    myh.insert(57);
    myh.insert(34);
    myh.insert(780);

    std::cout << myh.contains(280) << std::endl;
    std::cout << myh.contains(34) << std::endl;

    myh.printTable();
    return 0;
}