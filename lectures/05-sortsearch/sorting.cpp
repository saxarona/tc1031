#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void swapSort(vector<T> &A){
    T aux;
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

template <typename T>
void bubbleSort(vector<T> &A){
    T aux;
    bool sentinel = true;
    int n = A.size();
    int i;

    while (sentinel){
        for(i=0; i < n-1; i++){
            if(A[i] > A[i+1]){
                aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
            }
        }
        sentinel = false;

        for(i=0; i < n-1; i++){
            if(A[i] > A[i+1]){
                // not sorted
                sentinel = true;
                break;
            }
        }
    }
}

template <typename T>
void selectSort(vector<T> &A){
    int aux, pos_smallest, i, j;
    int n = A.size();

    for(i = 0; i < n-1; i++){
        pos_smallest = i;
        for(j = i+1; j < n; j++){
            if(A[pos_smallest] > A[j]){
                pos_smallest = j;
            }
        } // you now have the smallest
        if (i != pos_smallest)
        {
            aux = A[i];
            A[i] = A[pos_smallest];
            A[pos_smallest] = aux;
        }
    }
}

template <typename T>
void insertionSort(vector<T> &A){
    int aux, i, j;
    int n = A.size();

    for(i = 1; i < n; i++){ // start at 1
        j = i;
        aux = A[i];
        while(j > 0 && aux < A[j-1]){
            A[j] = A[j-1];
            j--;
        }
        A[j] = aux;
    }
}

int main(int argc, char *argv[]){
    int i;
    vector<int> A = {1, 2 ,3, 3, 0, 23, 9, 12, 7, 2, 1 , 1, 5};
    insertionSort(A);

    for (i = 0; i <= A.size()-1; i++){
        std::cout << A[i] << ' ';
    }
    return 0;
}