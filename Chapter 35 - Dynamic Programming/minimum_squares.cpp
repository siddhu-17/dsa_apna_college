/* Recursive solution with O(n^2) time complexity:

int getMinSquares (unsigned long n) {
  if (sqrt(n) - floor(sqrt(n)) == 0) return 1;
  if (n <= 3) return n;

  int res = n;

  for (int i = 1; i * i <= n; i++) {
    res = min(res, 1 + getMinSquares(n - temp));
  }

  return res;
}

*/

#include <bits/stdc++.h>
using namespace std;

// top - down / memoization approach

int minSquares (unsigned int n, int *dp) {
  if (dp[n] != INT_MAX) return dp[n];
  if (sqrt(n) - floor(sqrt(n)) == 0) return dp[n] = 1;

  int res = n;

  for (int i = 1; i * i <= n; i++) {
    dp[n] = min(dp[n], 1 + minSquares(n - i * i, dp));
  }

  return dp[n];
}

int main()
{
  int n;
  cin >> n;

  int *dp = new int[n + 1];

  for (int i = 0; i <= n; i++) {
    dp[i] = INT_MAX;
  }

  dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[4] = 4;

  // bottom - up / tabulation approach

  vector<int> sq(n + 1, INT_MAX);
  sq[0] = 0, sq[1] = 1, sq[2] = 2, sq[3] = 3;

  for (int i = 1; i * i <= n; i++) {
    for (int j = 0; i * i + j <= n; j++) {
      sq[i * i + j] = min(sq[i * i + j], 1 + sq[j]);
    }
  }

  cout << minSquares(n, dp) << " " << sq[n] << endl;

  return 0;
}
