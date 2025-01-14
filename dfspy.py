# DFS Recursive Implementation
def dfs_recursive(graph, node, visited):
    if node not in visited:
        print(node, end=" ")
        visited.add(node)
        for neighbor in graph[node]:
            dfs_recursive(graph, neighbor, visited)

# DFS Iterative Implementation
def dfs_iterative(graph, start):
    visited = set()
    stack = [start]

    while stack:
        node = stack.pop()
        if node not in visited:
            print(node, end=" ")
            visited.add(node)
            stack.extend(reversed(graph[node]))  # Add neighbors to stack in reverse order for consistent traversal

# Graph Representation (Adjacency List)
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

# DFS Recursive Traversal
print("DFS Traversal (Recursive):")
visited = set()
dfs_recursive(graph, 'A', visited)

print("\n")

# DFS Iterative Traversal
print("DFS Traversal (Iterative):")
dfs_iterative(graph, 'A')
