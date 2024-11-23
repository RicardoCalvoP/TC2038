"""
Ricardo Alfredo Calvo Pérez - A01028889

Functions for graphs
"""


import os
from functions import generate_node_names


def read_graph_from_file(file):
    """
    Reads a graph from a file and converts it into an adjacency matrix.

    Args:
        file (str): Name of the file (e.g., 'Graph_4_nodes.txt').

    Returns:
        tuple: A tuple containing:
            - nodes (list): List of node names (e.g., ["A", "B", "C"]).
            - graph (list): Adjacency matrix as a 2D list.
    """
    folder = "Graphs"
    filepath = os.path.join(folder, file)

    if not os.path.exists(folder):
        print(f"Error: Folder '{folder}' does not exist.")
        return None, None

    try:
        with open(filepath, "r") as file_obj:
            # Read the first line (number of nodes and edges)
            num_nodes, num_edges = map(int, file_obj.readline().strip().split())

            # Generate unique node names and initialize adjacency matrix
            nodes = generate_node_names(num_nodes)
            graph = [[-1 for _ in range(num_nodes)] for _ in range(num_nodes)]

            # Fill the adjacency matrix with data from the file
            for line in file_obj:
                origin, destination, weight = map(int, line.strip().split())
                graph[origin - 1][destination - 1] = weight  # Convert 1-indexed to 0-indexed

            return nodes, graph

    except FileNotFoundError:
        print(f"Error: File '{filepath}' not found.")
        return None, None
    except Exception as e:
        print(f"Error reading file: {e}")
        return None, None
