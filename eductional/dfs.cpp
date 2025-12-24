def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    for neighbor in graph.get(start, []):
        if neighbor not in visited:
            dfs(graph, neighbor, visited)
    return visited

# Check connectivity in campus
campus_graph = {
    'BlockA': ['BlockB', 'BlockC'],
    'BlockB': ['BlockD'],
    'BlockC': [],
    'BlockD': []
}

print(dfs(campus_graph, 'BlockA'))
