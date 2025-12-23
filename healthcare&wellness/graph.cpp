#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<pair<int,int>> *adj; // {neighbor, distance}

    Graph(int vertices) {
        V = vertices;
        adj = new vector<pair<int,int>>[V];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    void displayGraph(vector<string> &facilities) {
        for(int i=0; i<V; i++){
            cout << facilities[i] << " connected to: ";
            for(auto edge: adj[i])
                cout << facilities[edge.first] << "(" << edge.second << "km) ";
            cout << endl;
        }
    }

    ~Graph() {
        delete[] adj;
    }
};

int main() {
    vector<string> facilities = {"Hospital A", "Clinic B", "Hospital C"};
    Graph g(facilities.size());

    g.addEdge(0,1,4);
    g.addEdge(0,2,6);
    g.addEdge(1,2,3);

    g.displayGraph(facilities);
}
