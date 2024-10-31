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
    cout << i + 1 << ": ";
    for (int j = 0; j < adjacency_list[i].size(); j++)
    {
      cout << adjacency_list[i][j] + 1 << " ";
    }
    cout << endl;
  }
}

vector<vector<int>> readGraph(string file)
{
  int nodes, edges, type;
  vector<vector<int>> adjacency_list;
  ifstream myFile(file);
  if (myFile.is_open())
  {
    myFile >> nodes >> edges >> type;
    adjacency_list.resize(nodes);
    for (int i = 0; i < edges; i++)
    {
      int u, v;
      myFile >> u >> v;
      adjacency_list[u - 1].push_back(v - 1);
      adjacency_list[v - 1].push_back(u - 1);
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
  vector<vector<int>> adjacency_list = readGraph("../grafo.txt");
  read_Adjacency_List(adjacency_list);

  cout << "DFS" << endl;
  DFS(adjacency_list, 0);
  cout << endl;
  cout << "BFS" << endl;
  BFS(adjacency_list, 0);
  cout << endl;
  return 0;
}