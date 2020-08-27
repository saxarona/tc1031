#include <iostream>
#include <vector>

void interchange(vector<int> &A){
    int aux;
    int i, j;
    int n = A.size();

    for (i = 0; i <= n-2; i++){
        for (j = i+1; j <= n-1; j++){
            if(A[i] > A[j]){
                aux = A[i];
                A[i] = A[j];
                A[j] = aux;
            }
        }
    }
}