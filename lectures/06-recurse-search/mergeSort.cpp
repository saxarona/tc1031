#include <iostream>
#include <vector>

using namespace std;
void joinHelper(vector<int> &A, int startpoint, int midpoint, int endpoint);
void mergeSort(vector<int> &A, int startpoint, int endpoint);

void mergeSort(vector<int> &A, int startpoint, int endpoint){
    if (startpoint < endpoint){
        int mid = (startpoint + endpoint) / 2;
        mergeSort(A, startpoint, mid);
        mergeSort(A, mid+1, endpoint);
        joinHelper(A, startpoint, mid, endpoint);   
    }
}

void joinHelper(vector<int> &A, int startpoint, int midpoint, int endpoint){
    int i = startpoint;
    int k = startpoint;
    int j = midpoint + 1;
    vector<int> aux(endpoint);

    while(i <= midpoint && j <= endpoint){
        if (A[i] <= A[j]){
            aux[k] = A[i];
            k++;
            i++;
        } else{
            aux[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= midpoint){
        aux[k] = A[i];
        k++;
        i++;
    }
    while (j <= endpoint){
        aux[k] = A[j];
        k++;
        j++;
    }
    for(int z=startpoint; z < k; z++){
        A[z] = aux[z];
    }
}

int main(){
    int i;
    vector<int> X = {2, 1 ,4, 3, 25, 23, 9, 12};
    int n = X.size();
    vector<int> aux(n);
    
    mergeSort(X, 0, n-1);

    for (i = 0; i < n; i++){
        cout << X[i] << " ";
    }
    return 0;
}