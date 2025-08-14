#include <bits/stdc++.h>
#include <cmath>
#include <utility>
using namespace std;

// work but TLE

class Solution {
public:
  void solve(int n, int x, int start, int sum, int &ans) {
    if (start <= 0) {
      if (sum == n)
        ans++;
      return;
    } else if (sum > n)
      return;
    if (sum == n) {
      ans++;
      return;
    }
    solve(n, x, start - 1, sum + pow(start, x), ans);
    solve(n, x, start - 1, sum, ans);
  }

  int numberOfWays(int n, int x) {
    int ans = 0;
    if (x == 1 || n == 1) {
      solve(n, x, n, 0, ans);
      return ans;
    }
    solve(n, x, n / 2, 0, ans);
    return ans;
  }
};

// solution using DP

int numberOfWays(int n, int x) {
  long long mod = 1e9 + 7;
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    long long val = pow(i, x);
    for (int j = 0; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= val) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - val]) % mod;
      }
    }
  }
  return dp[n][n];
}

int main() { return 0; }
