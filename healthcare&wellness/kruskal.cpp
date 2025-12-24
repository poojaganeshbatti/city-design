#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) { return a.w < b.w; }

int find_set(int u, vector<int>& parent) {
    if(u != parent[u])
        parent[u] = find_set(parent[u], parent);
    return parent[u];
}

void kruskal(int V, vector<Edge>& edges) {
    vector<int> parent(V);
    for(int i=0;i<V;i++) parent[i] = i;

    sort(edges.begin(), edges.end(), cmp);
    vector<Edge> MST;

    for(auto e : edges) {
        int u_root = find_set(e.u, parent);
        int v_root = find_set(e.v, parent);
        if(u_root != v_root) {
            MST.push_back(e);
            parent[u_root] = v_root;
        }
    }

    cout << "Edges in MST:\n";
    for(auto e : MST) cout << e.u << " - " << e.v << " (weight " << e.w << ")\n";
}

int main() {
    int V = 4;
    vector<Edge> edges = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    kruskal(V, edges);
}
