#include "Node.h"

class LinkedList{
private:
    Node *head;
    int size;
public:
    LinkedList();
    void append(int datum);
    void push(int datum);
    int getSize();
    int getElement(int pos);

};

LinkedList::LinkedList(){
    head = nullptr;
    size = 0;
}


/**
 * @brief Adds new node at the end of the list
 * 
 * @param datum 
 */
void LinkedList::append(int datum){
    Node *pnewboy = new Node(datum);
    Node *pcurrentboy;
    pcurrentboy = head;
    if (head == nullptr){ //if the list is empty
        head = pnewboy;
    }
    else{
        while(pcurrentboy->nextboy != nullptr){
            pcurrentboy = pcurrentboy->nextboy;
        }
        pcurrentboy->nextboy = pnewboy;
    }
    size++;
}

/**
 * @brief Adds a node to the beginning of the list
 * 
 * @param datum 
 */
void LinkedList::push(int datum){
    Node *pnewboy = new Node(datum);
    pnewboy->nextboy = head;
    head = pnewboy;
    size++;
}

int LinkedList::getSize(){
    return size;
}

int LinkedList::getElement(int pos){
    if(pos <= size){
        Node *pcurrentboy = head;
        for (int i = 0;i < pos;i++){
            pcurrentboy = pcurrentboy->nextboy;
        }
        return pcurrentboy->content;
    }
    else{
        return -1;
    }
}