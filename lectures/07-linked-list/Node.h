/**
 * @file Node.h
 * @author your name (you@domain.com)
 * @brief The node class for a linked list demo
 * @version 0.1
 * @date 2020-09-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

class Node{
public:
    int content;
    Node *nextboy; // this is a pointer!

    Node(int data);
    Node(int data, Node *next);
};

/**
 * @brief Construct a new Node:: Node object
 * 
 * @param data 
 */
Node::Node(int data){
    content = data;
    nextboy = nullptr;
}