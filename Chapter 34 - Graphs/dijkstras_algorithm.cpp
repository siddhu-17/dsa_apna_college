/* Problem: Given a weighted adj. Find the single source shortest path from a vertex u to all the vertices in the adj. If the node is unreachable, then print -1.

Note: The weight of the cycle must be positive

Idea:

-> Assign a distance value to all the vertices in the input adj. Intialize all distance values as INFINITE. Assign distance value as zero for the source vertex.
-> While set is not empty: pick a vertex u from set s that has minimum distance value, update distance value of all adjacent vertices of u. */

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> dist(n + 1, INT32_MAX);
  vector<vector<pair<int, int>>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({ v, w });
    adj[v].push_back({ u, w });
  }

  int source;
  cin >> source;

  dist[source] = 0;

  set<pair<int, int>> st;
  st.insert({ 0, source });

  while (!st.empty()) {
    auto x = *st.begin();
    st.erase(x);

    int u = x.second;

    for (auto it : adj[u]) {
      int curr = dist[u] + it.second;

      if (dist[it.first] > curr) {
        st.erase({ dist[it.first], it.first });
        dist[it.first] = curr;
        st.insert({ curr, it.first });
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (dist[i] < INT32_MAX) cout << dist[i] << " ";
    else cout << -1 << " ";
  }

  cout << endl;

  return 0;
}
