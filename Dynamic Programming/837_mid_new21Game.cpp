#include <bits/stdc++.h>
using namespace std;

// best solution out of all using sliding window and dp

class Solution {
public:
  double new21Game(int n, int k, int maxPts) {
    vector<double> dp(n + 1);
    dp[0] = 1;
    double s = k > 0 ? 1 : 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = s / maxPts;
      if (i < k) {
        s += dp[i];
      }
      if (i - maxPts >= 0 && i - maxPts < k) {
        s -= dp[i - maxPts];
      }
    }
    return accumulate(dp.begin() + k, dp.end(), 0.0);
  }
};

// fast then solution 2 but still TLE

class Solution1 {
public:
  double solve(int n, int k, int maxPt, int curr, vector<double> &dp) {
    if (curr >= k && curr <= n) {
      dp[curr] = 1;
      return 1;
    } else if (curr >= k && curr > n) {
      dp[curr] = 0;
      return 0;
    }

    if (dp[curr] != -1)
      return dp[curr];
    double ans = 0;
    for (int i = 1; i <= maxPt; i++) {
      ans += solve(n, k, maxPt, curr + i, dp);
    }
    dp[curr] = ans / maxPt;
    return dp[curr];
  }

  double new21Game(int n, int k, int maxPts) {
    vector<double> dp(k + maxPts + 1, -1);
    return solve(n, k, maxPts, 0, dp);
  }
};

// solution using recursion and dp
// faster the previous but still TLE

class Solution2 {
public:
  double solve(int n, int k, int maxPt, int curr,
               unordered_map<int, double> &dp) {
    if (curr >= k && curr <= n) {
      dp[curr] = 1;
      return 1;
    } else if (curr >= k && curr > n) {
      dp[curr] = 0;
      return 0;
    }

    if (dp.find(curr) != dp.end())
      return dp[curr];
    double ans = 0;
    for (int i = 1; i <= maxPt; i++) {
      ans += solve(n, k, maxPt, curr + i, dp);
    }
    dp[curr] = ans / maxPt;
    return dp[curr];
  }

  double new21Game(int n, int k, int maxPts) {
    unordered_map<int, double> dp;
    return solve(n, k, maxPts, 0, dp);
  }
};

// works but TLE

double solve(int n, int k, int maxPt, int curr) {
  if (curr >= k && curr <= n)
    return 1;
  else if (curr >= k && curr > n)
    return 0;
  double ans = 0;
  for (int i = 1; i <= maxPt; i++) {
    ans += solve(n, k, maxPt, curr + i);
  }
  return ans / maxPt;
}

double new21Game(int n, int k, int maxPts) { return solve(n, k, maxPts, 0); }

int main() { return 0; }
