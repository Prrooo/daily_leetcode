// There is a robot on an m x n grid. The robot is initially located at the
// top-left corner (i.e., grid[0][0]). The robot tries to move to the
// bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move
// either down or right at any point in time.
//
// Given the two integers m and n, return the number of possible unique paths
// that the robot can take to reach the bottom-right corner.
//
// The test cases are generated so that the answer will be less than or equal to
// 2 * 109.
//
// Example 1:
//
// Input: m = 3, n = 7
// Output: 28
// Example 2:
//
// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach
// the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

#include <bits/stdc++.h>
using namespace std;

// best solution using math

int uniquePaths(int m,int n){
  return 0;
}

// ok ok solution time complexity O(n*m) and space complexity O(n*m) 
// using DP

// int solve(vector<vector<int>> &dp, int row, int col, int m, int n) {
//   if (row == (m - 1) && col == (n - 1))
//     return 1;
//   if (row >= m || col >= n)
//     return 0;
//   if (dp[row][col] != -1)
//     return dp[row][col];
//   else
//     return dp[row][col] =
//                solve(dp, row + 1, col, m, n) + solve(dp, row, col + 1, m, n);
// }
// 
// int uniquePaths(int m, int n) {
//   vector<vector<int>> dp(m, vector<int>(n, -1));
//   dp[m - 1][n - 1] = 1;
//   solve(dp, 0, 0, m, n);
//   return dp[0][0];
// }

int main() {
  int n, m;
  cin >> m >> n;
  cout << uniquePaths(m, n);
  return 0;
}
