import heapq

def prim(graph, start):
    visited = set([start])
    edges = [(cost, start, to) for to, cost in graph[start]]
    heapq.heapify(edges)
    mst = []

    while edges:
        cost, frm, to = heapq.heappop(edges)
        if to not in visited:
            visited.add(to)
            mst.append((frm, to, cost))
            for to_next, cost_next in graph[to]:
                if to_next not in visited:
                    heapq.heappush(edges, (cost_next, to, to_next))
    return mst

campus_graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('A', 1), ('C', 2)],
    'C': [('A', 4), ('B', 2)]
}

print(prim(campus_graph, 'A'))
