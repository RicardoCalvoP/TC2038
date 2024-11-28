"""
Ricardo Alfredo Calvo Pérez - A01028889
23/11/2024

Helper functions for graph operations:
- Generate node names
- Print adjacency matrix
- Save graphs to a file
- Visualize graphs
"""

import string
import os
import networkx as nx
import matplotlib.pyplot as plt
from cable_problem import cable_problem
from traveler_problem import travelers_problem

def generate_node_names(num_nodes):
    """
    Generate unique node names (e.g., A, B, ..., AA, AB, ...).

    Args:
        num_nodes (int): Number of nodes.

    Returns:
        list: List of node names.
    """
    names = []
    alphabet = string.ascii_uppercase
    while len(names) < num_nodes:
        length = len(names)
        name = ""
        while True:
            name = alphabet[length % 26] + name
            length = length // 26 - 1
            if length < 0:
                break
        names.append(name)
    return names

def print_graph(graph, nodes):
    """
    Print the adjacency matrix of a graph.

    Args:
        graph (list): Adjacency matrix.
        nodes (list): List of node names.
    """
    print("      " + " ".join(f"{node:<3}" for node in nodes))
    for i, row in enumerate(graph):
        print(f"{nodes[i]:<3} " + " ".join(f"{val:>3}" for val in row))

def save_graph_to_file(graph, nodes):
    """
    Save the graph as a text file.

    Args:
        graph (list): Adjacency matrix.
        nodes (list): List of node names.
    """
    edges = []
    num_nodes = len(nodes)
    directory = "Graphs"
    filename = f"{directory}/Graph_{num_nodes}_nodes.txt"
    os.makedirs(directory, exist_ok=True)

    for i in range(num_nodes):
        for j in range(num_nodes):
            if graph[i][j] != -1 and graph[i][j] != 0:
                edges.append((i + 1, j + 1, graph[i][j]))

    with open(filename, "w") as f:
        f.write(f"{num_nodes} {len(edges)}\n")
        for edge in edges:
            f.write(f"{edge[0]} {edge[1]} {edge[2]}\n")

    print(f"Graph saved at {filename}.")

def visualize_graph(graph, nodes):
    """
    Visualize a directed graph using NetworkX and Matplotlib.

    Args:
        graph (list): Adjacency matrix.
        nodes (list): List of node names.
    """
    G = nx.DiGraph()

    for i in range(len(nodes)):
        for j in range(len(nodes)):
            if graph[i][j] != -1 and graph[i][j] != 0:
                G.add_edge(nodes[i], nodes[j], weight=graph[i][j])

    pos = nx.spring_layout(G)
    nx.draw(G, pos, with_labels=True, node_color="lightblue", font_weight="bold")
    edge_labels = nx.get_edge_attributes(G, "weight")
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)
    plt.title("Graph Visualization")
    plt.show()


"""
Helper functions for user interaction and displaying results for the cable problem.
"""

def extraFunctions(graph, nodes, version):
    """
    Provides additional functionalities for user interaction:
    - Print the adjacency matrix of the graph.
    - Save the graph to a file.
    - Visualize the graph as a directed graph.

    Args:
        graph (list): Adjacency matrix of the graph.
        nodes (list): List of node names.
    """
    if version == "2":
        choice = input("Do you need to save the graph into a file? [y] yes , [n] no: ")
        if choice.lower() == "y":
            save_graph_to_file(graph, nodes)  # Save the graph to a text file

    choice = input("Do you need to see the graph? [y] yes , [n] no: ")
    if choice.lower() == "y":
        visualize_graph(graph, nodes)  # Visualize the graph


def print_cable_problem(graph, nodes):
    """
    Solves and prints the results of the cable problem (MST).
    - Uses Prim's Algorithm to compute the Minimum Spanning Tree (MST).
    - Displays the edges in the MST with their weights.
    - Displays the total cost of the MST.

    Args:
        graph (list): Adjacency matrix of the graph.
        nodes (list): List of node names.
    """
    print(
        "\n=================================================="
        "\n|                Cable Problem                   |"
        "\n=================================================="
    )
    mst, total_cost = cable_problem(graph, nodes)  # Solve the MST problem

    # Print the edges of the MST
    for edge in mst:
        print(f"{nodes[edge[0]]} → {nodes[edge[1]]} (Weight: {edge[2]})")

    # Print the total cost of the MST
    print("Total cost →", total_cost)


def print_travelers_problem(graph, nodes):

    print(
        "\n=================================================="
        "\n|              Traveler's Problem                |"
        "\n=================================================="
    )

    path , total_cost = travelers_problem(graph, nodes)
    for edge in path:
        print(f"{edge[0]} → {edge[1]} (Cost: {edge[2]} km)")
    print(f"Total Cost: {total_cost} km")  # Print the total cost
