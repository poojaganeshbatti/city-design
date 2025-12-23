#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>> &adj, int source) {
    int V = adj.size();
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge: adj[u]){
            int v = edge.first;
            int w = edge.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V = 3;
    vector<vector<pair<int,int>>> adj(V);
    adj[0].push_back({1,4});
    adj[0].push_back({2,6});
    adj[1].push_back({0,4});
    adj[1].push_back({2,3});
    adj[2].push_back({0,6});
    adj[2].push_back({1,3});

    vector<int> dist = dijkstra(adj, 0);
    for(int i=0;i<V;i++)
        cout << "Distance from Residential to Facility " << i << ": " << dist[i] << " km\n";
}
