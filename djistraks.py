import heapq

def dijkstra(n, edges, src):
    graph = {i: [] for i in range(n)}
    for u, v, w in edges:
        graph[u].append((v, w))
    
    # Priority queue (min-heap) for Dijkstra's algorithm
    min_heap = [(0, src)]  # (distance, node)
    distances = {i: float('inf') for i in range(n)}
    distances[src] = 0
    
    while min_heap:
        curr_dist, node = heapq.heappop(min_heap)
        
        if curr_dist > distances[node]:  # Skip if already processed with a shorter path
            continue
        
        for neighbor, weight in graph[node]:
            new_dist = curr_dist + weight
            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                heapq.heappush(min_heap, (new_dist, neighbor))
    
    # Convert unreachable distances to -1
    return [dist if dist != float('inf') else -1 for dist in distances.values()]

# Example usage
n = 5
edges = [(0, 1, 2), (0, 2, 4), (1, 2, 1), (1, 3, 7), (2, 4, 3), (3, 4, 1)]
src = 0
print(dijkstra(n, edges, src))
