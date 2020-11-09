/**
 * @brief The Vertex class for a graph
 * 
 */
#include <vector>
#include <string>

using namespace std;

class Vertex
{
private:
    string label;
public:
    Vertex(string name="");
    vector<Vertex*> connections;

    void addConnection(Vertex *who);
    void getNeighborhood();
    string getName();
    bool operator==(Vertex thatguy){ return thatguy.label == this->label; }
};

/**
 * @brief Construct a new Vertex:: Vertex object
 * 
 * @param name Name of the vertex
 */
Vertex::Vertex(string name){
    this->label = name;
}


/**
 * @brief Returns the readable name of the vertex
 * 
 * @return The name given to this vertex
 */
string Vertex::getName(){
    return this->label;
}

/**
 * @brief Adds a connection from this vertex to `who`
 * 
 * @param who A pointer to another vertex
 */
void Vertex::addConnection(Vertex* who){
    this->connections.push_back(who);
}

void Vertex::getNeighborhood(){
    vector<Vertex*>::iterator it;
    for(it = this->connections.begin(); it != this->connections.end(); ++it){
        cout << (*it)->getName() << " ";
    }
}