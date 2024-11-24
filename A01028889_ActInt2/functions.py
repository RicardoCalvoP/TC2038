"""
Ricardo Alfredo Calvo Perez - A01028889
23/11/2024

Functions used for graphs functions
"""

import string
import os
import networkx as nx
import matplotlib.pyplot as plt

from cable_problem import cable_problem


def generate_node_names(num_nodes):

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

    print("      " + " ".join(f"{node:<{3}}" for node in nodes))

    for i, row in enumerate(graph):
        print(f"{nodes[i]:<{3}} " + " ".join(f"{val:>{3}}" for val in row))


def save_graph_to_file(graph, nodes):
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

    print(f"Graph saved correctly at  {filename}.")


def visualize_graph(graph, nodes):
    """
    Visualiza un grafo dirigido utilizando NetworkX y Matplotlib.

    Args:
        graph (list): Matriz de adyacencia.
        nodes (list): Lista de nombres de los nodos.
    """
    # Crear un grafo dirigido
    G = nx.DiGraph()

    # Agregar nodos y aristas dirigidas al grafo
    for i in range(len(nodes)):
        for j in range(len(nodes)):
            if graph[i][j] != -1 and graph[i][j] != 0:  # Excluir -1 y autoconexiones
                G.add_edge(nodes[i], nodes[j], weight=graph[i][j])

    # Posiciones para los nodos
    pos = nx.spring_layout(G)  # Diseño de nodos

    # Dibujar los nodos y las flechas (aristas dirigidas)
    nx.draw_networkx_nodes(G, pos, node_color="lightblue", node_size=700)
    nx.draw_networkx_labels(
        G, pos, labels={node: node for node in nodes}, font_weight="bold")
    nx.draw_networkx_edges(G, pos, arrowstyle="->",
                           arrowsize=20, connectionstyle="arc3,rad=0.2")

    # Agregar etiquetas de los pesos de las aristas
    edge_labels = nx.get_edge_attributes(G, "weight")
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

    # Título y mostrar el grafo
    plt.title("Visualización del Grafo Dirigido")
    plt.show()

def extraFunctions(graph, nodes):
    choice = input("Do you need to print adjacency matrix? [y] yes , [n] no: ")
    if choice.lower() == "y":
        print_graph(graph, nodes)
    choice = input("Do you need to save the graph into a file? [y] yes , [n] no: ")
    if choice.lower() == "y":
        save_graph_to_file(graph, nodes)
    choice = input("Do you need to see the graph? [y] yes , [n] no: ")
    if choice.lower() == "y":
        visualize_graph(graph, nodes)


def print_cable_problem(graph, nodes):
    print(
            "\n=================================================="
            "\n|                Cable Problem                   |"
            "\n=================================================="
            )
    mst, total_cost = cable_problem(graph, nodes)

    for edge in mst:
        print(f"{nodes[edge[0]]} → {nodes[edge[1]]} (Weight: {edge[2]})")

    print("Total cost →", total_cost)