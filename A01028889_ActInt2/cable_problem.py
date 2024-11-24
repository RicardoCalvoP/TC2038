"""
Ricardo Alfredo Calvo Pérez - A01028889
23/11/2024

Prim's Algorithm to get the cheapest path to set cable
to connect all nodes

    Finds the Minimum Spanning Tree (MST) for an undirected graph using Prim's algorithm.

    Args:
        graph (list of list of int): Adjacency matrix representing the graph.

    Returns:
        tuple:
            - mst_edges (list): List of edges in the MST as (node1, node2, weight).
            - total_cost (int): Total cost of the MST.

"""

import heapq

def cable_problem(graph, nodes):
    """
    Prim's Algorithm to calculate the Minimum Spanning Tree (MST) for a graph.

    Args:
        graph (list of list of int): Adjacency matrix representing the graph.
        nodes (list): List of node names.

    Returns:
        tuple:
            - mst (list): List of edges in the MST as (parent_node, current_node, weight).
            - total_cost (int): Total cost of the MST.
    """
    visited = [False] * len(nodes)  # List of length of number of nodes to track visited nodes
    mst = []  # Store the edges of the MST
    total_cost = 0  # Total cost of the MST
    priority_queue = [(0, 0, -1)]  # Start from node 0 with weight 0 and no parent

    while priority_queue:
        weight, current_node, parent_node = heapq.heappop(priority_queue)

        # Skip if the node is already visited
        if visited[current_node]:
            continue

        # Mark the current node as visited
        visited[current_node] = True
        total_cost += weight  # Add the weight to the total cost

        # Add the edge to the MST if it's not the starting node
        if parent_node != -1:
            mst.append((parent_node, current_node, weight))

        # Add all unvisited neighbors of the current node to the priority queue
        for neighbor, edge_weight in enumerate(graph[current_node]):
            if edge_weight != -1 and not visited[neighbor]:
                heapq.heappush(priority_queue, (edge_weight, neighbor, current_node))

    return mst, total_cost
