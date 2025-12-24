#include <bits/stdc++.h>
using namespace std;

void dijkstra(int src, vector<vector<pair<int,int>>>& graph, int V) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Fastest time to hospitals:\n";
    for (int i = 0; i < V; i++)
        cout << "Hospital " << i << " : " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> graph(V);

    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[2].push_back({1, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});

    dijkstra(0, graph, V);
    return 0;
}

