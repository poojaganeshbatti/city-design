#include <bits/stdc++.h>
using namespace std;

int main() {
    int V = 5; // number of banks
    vector<vector<int>> adj(V);

    // Sample connections between banks and users
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(4);

    cout << "Bank connections (Adjacency List):\n";
    for(int i=0;i<V;i++){
        cout << "Bank " << i << " connected to: ";
        for(int j: adj[i]) cout << j << " ";
        cout << "\n";
    }
}

