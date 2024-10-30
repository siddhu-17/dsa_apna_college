// Given an array of items with their { weights, value } and a kanpsack with capacity W. Find the maximum value of items that can be stolen and put into the knapsack.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pair<int, int>>

const int N = 1e3+2;

// recursive solution

int knapsack (int n, int w, vi &wt, vi &val) {
  if (w <= 0 || n <= 0) return 0;

  if (wt[n - 1] > w) {
    return knapsack(n - 1, w, wt, val);
  }

  return max(knapsack(n - 1, w, wt, val), knapsack(n - 1, w - wt[n - 1], wt, val) + val[n - 1]);
}

// memoized solution

int dp[N][N];

int knapsackMemo (int n, int w, vi &wt, vi &val) {
  if (w <= 0 || n <= 0) return 0;

  if (dp[n][w] != -1) return dp[n][w];

  if (wt[n - 1] > w) {
    return dp[n][w] = knapsack(n - 1, w, wt, val);
  }
  
  else return dp[n][w] = max(knapsack(n - 1, w, wt, val), knapsack(n - 1, w - wt[n - 1], wt, val) + val[n - 1]);
}

int main()
{
  int n;
  cin >> n;

  vi wt(n), val(n);

  for (int i = 0; i < n; i++) cin >> wt[i];
  for (int i = 0; i < n; i++) cin >> val[i];

  int w;
  cin >> w;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) dp[i][j] = -1;
  }

  cout << knapsack(n, w, wt, val) << endl;
  cout << knapsackMemo(n, w, wt, val) << endl;

  return 0;
}
