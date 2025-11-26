#include <bits/stdc++.h>
using namespace std;

// I solve it on my onw hahahahahahahaahh

class Solution {
public:
  int modVal = 1e9 + 7;
  int solve(int i, int j, int rem, vector<vector<int>> &grid,
            vector<vector<vector<int>>> &dp, int k, int n, int m) {
    if (i >= n || j >= m)
      return 0;
    if (i == (n - 1) && j == (m - 1)) {
      rem = (rem + grid[i][j]) % k;
      if (rem == 0)
        return 1;
      return 0;
    }
    if (dp[i][j][rem] != -1)
      return dp[i][j][rem];
    int right = solve(i, j + 1, (rem + grid[i][j]) % k, grid, dp, k, n, m);
    int down = solve(i + 1, j, (rem + grid[i][j]) % k, grid, dp, k, n, m);
    return dp[i][j][rem] = (right + down) % modVal;
  }

  int numberOfPaths(vector<vector<int>> &grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(m, vector<int>(k, -1)));
    return solve(0, 0, 0, grid, dp, k, n, m);
  }
};

int main() { return 0; }
