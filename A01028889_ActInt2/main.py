"""
Ricardo Alfredo Calvo Pérez - A01028889
23/11/2024

Main program to solve graph problems:
- Create random graphs
- Load graphs from files
- Solve the cable problem (MST)
"""

from create_graph import create_graph
from read_graph import read_graph_from_file
from functions import print_cable_problem, extraFunctions

# Main program loop
while True:
    print("\nChoose an option:\n")
    choice = input('[1] Read a graph from a file\n[2] Create a random graph\nChoice: ')
    if choice == "1":
        file = input("Enter the filename (e.g., Graph_4_nodes.txt):\n")
        nodes, graph = read_graph_from_file(file)
        extraFunctions(graph, nodes)
        print_cable_problem(graph, nodes)
        break
    elif choice == "2":
        num_nodes = int(input("Enter the number of nodes: "))
        graph, nodes = create_graph(num_nodes)
        extraFunctions(graph, nodes)
        print_cable_problem(graph, nodes)
        break
    else:
        print("Invalid option. Try again.")
