/*
Ricardo Alfredo Calvo Perez
07/11/2024

Floyd Warshall & Dijkstar Algorithm
*/

#include <iostream>
#include <vector>
#include "floyd_warshall.h"
#include "dijkstra.h"
using namespace std;

/*
=========================================================================
MAIN
=========================================================================
*/

int main()
{
  system("cls"); // Clear terminal output

  /*
  ** INTRSUCTIONS **

  Use any of the graphs in the Graph examples folder or create your own with the following format

  line 1 -> [number of nodes ] [number of edges]
  line 2-e -> [origin node] [destination node] [cost]

  Remeber this is for weighted directed graph only
  */
  string graph = "../Graph_examples/grafo6.txt";

  vector<vector<int>>
      adjacency_matrix = get_Adjacency_Matrix(graph);
  cout << "Adjacency Matrix" << endl;
  read_Adjacency_Matrix(adjacency_matrix);

  vector<vector<vector<int>>> adjacency_list = get_Adjacency_List(graph);
  cout << endl
       << "Adjacency List:" << endl;
  read_Adjacency_List(adjacency_list);

  vector<vector<int>> Floyd_matrix = floydWarshall(adjacency_matrix);
  cout << endl
       << "Adjacency Matrix with floyd" << endl;
  read_Adjacency_Matrix(Floyd_matrix);

  vector<vector<vector<int>>> dijkstra_list = Dijkstra(adjacency_list);
  cout << endl
       << "Adjacency List with Dijkstra" << endl;
  print_Dijkstra_List(dijkstra_list);

  cout << endl;
  return 0;
}
