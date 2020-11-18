#include <vector>
#include <string>
#include <iostream>
#include "Vertex.h"
#include <algorithm>
#include <memory>
#include <list>

using namespace std;

class Graph
{
public:
    Graph(vector<string> labels);
    list<shared_ptr<Vertex>> vertices; // Container for vertices as lists of connections
    void addEdge(string u, string v);
    int getSize(){ return this->vertices.size(); }
    void DFS(string label);
    void printGraph();
};

/**
 * @brief Construct a new Graph:: Graph object
 * 
 * @param labels 
 */
Graph::Graph(vector<string> labels){
    for(const string it : labels){
        this->vertices.emplace_back(make_shared<Vertex>(it));
    }
}

void Graph::DFS(string label){
    list<shared_ptr<Vertex>>::iterator start;  // The vertex in which I'm starting the exploration

    start = find_if(this->vertices.begin(), this->vertices.end(),
                   [label](shared_ptr<Vertex> x){return x->getName() == label;});

    if (start == this->vertices.end()){
        // if not found
        cout << "There's no such label in the graph!" << endl;
    }
    else{
        list<weak_ptr<Vertex>> visited;
        list<weak_ptr<Vertex>> stack;

        stack.push_back(weak_ptr<Vertex>(*start));  // insert first into stack

        while(stack.size() > 0){
            auto current = stack.back();
            stack.pop_back();

            string current_name = current.lock()->getName();

            // if current is not in visited, add to visited
            auto in_visited = find_if(visited.begin(), visited.end(),
            [current_name](weak_ptr<Vertex> x){return x.lock()->getName() == current_name;});
            if (in_visited == visited.end()){
                visited.push_back(current); // insert first into visited
            }

            // Add its neighbourhood to the stack
            for (const auto conn : current.lock()->connections){
                auto in_visited = find_if(visited.begin(), visited.end(), 
                [conn](weak_ptr<Vertex> x){return x.lock()->getName() == conn.lock()->getName();});
                if (in_visited == visited.end()){
                    // if the connection is not in visited, add it to the stack
                    stack.push_back(conn);
                }
            }

        }
        cout << "DFS exploration starting from " << label << " is: [";
        for (weak_ptr<Vertex> visit_it : visited){
            cout << visit_it.lock()->getName() << " ";
        }
        cout << "]" << endl;
    }
}

/**
 * @brief Adds an edge between two vertices
 * 
 * @param u A string representing the label of a vertex
 * @param v A string representing the label of a vertex
 */
void Graph::addEdge(string u, string v){
    list<shared_ptr<Vertex>>::iterator pu, pv;
    pu = find_if(this->vertices.begin(), this->vertices.end(),
                    [u](shared_ptr<Vertex> x){return x->getName() == u;});
    pv = find_if(this->vertices.begin(), this->vertices.end(),
                    [v](shared_ptr<Vertex> x){return x->getName() == v;});

    if (pu == this->vertices.end() && pv == this->vertices.end()){
        // if they don't exist, add them

        this->vertices.emplace_back(make_shared<Vertex>(u));
        shared_ptr<Vertex> U = this->vertices.back();
        this->vertices.emplace_back(make_shared<Vertex>(v));
        shared_ptr<Vertex> V = this->vertices.back();

        U->addConnection(weak_ptr<Vertex>(V));
        V->addConnection(weak_ptr<Vertex>(U));

    }
    else if(pv == this->vertices.end()){
        //only pu exists, so create pv and find U
        shared_ptr<Vertex> U(*pu);  // this increases the counter of the smart pointer of the object at pu
        this->vertices.emplace_back(make_shared<Vertex>(v));
        shared_ptr<Vertex> V = this->vertices.back();

        U->addConnection(weak_ptr<Vertex>(V));
        V->addConnection(weak_ptr<Vertex>(U));
        
    }
    else if(pu == this->vertices.end()){
        //only pv exists, so add pu and find V
        shared_ptr<Vertex> V(*pv);  // this increases the counter of the smart pointer of the object at pu
        this->vertices.emplace_back(make_shared<Vertex>(u));
        shared_ptr<Vertex> U = this->vertices.back();

        U->addConnection(weak_ptr<Vertex>(V));
        V->addConnection(weak_ptr<Vertex>(U));
    }
    else{
        //both exist, so find them both
        // these two generate a normal pointer to the object at pu and pv, which is scope-dependent
        shared_ptr<Vertex> U(*pu); 
        shared_ptr<Vertex> V(*pv);

        U->addConnection(weak_ptr<Vertex>(V));
        V->addConnection(weak_ptr<Vertex>(U));
    }
}
/**
 * @brief Prints the graph by adjacency lists
 * 
 */

void Graph::printGraph(){

    for(const shared_ptr<Vertex> current : this->vertices){
        cout << current->getName() << " has the following connections: [";
        //each vertex prints its neighbors
        current->printNeighborhood();
        cout << "]" << endl;
    }
}