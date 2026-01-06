#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> state = {"RYR", "RYG", "RGR", "RGY", "YRY", "YRG",
                          "YGR", "YGY", "GRY", "GRG", "GYR", "GYG"};

  int MOD = 1e9 + 7;

  int solve(int n, int pre, vector<vector<int>> &dp) {
    if (n == 0)
      return 1;
    if (dp[n][pre] != -1)
      return dp[n][pre];
    int res = 0;
    for (int i = 0; i < 12; i++) {
      if (i == pre)
        continue;
      bool check = false;
      for (int j = 0; j < 3; j++) {
        if (state[pre][j] == state[i][j]) {
          check = true;
          break;
        }
      }
      if (check == false) {
        res = (res + solve(n - 1, i, dp) % MOD) % MOD;
      }
    }
    return dp[n][pre] = res;
  }

  int numOfWays(int n) {
    vector<vector<int>> dp(n, vector<int>(12, -1));
    int result = 0;
    for (int i = 0; i < 12; i++) {
      result = (result + solve(n - 1, i, dp) % MOD) % MOD;
    }
    return result;
  }
};

int main() { return 0; }
