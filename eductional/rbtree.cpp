# Using library `bintrees` for simplicity
from bintrees import RBTree

tree = RBTree()
tree.insert(101, 'Alice')
tree.insert(102, 'Bob')
tree.insert(103, 'Charlie')

# Search
print(tree.get(102))  # Output: Bob
