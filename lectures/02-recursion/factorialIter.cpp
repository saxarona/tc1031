// iterative factorial

#include <cstdlib>
#include <iostream>

int factorialIter (int n){
    int r = 1;
    for(int i=1; i<=n; i++){
        r *= i;
    }
    return r;
}

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    std::cout << factorialIter(n);
    return 0;
}