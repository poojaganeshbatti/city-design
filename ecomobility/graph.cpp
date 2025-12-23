#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, weight;
};

int main() {
    int V, E;
    cin >> V >> E; // V = number of nodes (junctions/stops), E = number of edges
    vector<vector<Edge>> graph(V);

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w; // edge from u to v with weight w (time/distance)
        graph[u].push_back({v, w});
        // For undirected: graph[v].push_back({u,w});
    }

    // Display graph connections
    for(int i=0; i<V; i++){
        cout<<"Node "<<i<<" connects to:\n";
        for(auto &edge: graph[i]){
            cout<<"  -> "<<edge.to<<" (weight "<<edge.weight<<")\n";
        }
    }

    return 0;
}
