/* The game of snakes & ladders: You are at square 1 and have to reach square 100. You have complete control over the die and can get any number from 1 - 6. From given ladders and snakes, find the minimum steps to reach square 100.

Sample input:

2   -> ladders
3 90
56 76
3   -> snakes
99 10
30 20
20 5  */

#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main()
{
  int ladders, snakes;
  cin >> ladders >> snakes;

  map<int, int> ld;
  map<int, int> sn;

  for (int i = 0; i < ladders; i++) {
    int u, v;
    cin >> u >> v;
    ld[u] = v;
  }

  for (int i = 0; i < snakes; i++) {
    int u, v;
    cin >> u >> v;
    sn[u] = v;
  }

  queue<int> q;
  q.push(1);

  vector<bool> visited (101, false);
  visited[1] = true;

  int moves = 0;
  bool found = false;

  while (!q.empty() && !found) {
    int sz = q.size();

    while (sz--) {
      int t = q.front();
      q.pop();

      for (int dice = 1; dice <= 6; dice++) {
        if (t + dice == 100) found = true;

        if (t + dice <= 100 && ld[t + dice] && !visited[ld[t + dice]]) {
          visited[ld[t + dice]] = true;
          if (ld[t + dice] == 100) found = true;
          q.push(ld[t + dice]);
        }

        else if (t + dice <= 100 && sn[t + dice] && !visited[sn[t + dice]]) {
          visited[sn[t + dice]] = true;
          if (sn[t + dice] == 100) found = true;
          q.push(sn[t + dice]);
        }

        else if (t + dice <= 100 && !visited[t + dice] && !sn[t + dice] && !ld[t + dice]) {
          visited[t + dice] = true;
          q.push(t + dice);
        }
      }
    }

    moves += 1;
  }

  if (found) cout << moves << endl;
  else cout << -1 << endl;

  return 0;
}
