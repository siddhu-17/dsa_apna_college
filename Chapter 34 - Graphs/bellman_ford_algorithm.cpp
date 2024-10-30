/* Problem: From a source vertex v, find the shortest distance to all other nodes in the graph

Idea:

-> Initially, d[v] = 0, and for all other elements, d[i] = infinity
-> In each pass, relax all the edges, i.e. for edge (a, b) having weight w, d[b] = min(d[b], d[a] + w)
-> Assuming no negative edge cycle, since there are n vertices, shortest path can only contain 'n-1' edges. Therefore, we will get our answer in at most 'n-1' passes.

Advantages over Dijkstra's algorithm:

-> It will work for negative edges & negative cycles
-> It can detect negative cycles as well */

#include <iostream>
#include <vector>
using namespace std;

int inf = 1e5+ 3;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> edges;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    edges.push_back({ u, v, w });
  }

  int src;
  cin >> src;

  vector<int> dist(n, inf);
  dist[src] = 0;

  bool negativeCycle = false;

  for (int i = 0; i < n - 1; i++) {
    for (auto e : edges) {
      int u = e[0];
      int v = e[1];
      int w = e[2];

      if (dist[v] > w + dist[u]) {
        negativeCycle = true;
      }

      dist[v] = min(dist[v], w + dist[u]);
    }
  }

  for (auto it : dist) {
    cout << it << " ";
  }

  cout << endl << "\n" << "Graph contains negative cycle" << endl;

  return 0;
}
