// Problem: To find all pair shortest paths, i.e. for every u, v in graph G, find the shortest path from u to v

#include <iostream>
#include <vector>
using namespace std;

const int inf = 1e9;

int main()
{
  vector<vector<int>> graph = {
    {0, 5, inf, 10},
    {inf, 0, 3, inf},
    {inf, inf, 0 ,1},
    {inf, inf, inf, 0}
  };

  int n = graph.size();

  vector<vector<int>> dist = graph;

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dist[i][j] == inf) cout << "-1" << "\t";
      else cout << dist[i][j] << "\t";
    }

    cout << endl;
  }
  
  return 0;
}
