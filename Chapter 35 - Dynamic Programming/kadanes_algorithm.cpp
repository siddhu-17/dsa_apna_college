// Maximum subarray sum: We are given an array. Our task is to find the maximum sum of subarray which can be found using the above array.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pair<int, int>>

int main()
{
  int n;
  cin >> n;

  vi nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int curr = 0, mx = 0;

  for (int i = 0; i < n; i++) {
    curr += nums[i];
    mx = max(mx, curr);

    if (curr < 0) curr = 0;
  }

  cout << mx << endl;

  return 0;
}
