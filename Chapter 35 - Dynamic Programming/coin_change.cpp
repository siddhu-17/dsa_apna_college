// Given a set of coins and a value V. Find the number of ways we can make change of V.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pair<int, int>>

// recursive solution

int coinChange (vi &coins, int n, int value) {
  if (n <= 0 || value < 0) return 0;
  if (value == 0) return 1;

  return coinChange(coins, n, value - coins[n-1]) + coinChange(coins, n-1, value);
}

// memoized solution

const int N = 1e3+2;
int dp[N][N];

int coinChangeMemo (vi &coins, int n, int value) {
  if (n <= 0 || value < 0) return 0;
  if (value == 0) return 1;

  if (dp[n][value] != -1) return dp[n][value];

  dp[n][value] = coinChange(coins, n, value - coins[n-1]) + coinChange(coins, n-1, value);

  return dp[n][value];
}

int main()
{
  int n, value;
  cin >> n >> value;

  vi coins(n);

  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = -1;
    }
  }

  cout << coinChangeMemo(coins, n, value) << endl;

  // tabulated solution

  vvi ch (n + 1, vi(value + 1, 0));
  ch[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= value; j++) {
      ch[i][j] += ch[i - 1][j];    // not using the current coin
      if (j - coins[i - 1] >= 0) ch[i][j] += ch[i][j - coins[i - 1]];    // using the current coin
    }
  }

  cout << ch[n][value] << endl;

  return 0;
}
