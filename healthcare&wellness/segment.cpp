class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.tree = [0]*(2*self.n)
        for i in range(self.n):
            self.tree[self.n + i] = data[i]
        for i in range(self.n-1, 0, -1):
            self.tree[i] = self.tree[2*i] + self.tree[2*i+1]

    def update(self, index, value):
        index += self.n
        self.tree[index] = value
        while index > 1:
            index //= 2
            self.tree[index] = self.tree[2*index] + self.tree[2*index+1]

    def query(self, l, r):
        l += self.n
        r += self.n
        res = 0
        while l <= r:
            if l % 2 == 1:
                res += self.tree[l]
                l += 1
            if r % 2 == 0:
                res += self.tree[r]
                r -= 1
            l //= 2
            r //= 2
        return res

beds = [5, 3, 6, 2, 4]
st = SegmentTree(beds)
print(st.query(1,3))
