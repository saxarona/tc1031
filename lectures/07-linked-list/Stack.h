#include "Node.h"

class Stack
{
private:
    /* data */
    Node *top;
    int size;
    
public:
    Stack();
    void push(int datum);
    int pop();
    int getSize();
};

Stack::Stack(){
    top = nullptr;
    size = 0;
}

/**
 * @brief Inserts an element atop the stack
 * 
 * @param datum An integer to be inserted on top of the stack
 */
void Stack::push(int datum){
    Node *pnewboy = new Node(datum);
    pnewboy->nextboy = top;
    top = pnewboy;
    size++;
}
/**
 * @brief Pops element atop the stack
 * 
 * @return int An integer value which was atop the stack
 */
int Stack::pop(){
    Node *premovedboy = top;
    int data = top->content;

    top = premovedboy->nextboy;
    delete premovedboy;
    size--;
    return data;
}

/**
 * @brief Gets size of the stack
 * 
 * @return int The size of the stack
 */
int Stack::getSize(){
    return size;
}
