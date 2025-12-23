#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int V = 5;
    vector<pair<int,int>> adj[V]; // adjacency list: {neighbor, distance}

    // sample connections (u,v,distance)
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 5});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 3});
    adj[2].push_back({3, 2});
    adj[3].push_back({4, 1});

    vector<int> dist(V, INF);
    dist[0] = 0; // source = node 0
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});

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

    cout << "Shortest distances from home (0) to institutions:\n";
    for(int i=0;i<V;i++)
        cout << "Node " << i << ": " << dist[i] << endl;

    return 0;
}
