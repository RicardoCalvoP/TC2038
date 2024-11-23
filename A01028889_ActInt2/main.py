"""
Ricardo Alfredo Calvo Perez - A01028889
18/11/2024

Instructions:
"""

from create_graph import create_graph
from read_graph import read_graph_from_file
from functions import  print_graph, save_graph_to_file, visualize_graph


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
        break
    elif choice == "2":
        num_nodes = int(input("Set number of nodes: "))
        graph, nodes = create_graph(num_nodes)
        extraFunctions(graph, nodes)
        break
    else:
        print("Invalid option")