#include "Graph.h"
#include <vector>
#include <string>

using namespace std;

main(){
    vector<string> V = { };
    Graph graph = Graph(V);
    graph.addEdge("A", "B");
    graph.addEdge("B", "D");
    graph.addEdge("C", "A");
    graph.addEdge("C", "D");
    graph.addEdge("E", "D");
    graph.addEdge("C", "E");
    graph.addEdge("D", "F");
    graph.addEdge("D", "G");

    graph.printGraph();

    cout << "---" << endl;

    cout << "Graph has " << graph.getSize() << " nodes." << endl;

    graph.DFS("A");

    return 0;
}