class FenwickTree:
    def __init__(self, n):
        self.tree = [0]*(n+1)
    def update(self, i, delta):
        i += 1
        while i < len(self.tree):
            self.tree[i] += delta
            i += i & -i
    def query(self, i):
        i += 1
        result = 0
        while i > 0:
            result += self.tree[i]
            i -= i & -i
        return result

ft = FenwickTree(5)
ft.update(0, 1)
ft.update(1, 2)
print(ft.query(1))  # 3
