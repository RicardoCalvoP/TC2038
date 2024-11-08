#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <queue>
#include <limits>

using namespace std;
const int INF = numeric_limits<int>::max();

/*
=========================================================================
Floyd Warshall
=========================================================================
*/
void read_Adjacency_Matrix(vector<vector<int>> adjacency_matrix)
{
  for (int i = 0; i < adjacency_matrix.size(); i++)
  {
    cout << "Node " << i + 1 << ": ";
    for (int j = 0; j < adjacency_matrix[i].size(); j++)
    {
      if (adjacency_matrix[i][j] < 0)
      {

        cout << adjacency_matrix[i][j] << " ";
      }
      else if (adjacency_matrix[i][j] > 9)
      {
        cout << " " << adjacency_matrix[i][j];
      }
      else
      {
        cout << " " << adjacency_matrix[i][j] << " ";
      }
    }
    cout << endl;
  }
}

vector<vector<int>> get_Adjacency_Matrix(string file)
{
  int nodes, edges;
  vector<vector<int>> adjacency_matrix;
  ifstream myFile(file);
  if (myFile.is_open())
  {
    myFile >> nodes >> edges;

    adjacency_matrix.resize(nodes, vector<int>(nodes, -1));

    // set in 0 diagonal line in matrix
    for (int i = 0; i < nodes; i++)
    {
      adjacency_matrix[i][i] = 0;
    }

    for (int i = 0; i < edges; i++)
    {
      // u = nodo origen
      // v = nodo destino
      // c = costo de la arista
      int u, v, c;
      myFile >> u >> v >> c;

      // Guardar el costo en la posición correspondiente
      adjacency_matrix[u - 1][v - 1] = c;
    }
  }
  else
  {
    cout << "Could not open file" << endl;
  }
  return adjacency_matrix;
}

vector<vector<int>> floydWarshall(vector<vector<int>> matrix)
{
  int n = matrix.size();
  vector<vector<int>> dist = matrix; // Copia de la matriz de entrada para calcular las distancias

  // Reemplazar -1 por INF (excepto en la diagonal principal)
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (dist[i][j] == -1 && i != j) // No hay conexión directa
      {
        dist[i][j] = INF;
      }
    }
  }

  // Aplicamos Floyd-Warshall
  for (int k = 0; k < n; ++k) // Nodo intermedio
  {
    for (int i = 0; i < n; ++i) // Nodo origen
    {
      for (int j = 0; j < n; ++j) // Nodo destino
      {
        // Si hay un camino válido a través de k, actualizamos la distancia
        if (dist[i][k] != INF && dist[k][j] != INF)
        {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  return dist;
}
void read_Adjacency_List(vector<vector<vector<int>>> adjacency_list)
{
  for (int i = 0; i < adjacency_list.size(); i++)
  {
    cout << "Node " << i + 1 << ": ";
    for (int j = 0; j < adjacency_list[i].size(); ++j)
    {
      if (j != adjacency_list[i].size() - 1)
      {
        cout << "[" << adjacency_list[i][j][0] << " , " << adjacency_list[i][j][1] << "] - ";
      }
      else
      {
        cout << "[" << adjacency_list[i][j][0] << " , " << adjacency_list[i][j][1] << "]";
      }
    }

    cout << endl;
  }
}

vector<vector<vector<int>>> get_Adjacency_List(string file)
{
  int nodes, edges;
  vector<vector<vector<int>>> adjacency_list;
  ifstream myFile(file);
  if (myFile.is_open())
  {

    myFile >> nodes >> edges;

    adjacency_list.resize(nodes);

    for (int i = 0; i < edges; i++)
    {
      // u = source vertex
      // v = destination vertex
      // w = weight
      int u, v, w;
      myFile >> u >> v >> w;
      vector<int> vw = {v, w};
      adjacency_list[u - 1].push_back(vw);
    }
  }
  else
  {
    cout << "Could not open file" << endl;
  }
  return adjacency_list;
}

int main()
{
  system("cls"); // Borrar contenido de terminal

  vector<vector<int>> adjacency_matrix = get_Adjacency_Matrix("../../grafo.txt");
  cout << "Adjacency Matrix" << endl;
  read_Adjacency_Matrix(adjacency_matrix);

  vector<vector<vector<int>>> adjacency_list = get_Adjacency_List("../../grafo.txt");
  cout << endl
       << "Adjacency List:" << endl;
  read_Adjacency_List(adjacency_list);

  vector<vector<int>> Floyd_matrix = floydWarshall(adjacency_matrix);
  cout << endl
       << "Adjacency Matrix with floyd" << endl;
  read_Adjacency_Matrix(Floyd_matrix);

  cout << endl;
  return 0;
}