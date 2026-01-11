#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findSum(int index, string &s, int n) {
    int temp = 0;
    for (int i = index; i < n; i++) {
      temp += s[i];
    }
    return temp;
  }

  int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp,
            int n, int m) {
    if (i >= n && j >= m)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];
    if (i >= n) {
      return dp[i][j] = findSum(j, s2, m);
    } else if (j >= m) {
      return dp[i][j] = findSum(i, s1, n);
    }

    int ans = 1e9;
    if (s1[i] == s2[j]) {
      ans = min(ans, solve(i + 1, j + 1, s1, s2, dp, n, m));
    } else {
      int witout = s1[i] + s2[j] + solve(i + 1, j + 1, s1, s2, dp, n, m);
      int left = s1[i] + solve(i + 1, j, s1, s2, dp, n, m);
      int right = s2[j] + solve(i, j + 1, s1, s2, dp, n, m);
      ans = min({ans, witout, left, right});
    }
    return dp[i][j] = ans;
  }

  int minimumDeleteSum(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(0, 0, s1, s2, dp, n, m);
  }
};

int main() { return 0; }
