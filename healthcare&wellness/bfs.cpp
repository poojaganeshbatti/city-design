#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<int> adj[], int V){
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front(); q.pop();
        cout << node << " "; // visiting node
        for(int neighbor: adj[node]){
            if(!visited[neighbor]){
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }
}

int main(){
    int V = 5;
    vector<int> adj[V];
    adj[0] = {1,2};
    adj[1] = {3};
    adj[2] = {3,4};
    adj[3] = {4};

    cout << "BFS traversal from node 0:\n";
    BFS(0, adj, V);
    return 0;
}
