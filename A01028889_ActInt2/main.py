"""
Ricardo Alfredo Calvo Perez - A01028889
18/11/2024

Instructions:
"""

from create_graph import create_graph
from read_graph import read_graph_from_file
from functions import  print_cable_problem, extraFunctions


"""
=========================================
MAIN PROGRAM
=========================================
"""
# Options of UX
while True:
    print("\nWhat versions do yo want to try?\n")
    choice = input('[1] Read your own file\n'
            '[2] Create random graph\n'
            'Version: ')
    if choice == "1":
        file = input("What file you want to open? ej. Graph_4_nodes.txt:\n")
        nodes, graph = read_graph_from_file(file)
        extraFunctions(graph, nodes)

        print_cable_problem(graph,nodes)

        break
    elif choice == "2":
        num_nodes = int(input("Set number of nodes: "))
        graph, nodes = create_graph(num_nodes)
        extraFunctions(graph, nodes)

        print_cable_problem(graph,nodes)

        break
    else:
        print("Invalid option")