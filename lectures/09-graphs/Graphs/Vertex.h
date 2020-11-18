#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <list>

using namespace std;

class Vertex
{
private:
    string label;
public:
    Vertex(string name);
    list<weak_ptr<Vertex>> connections;

    string getName(){ return this->label; };
    void addConnection(weak_ptr<Vertex> who);
    bool operator==(weak_ptr<Vertex> who) { return who.lock()->getName() == this->getName(); };

    void printNeighborhood();
};

/**
 * @brief Construct a new Vertex:: Vertex object
 * 
 * @param name 
 */
Vertex::Vertex(string name){
    this->label = name;
}

/**
 * @brief Adds who as a connection in this vertex
 * 
 * @param who A weak pointer to a Vertex object
 */
void Vertex::addConnection(weak_ptr<Vertex> who){
    this->connections.push_back(who);
}

void Vertex::printNeighborhood(){

    for(const weak_ptr<Vertex> conn : this->connections){
        cout << conn.lock()->getName() << " ";
    }
}
