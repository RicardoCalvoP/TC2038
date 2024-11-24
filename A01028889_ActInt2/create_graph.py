"""
Ricardo Alfredo Calvo Pérez - A01028889

Create a random graph based on the number of nodes.

Generates a graph with random weights between nodes, where some connections
may not exist.
"""

import random
from functions import generate_node_names

def create_graph(num_nodes):
    """
    Generate a random graph.

    Args:
        num_nodes (int): Number of nodes in the graph.

    Returns:
        tuple:
            - graph (list of list of int): Adjacency matrix for the graph.
            - nodes (list): List of node names.
    """
    # Generate node names (e.g., ["A", "B", ...])
    nodes = generate_node_names(num_nodes)

    # Initialize adjacency matrix with random weights
    graph = [[0 if i == j else random.randint(1, 100) for j in range(num_nodes)] for i in range(num_nodes)]

    # Randomly disconnect some edges
    for i in range(num_nodes):
        for j in range(i + 1, num_nodes):
            if random.random() > 0.6:  # 40% chance to keep an edge
                graph[i][j] = graph[j][i] = -1

    return graph, nodes
