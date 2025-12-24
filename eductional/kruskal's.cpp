class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self, x, y):
        self.parent[self.find(x)] = self.find(y)

edges = [(1, 0, 1), (4, 0, 2), (2, 1, 2)]  # (weight, u, v)
edges.sort()
uf = UnionFind(3)
mst = []

for w, u, v in edges:
    if uf.find(u) != uf.find(v):
        uf.union(u, v)
        mst.append((u, v, w))
print(mst)
