#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void bubbleSort(vector<string> &A){
    string aux;
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

    ifstream log("bitacora.txt", ios::binary);
    vector<string> contents;
    string singleLine;
    while (getline(log, singleLine)){
        contents.push_back(singleLine);
    }

    cout << contents.size() << " lines read to memory\n";

    log.close();


    bubbleSort(contents);

    ofstream sorted("sorted.txt", ios::binary);
    for (vector<string>::iterator it = contents.begin(); it != contents.end(); it++){
        sorted << *it << "\n";
    }
    sorted.close();
    
    return 0;
}