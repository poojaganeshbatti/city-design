#include <bits/stdc++.h>
using namespace std;

int find_set(int u, vector<int>& parent) {
    if(parent[u] != u)
        parent[u] = find_set(parent[u], parent);
    return parent[u];
}

void union_sets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = find_set(u, parent);
    v = find_set(v, parent);
    if(u != v) {
        if(rank[u] < rank[v]) swap(u,v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
    }
}

int main() {
    int n = 5; // nodes 0-4
    vector<int> parent(n), rank(n,0);
    for(int i=0;i<n;i++) parent[i] = i;

    union_sets(0,1,parent,rank);
    union_sets(1,2,parent,rank);
    union_sets(3,4,parent,rank);

    for(int i=0;i<n;i++)
        cout << "Parent of " << i << " is " << find_set(i,parent) << "\n";
}
