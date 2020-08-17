#define MAX 100
#include <iostream>

using namespace std;

class List
{
private:
    /* data */
    int data[MAX];
    int size;
public:
    List();
    // insert
    void insert(int element);
    // erase
    void erase();
    // getData
    int getData(int pos);
    // getSize
    int getSize();
    // print
    void print();
};

List::List()
{
    size = 0;
}

void List::insert(int element){
    if (size < MAX){
        data[size] = element;
        size++;
    }
}

void List::erase(){
    if (size > 0){
        cout << data[size-1] << endl;
        size--;
    }
    else
    {
        cout << "There's no elements in here" << endl;
    }
}

int List::getData(int pos){
    int retval = -1;
    if (pos > 0 && pos <= size){
        retval = data[pos];
    }
    return retval;
}

int List::getSize(){
    return size;
}

void List::print(){
    for(int i=0; i<size; i++){
        cout << "[" << i << "] - " << data[i] << endl;
    }
}
