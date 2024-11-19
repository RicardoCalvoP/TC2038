"""
Ricardo Alfredo Calvo Perez - A01028889
18/11/2024

Instructions:
"""

from create_graph import create_graph, print_graph, save_graph_to_file, visualize_graph


"""
=========================================
MAIN PROGRAM
=========================================
"""

# Ask for numbers of nodes
num_nodes = int(input("Set number of nodes: "))
graph, nodes = create_graph(num_nodes)


# Options of UX
choice = input("Do you need to print adjacency matrix? [y] yes , [n] no: ")
if choice.lower() == "y":
    print_graph(graph, nodes)
choice = input("Do you need to save the graph into a file? [y] yes , [n] no: ")
if choice.lower() == "y":
    save_graph_to_file(graph, nodes)
choice = input("Do you need to see the graph? [y] yes , [n] no: ")
if choice.lower() == "y":
    visualize_graph(graph, nodes)
