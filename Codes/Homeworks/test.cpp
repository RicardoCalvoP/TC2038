#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<int>> readGraph(string file)
{
  int nodes, edges;
  vector<vector<int>> adjacency_list;
  ifstream myFile(file);
  if (myFile.is_open())
  {
    myFile >> nodes >> edges;

    // Inicializar la lista de adyacencia con -1 (sin conexión directa)
    adjacency_list.resize(nodes, vector<int>(nodes, -1));

    // Poner 0 en la diagonal principal (costo de nodo a sí mismo)
    for (int i = 0; i < nodes; i++)
    {
      adjacency_list[i][i] = 0;
    }

    for (int i = 0; i < edges; i++)
    {
      // u = nodo origen
      // v = nodo destino
      // c = costo de la arista
      int u, v, c;
      myFile >> u >> v >> c;

      // Mostrar los valores leídos
      cout << "u=" << u << ", v=" << v << ", c=" << c << endl;

      // Guardar el costo en la posición correspondiente
      adjacency_list[u - 1][v - 1] = c;

      // Si el grafo no es dirigido, descomenta la siguiente línea:
      // adjacency_list[v - 1][u - 1] = c;
    }
  }
  else
  {
    cout << "Could not open file" << endl;
  }
  return adjacency_list;
}

void read_Adjacency_List(vector<vector<int>> adjacency_list)
{
  for (int i = 0; i < adjacency_list.size(); i++)
  {
    cout << "Node " << i + 1 << ": ";
    for (int j = 0; j < adjacency_list[i].size(); j++)
    {
      cout << adjacency_list[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  system("cls"); // Borrar contenido de terminal

  string filename = "../../grafo.txt";
  vector<vector<int>> graph = readGraph(filename);

  // Imprimir la lista de adyacencia
  cout << "Lista de adyacencia del grafo:" << endl;
  read_Adjacency_List(graph);

  return 0;
}
