#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int distance;
};

int main() {
    int V, E;
    cin >> V >> E; // V = banks + ATMs + residential nodes, E = edges
    vector<vector<Edge>> graph(V);

    for(int i=0; i<E; i++){
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d}); // undirected
    }

    // Display connections
    for(int i=0;i<V;i++){
        cout<<"Node "<<i<<" connected to:\n";
        for(auto &e: graph[i])
            cout<<"  -> "<<e.to<<" (Distance "<<e.distance<<")\n";
    }

    return 0;
}
