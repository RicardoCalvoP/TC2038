"""
Ricardo Alfredo Calvo Perez - A01028889

Create a graph depending on the number of nodes given

Arguments:
  * num_nodes (int): number of nodes in the graph
"""

import random
from functions import generate_node_names



def create_graph(num_nodes):

    nodes = generate_node_names(num_nodes)

    graph = [[0 if i == j else random.randint(
        1, 100) for j in range(num_nodes)] for i in range(num_nodes)]

    for i in range(num_nodes):
        for j in range(i + 1, num_nodes):
            if random.random() > 0.6:
                graph[i][j] = graph[j][i] = -1

    return graph, nodes