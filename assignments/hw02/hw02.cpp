#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &A){
    int aux;
    int misplacements = 1;

    while (misplacements > 0){
        for (int i=0; i < A.size()-1; i++){
            if (A[i] > A[i+1]){
                aux = A[i+1];
                A[i+1] = A[i];
                A[i] = aux;
            }
        }

        // check if sorted by counting misplacements
        misplacements = 0;
        for (int i=0; i < A.size()-1; i++){
            if (A[i] > A[i+1]){
                //not sorted
                misplacements++;
            }
        }   
    }
}

int main(int argc, char *argv[]){
    vector<int> X = {1, 3, 10, 2, 7, 9, 15, 2, 1};
    bubbleSort(X);
    for (vector<int>::iterator it = X.begin(); it != X.end(); it++){
        cout << *it << " ";
    }
    
    return 0;
}