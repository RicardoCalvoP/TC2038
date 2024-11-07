#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

void read_Adjacency_List(vector<vector<int>> adjacency_list)
{
  for (int i = 0; i < adjacency_list.size(); i++)
  {
    cout << "Node " << i + 1 << ": ";
    for (int j = 0; j < adjacency_list[i].size(); j++)
    {
      cout << adjacency_list[i][j] + 1 << " ";
    }
    cout << endl;
  }
}

vector<vector<int>> readGraph(string file)
{
  int nodes, edges;
  vector<vector<int>> adjacency_list;
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
      adjacency_list[u - 1].push_back(w);
      cout << "adjacency_list version " << i << endl;
      read_Adjacency_List(adjacency_list);
    }
  }
  else
  {
    cout << "Could not open file" << endl;
  }
  return adjacency_list;
}

void DFS(vector<vector<int>> graph, int start)
{
  stack<int> my_stack;
  int current;
  vector<bool> visited(graph.size(), false);
  my_stack.push(start);
  while (!my_stack.empty())
  {
    current = my_stack.top();
    my_stack.pop();
    if (!visited[current])
    {
      cout << current << " ";
      visited[current] = true;
      for (int i = 0; i < graph[current].size(); i++)
      {
        if (!visited[graph[current][i]])
        {
          my_stack.push(graph[current][i]);
        }
      }
    }
  }
}

void BFS(vector<vector<int>> graph, int start)
{
  queue<int> my_stack;
  int current;
  vector<bool> visited(graph.size(), false);
  my_stack.push(start);
  while (!my_stack.empty())
  {
    current = my_stack.front();
    my_stack.pop();
    if (!visited[current])
    {
      cout << current << " ";
      visited[current] = true;
      for (int i = 0; i < graph[current].size(); i++)
      {
        if (!visited[graph[current][i]])
        {
          my_stack.push(graph[current][i]);
        }
      }
    }
  }
}

int main()
{
  system("cls"); // Borrar contenido de terminal

  vector<vector<int>> adjacency_list = readGraph("../../grafo.txt");
  read_Adjacency_List(adjacency_list);

  cout << "DFS" << endl;
  DFS(adjacency_list, 0);
  cout << endl;
  cout << "BFS" << endl;
  BFS(adjacency_list, 0);
  cout << endl;
  return 0;
}