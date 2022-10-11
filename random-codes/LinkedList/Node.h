/**
 * @file Node.h
 * @author Sax (mail@tec.mx)
 * @brief This is the Node class for my Data Structures Linked List lecture!
 * @version 0.1
 * @date 2020-09-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

class Node
{
public:
    int content;
    Node *nextboy; //this is a pointer!

    Node(int data);
    ~Node();
};

/**
 * @brief Construct a new Node:: Node object
 * 
 * @param data The content of the node
 */
Node::Node(int data){
    content = data;
    nextboy = nullptr;
}