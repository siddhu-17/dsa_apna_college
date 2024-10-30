/* Properties of Dynamic Programming

-> Optimal substructure: if we can write a recurrence relation, then a problem is said to have optimal substructure
-> Overlapping subproblems: if our subproblems repeat, then a problem is said to have overlapping subproblems

Ways to handle Overlapping Subproblems

-> Memoization (top-down): a lookup table is maintained and checked before computation of any state, recursion is involved
-> Tabulation (bottom-up): solution will be built from base, it is an iterative process

Key Points

-> Minimization and maximization problems are generally solved with DP where we want exhaustive solution (sometimes with binary search on answers)
-> Find the number of ways is also a very popular type of DP problems
-> Wherever we can form a recurrence relation or given in question, those problems can be solved using DP (sometimes using matrix exponentiation) */

#include <iostream>
#include <vector>
using namespace std;

int fib[200] = {-1};

int memozationFib (int n) {
  if (n == 0 || n == 1) return n;
  if (fib[n] != -1) return fib[n];

  fib[n] = fib[n-1] + fib[n-2];

  return fib[n];
}

int main()
{
  int n;
  cin >> n;

  vector<int> fib(n + 1);
  fib[1] = 0, fib[2] = 1;

  for (int i = 3; i <= n; i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }

  cout << fib[n] << endl;

  return 0;
}
