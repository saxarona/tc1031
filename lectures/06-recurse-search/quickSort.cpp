#include <iostream>
#include <vector>

void mysplit(std::vector<int> &A, int startpoint, int endpoint, int &pivot);
void quickSort(std::vector<int> &A, int startpoint, int endpoint);

void quickSort(std::vector<int> &A, int startpoint, int endpoint){
    int pivot;

    if(startpoint < endpoint){
        mysplit(A, startpoint, endpoint, pivot);
        quickSort(A, startpoint, pivot-1);
        quickSort(A, pivot+1, endpoint);
    }
}

void mysplit(std::vector<int> &A, int startpoint, int endpoint, int &pivot){
    int pivot_value = A[startpoint];
    int j = startpoint;
    int i, aux;

    for(i=startpoint+1; i <= endpoint; i++){
        if(A[i] < pivot_value){
            //go left
            j++;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }

    pivot = j;
    aux = A[startpoint];
    A[startpoint] = A[pivot];
    A[pivot] = aux;
}


int main(){
    int i;
    std::vector<int> X = {2, 1, 4, 3, 8, 7, 2, 10};
    int n = X.size();
    
    quickSort(X, 0, n-1);

    for (i = 0; i < n; i++){
        std::cout << X[i] << " ";
    }
    return 0;
}