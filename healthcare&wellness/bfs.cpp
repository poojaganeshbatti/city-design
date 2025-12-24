from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    nearest_hospitals = []

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)
            if "Hospital" in node:
                nearest_hospitals.append(node)
            for neighbor in graph.get(node, []):
                if neighbor not in visited:
                    queue.append(neighbor)
    return nearest_hospitals

graph = {
    'Home': ['Clinic1', 'Clinic2'],
    'Clinic1': ['Hospital1'],
    'Clinic2': ['Hospital2'],
    'Hospital1': [],
    'Hospital2': []
}

print(bfs(graph, 'Home'))
