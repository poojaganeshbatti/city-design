#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

void unite(int a, int b, vector<int>& parent) {
    parent[find(a, parent)] = find(b, parent);
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };

    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    cout << "Minimum Cost Road Network:\n";
    for (auto e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            unite(e.u, e.v, parent);
            cout << e.u << " - " << e.v << " : " << e.w << endl;
        }
    }

    return 0;
}
