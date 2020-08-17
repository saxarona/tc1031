#include <iostream>
#define MAX 100

using namespace std;

template <class T>
class Lista
{
private:
    T data[MAX];
    int size;
public:
    Lista();
    void insert(T element);
    void erase();
    T getData(int pos);
    int getSize();
    void print();
};

template <typename T>
Lista<T>::Lista()
{
    size = 0;
}

template <class T>
void Lista<T>::insert(T element){
    if (size < MAX){
        data[size] = element;
        size++;
    }
}
template <class T>
void Lista<T>::erase(){
    if (size > 0){
        cout << data[size-1] << "\n";
        size--;
    }
    else
    {
        cout << "No hay elementos, ni necesidad de gritar\n";
    }
    
}

template <class T>
T Lista<T>::getData(int pos){
    T retval = -1;
    if (pos > 0 && pos <= size){
        T retval = data[pos];
    }
    
    return retval;
}

template <class T>
int Lista<T>::getSize(){
    return size;
}

template <class T>
void Lista<T>::print(){
    for(int i=0; i<size; i++){
        cout << "[" << i << "] - " << data[i] << "\n";
    }
}