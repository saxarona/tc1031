/**
 * @brief A non-directed graph for my data structure class.
 * 
 */
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Vertex.h"

using namespace std;

class Graph
{
private:
    vector<Vertex> vertices;  // Container for vertices as lists of connections
public:
    Graph(vector<string> vertices);
    void addEdge(string u, string v);
    int getSize(){ return this->vertices.size(); }
    void printGraph();

};

Graph::Graph(vector<string> vertices){
    vector<string>::iterator it;

    for(it=vertices.begin(); it!=vertices.end(); it++){
        Vertex newboy = Vertex(*it);
        this->vertices.push_back(newboy);
    }
}
/**
 * @brief Adds an Edge between two vertices
 * 
 * @param u A string representing the label of a vertex
 * @param v A string representing the label of a vertex
 */
void Graph::addEdge(string u, string v){

    vector<Vertex>::iterator pu, pv;
    pu = find(this->vertices.begin(), this->vertices.end(), u);
    pv = find(this->vertices.begin(), this->vertices.end(), v);
    
    if (pu == this->vertices.end() && pv == this->vertices.end()){
        // if they don't exist, add them
        Vertex* U = new Vertex(u);
        Vertex* V = new Vertex(v);
        U->addConnection(V);
        V->addConnection(U);
        this->vertices.push_back(*U);
        this->vertices.push_back(*V);
    }
    else if(pu == this->vertices.end()){
        // only pv exists, create U and find V
        Vertex* U = new Vertex(u);
        Vertex* V = &this->vertices[pv - this->vertices.begin()];
        U->addConnection(V);
        V->addConnection(U);
        this->vertices.push_back(*U);
    }
    else if(pv == this->vertices.end()){
        // only pu exists, create V and find U
        Vertex*  U = &this->vertices[pu - this->vertices.begin()];
        Vertex* V = new Vertex(v);
        U->addConnection(V);
        V->addConnection(U);
        this->vertices.push_back(*V);
    }
    else{
        // both exist, find them
        Vertex* U = &this->vertices[pu - this->vertices.begin()];
        Vertex* V = &this->vertices[pv - this->vertices.begin()];
        U->addConnection(V);
        V->addConnection(U);
    }

    
}

void Graph::printGraph(){
    vector<Vertex>::iterator it;
    vector<Vertex*>::iterator in;

    for(it = this->vertices.begin(); it != this->vertices.end(); ++it){
        auto current = this->vertices[it - this->vertices.begin()];
        cout << current.getName() << " has the following connections: [" ;
        current.getNeighborhood();
        cout << "]" << endl;
    }
}
