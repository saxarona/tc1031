/**
 * @file hw01.cpp
 * @author Sax (sax@tec.mx)
 * @brief Solution of first HW.
 * @version 0.1
 * @date 2020-08-19
 * 
 * @copyright Meh (c) 2020
 * 
 */

#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * @brief Iterative Sum of 1 to n
 * 
 * @param n 
 * @return int 
 */
int iterativeSum(int n){
    int sum = 0;
    for(int i=1; i <= n; i++){
        sum += i;
    }
    return sum;
}

/**
 * @brief Recursive sum from n to 1
 * 
 * @param n 
 * @return int 
 */
int recursiveSum(int n){
    if (n == 1){
        return 1;
    }
    else{
        return n + recursiveSum(n-1);
    }
}

/**
 * @brief Direct sum using algebraic equivalence
 * 
 * @param n 
 * @return int 
 */
int algebraicSum(int n){
    return n * (n+1) / 2;
}

/**
 * @brief The main function call
 * 
 * @param argc argument count
 * @param argv This is the array of arguments
 * @return int The exit code status
 */
int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int it, rec, alg = 0;

    it = iterativeSum(n);
    rec = recursiveSum(n);
    alg = algebraicSum(n);

    cout << "Sum is \n";
    cout << it  << " by iterative sum \n";
    cout << rec << " by recursive sum \n";
    cout << alg << " by algebraic sum";

    return 0;
}