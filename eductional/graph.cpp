#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    void displayGraph() {
        for(int i=0; i<V; i++){
            cout << "Institution " << i << " connected to: ";
            for(int j: adj[i])
                cout << j << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.displayGraph();
    return 0;
}
