"""
Ricardo Alfredo Calvo Pérez - A01028889

Functions to read graphs from files and create adjacency matrices.
"""

import os
from functions import generate_node_names

def read_graph_from_file(file):
    """
    Read a graph from a file and convert it into an adjacency matrix.

    Args:
        file (str): Name of the file (e.g., 'Graph_4_nodes.txt').

    Returns:
        tuple:
            - nodes (list): List of node names.
            - graph (list): Adjacency matrix.
    """
    folder = "Graphs"
    filepath = os.path.join(folder, file)

    if not os.path.exists(folder):
        print(f"Error: Folder '{folder}' does not exist.")
        return None, None

    try:
        with open(filepath, "r") as file_obj:
            num_nodes, _ = map(int, file_obj.readline().strip().split())
            nodes = generate_node_names(num_nodes)
            graph = [[-1 for _ in range(num_nodes)] for _ in range(num_nodes)]

            for line in file_obj:
                origin, destination, weight = map(int, line.strip().split())
                graph[origin - 1][destination - 1] = weight

            return nodes, graph

    except FileNotFoundError:
        print(f"Error: File '{filepath}' not found.")
        return None, None
    except Exception as e:
        print(f"Error reading file: {e}")
        return None, None
