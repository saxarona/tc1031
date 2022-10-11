/**
 * @file LinkedList.h
 * @author Sax (mail@tec.mx)
 * @brief The linked list class for my data structures lecture on linked lists!
 * @version 0.1
 * @date 2020-09-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Node.h"

class LinkedList
{
private:
    Node *head;
    int size;

public:
    LinkedList();
    void append(int datum);
    void push(int datum);
    int getSize();
};

/**
 * @brief Construct a new Linked List:: Linked List object
 * 
 */
LinkedList::LinkedList(){
    head = nullptr;
    size = 0;
}

/**
 * @brief Adds a new node at the end of the list
 * 
 * @param datum The element to be appended
 */
void LinkedList::append(int datum){
    Node *pnewboy = new Node(datum);
    Node *pcurrentboy;
    pcurrentboy = head;
    if (head == nullptr){ //if the list empty
        head = pnewboy;
    }
    else{
        while (pcurrentboy->nextboy != nullptr){
            pcurrentboy = pcurrentboy->nextboy;
        }
        pcurrentboy->nextboy = pnewboy;
    }
    size++;
}

/**
 * @brief Adds an element to the start of the list
 * 
 * @param datum The element which will be added
 */
void LinkedList::push(int datum){
    Node *pnewboy = new Node(datum);
    pnewboy->nextboy = head;
    head = pnewboy;
    size++;
}

/**
 * @brief Gets the size of the list
 * 
 * @return int Size of the list
 */
int LinkedList::getSize(){
    return size;
}


