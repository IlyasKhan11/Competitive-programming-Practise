from collections import deque

def bfs(graph, start):
    # Create a queue for BFS
    queue = deque([start])
    # Set to keep track of visited nodes
    visited = set()
    
    visited.add(start)
    
    while queue:
        # Dequeue a vertex from the queue
        current = queue.popleft()
        print(current, end=" ")  # Process the current node
        
        # Get all adjacent vertices of the dequeued vertex
        # If an adjacent has not been visited, mark it visited and enqueue it
        for neighbor in graph[current]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

# Example usage
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

bfs(graph, 'A')
