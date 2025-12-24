from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    result = []

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)
            result.append(node)
            for neighbor in graph.get(node, []):
                if neighbor not in visited:
                    queue.append(neighbor)
    return result

# Example graph: campuses connected
graph = {
    'Residential1': ['School1', 'School2'],
    'Residential2': ['School2', 'College1'],
    'School1': [],
    'School2': [],
    'College1': []
}

print(bfs(graph, 'Residential1'))
