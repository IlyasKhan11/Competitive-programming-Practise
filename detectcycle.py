class Graph:
    def __init__(self, vertices):
        self.graph = defaultdict(list)
        self.vertices = vertices

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)  # Since it's undirected

    def is_cyclic_util(self, v, visited, parent):
        visited[v] = True

        for neighbor in self.graph[v]:
            if not visited[neighbor]:
                if self.is_cyclic_util(neighbor, visited, v):
                    return True
            elif parent != neighbor:  # If the visited neighbor is not the parent
                return True

        return False


    def is_cyclic(self):
        visited = [False] * self.vertices

        for node in range(self.vertices):
            if not visited[node]:
                if self.is_cyclic_util(node, visited, -1):
                    return True
        return False


# Example Usage
g = Graph(4)
g.add_edge(0, 1)
g.add_edge(1, 2)
g.add_edge(2, 3)
g.add_edge(3, 0)  # Adding a cycle here

if g.is_cyclic():
    print("Graph has a cycle")
else:
    print("Graph doesn't have a cycle")
