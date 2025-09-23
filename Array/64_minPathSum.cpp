// Given a m x n grid filled with non-negative numbers, find a path from top
// left to bottom right, which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
//
//
// Example 1:
//
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
//
// Example 2:
//
// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
//

#include <bits/stdc++.h>
using namespace std;

// best solution my meeee hehehehe

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int top = (i - 1 >= 0) ? grid[i][j] + dp[i - 1][j] : INT_MAX;
        int right = (j - 1 >= 0) ? grid[i][j] + dp[i][j - 1] : INT_MAX;
        dp[i][j] = min(dp[i][j], top);
        dp[i][j] = min(dp[i][j], right);
      }
    }
    return dp[n - 1][m - 1];
  }
};

// one solution without dp
// error TLE

void solve(vector<vector<int>> &grid, int i, int j, int n, int m, int temp,
           int &ans) {
  if (i >= n - 1 && j >= m - 1) {
    temp += grid[i][j];
    ans = min(ans, temp);
    return;
  } else if (i >= n || j >= m)
    return;
  temp += grid[i][j];
  solve(grid, i, j + 1, n, m, temp, ans);
  solve(grid, i + 1, j, n, m, temp, ans);
}

int minPathSum(vector<vector<int>> &grid) {
  int n = grid.size(), m = grid[0].size(), ans = INT_MAX;
  solve(grid, 0, 0, n, m, 0, ans);
  return ans;
}

int main() { return 0; }
