#include <iostream>
#include <vector>
#include <fstream>
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

    // Set 0 on the diagonal of the matrix
    for (int i = 0; i < nodes; i++)
    {
      adjacency_matrix[i][i] = 0;
    }

    for (int i = 0; i < edges; i++)
    {
      // u = origin node
      // v = destination node
      // c = edge cost
      int u, v, c;
      myFile >> u >> v >> c;

      // Store the cost in the corresponding position
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
  vector<vector<int>> dist = matrix;

  // Replace -1 with INF (except for the main diagonal)
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (dist[i][j] == -1 && i != j)
      {
        dist[i][j] = INF;
      }
    }
  }

  // Apply Floyd-Warshall algorithm
  for (int k = 0; k < n; ++k) // Intermediate node
  {
    for (int i = 0; i < n; ++i) // Origin node
    {
      for (int j = 0; j < n; ++j) // Destination node
      {
        // If a valid path exists through k, update the distance
        if (dist[i][k] != INF && dist[k][j] != INF)
        {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (dist[i][j] == INF)
      {
        dist[i][j] = -1;
      }
    }
  }
  return dist;
}