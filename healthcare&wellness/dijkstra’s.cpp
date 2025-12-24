#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void dijkstra(int V, int src, vector<pair<int,int>> adj[]) {
    vector<int> dist(V, INF);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Print distances
    cout << "Shortest distances from node " << src << ":\n";
    for(int i=0;i<V;i++) cout << "Node " << i << ": " << dist[i] << "\n";
}

int main() {
    int V = 5;
    vector<pair<int,int>> adj[V];
    // Example edges: {neighbor, weight}
    adj[0].push_back({1, 10});
    adj[0].push_back({2, 3});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 2});
    adj[2].push_back({1, 4});
    adj[2].push_back({3, 8});
    adj[2].push_back({4, 2});
    adj[3].push_back({4, 7});
    adj[4].push_back({3, 9});

    dijkstra(V, 0, adj);
}
