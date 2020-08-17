// recursive factorial

#include <cstdlib>
#include <iostream>

int factorialRecur (int n){
    // using two return values for the sake of clarity
    if (n == 1){
        return 1;
    }
    else
    {
        return n * factorialRecur(n - 1);
    }
}

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    std::cout << factorialRecur(n);
    return 0;
}