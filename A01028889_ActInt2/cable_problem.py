"""
Ricardo Alfredo Calvo Pérez - A01028889
23/11/2024

Prim's Algorithm to solve the cable problem.

This module calculates the Minimum Spanning Tree (MST) for an undirected graph
using Prim's algorithm. It identifies the cheapest way to connect all nodes
with cables.

Returns:
    - mst_edges (list): List of edges in the MST as (node1, node2, weight).
    - total_cost (int): Total cost of the MST.
"""

import heapq

def cable_problem(graph, nodes):
    """
    Solve the cable problem using Prim's Algorithm.

    Args:
        graph (list of list of int): Adjacency matrix representing the graph.
        nodes (list): List of node names.

    Returns:
        tuple:
            - mst_edges (list): List of edges in the MST as (parent_node, current_node, weight).
            - total_cost (int): Total cost of the MST.
    """
    visited = [False] * len(nodes)  # Track visited nodes
    mst = []  # Store the edges in the MST
    total_cost = 0  # Accumulate the total cost of the MST
    priority_queue = [(0, 0, -1)]  # (weight, current_node, parent_node)

    while priority_queue:
        weight, current_node, parent_node = heapq.heappop(priority_queue)

        # Skip if node has already been visited
        if visited[current_node]:
            continue

        # Mark the node as visited and update total cost
        visited[current_node] = True
        total_cost += weight

        # Add edge to MST if valid (ignore root node edge)
        if parent_node != -1:
            mst.append((parent_node, current_node, weight))

        # Add neighbors of the current node to the queue
        for neighbor, edge_weight in enumerate(graph[current_node]):
            if edge_weight != -1 and not visited[neighbor]:  # Valid edge
                heapq.heappush(priority_queue, (edge_weight, neighbor, current_node))

    return mst, total_cost
