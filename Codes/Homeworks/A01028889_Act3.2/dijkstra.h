/*
Ricardo Alfredo Calvo Perez
07/11/2024

Dijkstar Algorithm
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <limits>

using namespace std;
/*
=========================================================================
Dijkstra
=========================================================================
*/

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

vector<vector<vector<int>>> Dijkstra(vector<vector<vector<int>>> adjacency_list)
{
  int n = adjacency_list.size();
  vector<vector<vector<int>>> result(n); // To store the shortest paths for all nodes

  for (int src = 0; src < n; src++)
  {

    // Assuming the source is the first node (0-based index)
    vector<int> shortest(n, numeric_limits<int>::max()); // Store the shortest distance to each node
    shortest[src] = 0;                                   // Source node distance to itself is 0

    // Min-heap priority queue: pair<distance, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, src}); // Start from the source node

    while (!minHeap.empty())
    {
      int current_dist = minHeap.top().first;
      int current_node = minHeap.top().second;
      minHeap.pop();

      // If we already processed this node, skip it
      if (current_dist > shortest[current_node])
      {
        continue;
      }

      // Explore neighbors
      for (auto &neighbor : adjacency_list[current_node])
      {
        int next_node = neighbor[0] - 1; // Destination node
        int edge_weight = neighbor[1];   // Weight of the edge

        // Relaxation step: check if we can get a shorter path
        if (shortest[current_node] + edge_weight < shortest[next_node])
        {
          shortest[next_node] = shortest[current_node] + edge_weight;
          minHeap.push({shortest[next_node], next_node});
        }
      }
    }

    // Build the resulting adjacency list for the source node
    for (int j = 0; j < n; ++j)
    {
      if (shortest[j] != numeric_limits<int>::max() && src != j)
      {
        result[src].push_back({j + 1, shortest[j]});
      }
    }
  }
  return result;
}

void print_Dijkstra_List(vector<vector<vector<int>>> dijkstra_list)
{
  for (int i = 0; i < dijkstra_list.size(); i++)
  {
    for (const auto &edge : dijkstra_list[i])
    {

      cout << "Node " << i + 1 << " to node " << edge[0] << ": " << edge[1] << endl;
    }
  }
}
