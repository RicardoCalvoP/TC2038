def travelers_problem(graph, nodes):
    """
    Solves the Traveler's Problem (TSP) using the Nearest Neighbor heuristic.

    Args:
        graph (list of list of int): Adjacency matrix representing the graph.
        nodes (list): List of node names.

    Returns:
        tuple:
            - path (list): The sequence of edges as (node1, node2, cost).
            - total_cost (int): The total cost of the path.
    """
    num_nodes = len(nodes)
    visited = [False] * num_nodes  # Track visited nodes
    path = []  # Store the edges in the form (node1, node2, cost)
    total_cost = 0  # Accumulate the total cost

    # Start at the first node (node 0, or 'A')
    current_node = 0
    visited[current_node] = True

    for _ in range(num_nodes - 1):
        # Find the nearest unvisited neighbor
        nearest_neighbor = None
        min_distance = float('inf')

        for neighbor in range(num_nodes):
            if not visited[neighbor] and graph[current_node][neighbor] != -1:  # Valid edge
                if graph[current_node][neighbor] < min_distance:
                    nearest_neighbor = neighbor
                    min_distance = graph[current_node][neighbor]

        # Update path and cost
        if nearest_neighbor is not None:
            path.append((nodes[current_node], nodes[nearest_neighbor], min_distance))
            total_cost += min_distance
            visited[nearest_neighbor] = True
            current_node = nearest_neighbor

    # Return to the starting node to complete the cycle
    return_cost = graph[current_node][0]
    total_cost += return_cost
    path.append((nodes[current_node], nodes[0], return_cost))  # Add edge back to start

    return path, total_cost
