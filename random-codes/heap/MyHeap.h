/**
 * @file Heap.h
 * @author Sax (mail@tec.mx)
 * @brief A simple heap implementation
 * @version 0.1
 * @date 2020-10-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#define MAX_CAPACITY 255
#include  <iostream>

class MyHeap
{
private:
    int size; //Number of elements in the heap
    void swap(int a, int b);
    int contents[MAX_CAPACITY];

public:
    MyHeap();
    int getSize();
    int getLeftNodePos(int node);
    int getRightNodePos(int node);
    int getParentPos(int node);
    bool isLeaf(int node);
    void insert(int datum);
    void print();
    int pop();
};

/**
 * @brief Construct a new Heap::Heap object
 * 
 * @tparam int Type of array
 * @param cap Maximum number of elements in the heap
 */
MyHeap::MyHeap(){
    this->size = 0;
}

/**
 * @brief Returns the number of elements in the heap
 * 
 * @tparam int Type
 * @return int Size of the heap
 */
int MyHeap::getSize(){
    return this->size;
}

int MyHeap::getLeftNodePos(int node){
    return 2 * node + 1;
}

int MyHeap::getRightNodePos(int node){
    return 2 * node + 2;
}

int MyHeap::getParentPos(int node){
    return (node - 1) / 2;
}

bool MyHeap::isLeaf(int node){
    return (node >= this->size/2) && (node < this->size);
}

void MyHeap::swap(int a, int b){
    int aux = this->contents[a];
    this->contents[a] = this->contents[b];
    this->contents[b] = aux;
}

void MyHeap::insert(int datum){
    if(this->size > MAX_CAPACITY){
        std::cout << "The heap is full.";
    }
    else if(this->size == 0){
        this->contents[0] = datum;
        size++;
    }
    else{
        int current_pos = size;
        this->contents[current_pos] = datum;

        while (datum > contents[this->getParentPos(current_pos)]){
            //swap with parent
            this->swap(getParentPos(current_pos), current_pos);
            current_pos = getParentPos(current_pos);
        }
        size++;
    }
}

int MyHeap::pop(){
    if(this->size < 0){
        "The heap is empty.";
        return -1;
    }
    else{
        // swap with last
        this->swap(0, size-1);
        size--;
        int current_pos = 0;
        
        if (this->size != 0){
            // siftdown new root
            while(!isLeaf(current_pos)){
                int chosen_pos;

                if (contents[this->getLeftNodePos(current_pos)] < contents[this->getRightNodePos(current_pos)]){
                    // left is smaller
                    chosen_pos = this->getLeftNodePos(current_pos);
                }
                else{
                    //right is smaller
                    chosen_pos = this->getRightNodePos(current_pos);
                }
                if (contents[current_pos]  < contents[chosen_pos]){
                    // swap with chosen_pos
                    swap(current_pos, chosen_pos);
                    current_pos = chosen_pos;   
                }
                else{
                    break;
                }
            }
        }
        return this->contents[size];
    }
}

void MyHeap::print(){
    int i;
    for (i = 0; i < this->size; i++){
        std::cout << this->contents[i] << ' ';
    }
    std::cout << std::endl;
}