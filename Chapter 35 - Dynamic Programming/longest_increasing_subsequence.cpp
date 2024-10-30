/*
  You are given an array. Find the length of longest increasing subsequence. We define Lis(i) = length of longest increasing subsequence ending at 'ith' element, therefore, Lis depends on Lis(k), where 0 <= k <= i-1.

  if (a[i] > a[k]) Lis(i) = max(Lis(i), Lis(k) + 1)
*/

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pair<int, int>>

// top - down / memoization approach

int lis (vi &nums, int n, vi &dp) {
  if (dp[n] != -1) return dp[n];

  dp[n] = 1;   // single element subsequence

  for (int i = 0; i < n; i++) {
    if (nums[n] > nums[i]) dp[n] = max(dp[n], lis(nums, i, dp) + 1);
  }

  return dp[n];
}

int main()
{
  int n;
  cin >> n;

  vi nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vi dp(n, -1);

  cout << lis(nums, n - 1, dp) << endl;

  // bottom - up / tabulation solution

  dp.assign(n, 1);
  int ans = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
    }

    ans = max(ans, dp[i]);
  }

  cout << ans << endl;

  return 0;
}
