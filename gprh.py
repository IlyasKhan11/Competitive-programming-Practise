import networkx as nx
import matplotlib.pyplot as plt

def create_complete_graph(n):
    """
    Create and display a complete graph with n nodes.
    
    Parameters:
    n (int): Number of nodes in the graph.
    """
    # Create a complete graph
    graph = nx.complete_graph(n)

    # Draw the graph
    pos = nx.spring_layout(graph)  # Positions for all nodes
    nx.draw(graph, pos, with_labels=True, node_color='lightblue', node_size=500, font_size=10)
    nx.draw_networkx_edge_labels(graph, pos, edge_labels={(u, v): f"{u}-{v}" for u, v in graph.edges()})
    
    # Show the graph
    plt.title(f"Complete Graph with {n} Nodes")
    plt.show()

# Number of nodes in the complete graph
num_nodes = 5  # You can change this to any number
create_complete_graph(num_nodes)
