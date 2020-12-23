#include <list>
#include <iostream>

class Hash
{
private:
    std::list<int> *thedata;
    int encode(int val);
    int n_buckets;
public:
    Hash(int n_elements);
    void insert(int val);
    void remove(int val);
    bool contains(int val);
    void printTable();
};

Hash::Hash(int n_elements){
    this->n_buckets = n_elements;
    this->thedata = new std::list<int>[n_elements];
}

int Hash::encode(int val){
    return val % 257;
}

void Hash::insert(int val){
    int where = encode(val);
    this->thedata[where].push_back(val);
}

bool Hash::contains(int val){
    int where = encode(val);
    bool exists = false;

    for (const int eachval : this->thedata[where]){
        if(eachval == val){
            //found it
            exists = true;
            break;
        }
    }
    return exists;
}

void Hash::printTable(){
    int bu;
    for(bu =0; bu < this->n_buckets; bu++){
        std::cout << bu << ": [";
        for(const int eachval : this->thedata[bu]){
            std::cout << eachval << " ";
        }
        std::cout << "]" << std::endl;
    }
}