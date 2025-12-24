#include <bits/stdc++.h>
using namespace std;

void BFS(int start, vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "Healthcare coverage area from hospital " << start << ": ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 6;
    vector<vector<int>> graph(V);

    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {2, 5};
    graph[5] = {4};

    BFS(0, graph, V);
    return 0;
}
