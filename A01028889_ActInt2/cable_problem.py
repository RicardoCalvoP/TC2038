"""
Ricardo Alfredo Calvo Pérez - A01028889
23/11/2024

Prim's Algorithm to get the cheapest path to set cable
to connect all nodes
"""

import heapq

def cable_problem(graph, nodes):
    """
    Finds the Minimum Spanning Tree (MST) for an undirected graph using Prim's algorithm.

    Args:
        graph (list of list of int): Adjacency matrix representing the graph.

    Returns:
        tuple:
            - mst_edges (list): List of edges in the MST as (node1, node2, weight).
            - total_cost (int): Total cost of the MST.
    """

    visited = [False] * nodes # List of length of number nodes checked if visited or not