#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};

int main() {
    UnionFind uf(5);
    uf.unite(0, 1);
    uf.unite(1, 2);

    if (uf.find(0) == uf.find(2))
        cout << "Zones are connected\n";
    else
        cout << "Zones are disconnected\n";

    return 0;
}
