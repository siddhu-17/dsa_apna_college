#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5+2, MOD = 1e9+7;
long long dp[N];

long long memoizedFib (int n) {
  if (n == 0 || n == 1) return 0;
  if (n == 2) return 1;

  if (dp[n] != -1) return dp[n];

  return dp[n] = memoizedFib(n - 1) + memoizedFib(n - 2);
}

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < N; i++) dp[i] = -1;

  vector<long long> fib(n + 1);

  fib[0] = 0;
  fib[1] = 0;
  fib[2] = 1;   // this will cause segmentation fault for input 0

  for (int i = 3; i <= n; i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }

  cout << memoizedFib(n) << endl;
  cout << fib[n] << endl;

  return 0;
}
