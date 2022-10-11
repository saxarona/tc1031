/**
 * @file myhashtable.h
 * @author Sax (mail@tec.mx)
 * @brief A small hashtable to experiment
 * @version 0.1
 * @date 2020-11-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <list>
#include <iostream>

class Hashtable
{
private:
    std::list<int> *thedata;
    int encode(int val);
    int n_buckets;
public:
    Hashtable(int n_elements);
    void insert(int val);
    void remove(int val);
    bool contains(int val);
    void printTable();
};

/**
 * @brief Construct a new Hashtable:: Hashtable object
 * 
 */
Hashtable::Hashtable(int n_elements){
    this->thedata = new std::list<int>[n_elements];
    this->n_buckets = n_elements;
}

/**
 * @brief Hash function for encoding entries
 * 
 * @param val Value to encode
 * @return int Value to return after encoding!
 */
int Hashtable::encode(int val){
    return val % 257;
}

/**
 * @brief Inserts a value into the hashtable
 * 
 * @param val Value to insert
 */
void Hashtable::insert(int val) {
    int where = encode(val);
    this->thedata[where].push_back(val);
}

/**
 * @brief Removes value from hashtable
 * 
 * @param val 
 */
void Hashtable::remove(int val){
    int where = encode(val);
    std::list<int>::iterator it;
    for (it = this->thedata[where].begin(); it != this->thedata[where].end(); it++){
        if (*it == val){
            // we already know the position
            break;
        }
    }

    if (it != this->thedata[where].end()){
        // if found, then erase `it`
        this->thedata[where].erase(it);
    }
}

bool Hashtable::contains(int val){
    int where = encode(val);
    bool exists = false;

    std::list<int>::iterator it;
    //We search for it at the given position
    for (it = this->thedata[where].begin(); it != this->thedata[where].end(); it++){
        if (*it == val){
            // we found it at position `it`
            exists = true;
            break;
        }
    }
    return exists;
}

/**
 * @brief Prints the whole hashtable
 * 
 */
void Hashtable::printTable(){
    int bu;
    for (bu = 0; bu < this->n_buckets; bu++){
        std::cout << bu << ": [ ";
        for (const auto eachval : this->thedata[bu]){
            std::cout << eachval << " ";
        }
        std::cout << "]" << std::endl;
    }
}
