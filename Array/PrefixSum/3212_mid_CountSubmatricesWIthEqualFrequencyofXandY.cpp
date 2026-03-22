// Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or
// '.', return the number of that contain:
//
//     grid[0][0]
//     an equal frequency of 'X' and 'Y'.
//     at least one 'X'.
//
//
//
// Example 1:
//
// Input: grid = [["X","Y","."],["Y",".","."]]
//
// Output: 3
//
// Explanation:
//
// Example 2:
//
// Input: grid = [["X","X"],["X","Y"]]
//
// Output: 0
//
// Explanation:
//
// No submatrix has an equal frequency of 'X' and 'Y'.
//
// Example 3:
//
// Input: grid = [[".","."],[".","."]]
//
// Output: 0
//
// Explanation:
//
// No submatrix has at least one 'X'.

#include <bits/stdc++.h>
using namespace std;

// time complexity O(n*m) and space complexity O(n*m)

class Solution {
public:
  int numberOfSubmatrices(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<pair<int, int>>> preSum(
        n + 1, vector<pair<int, int>>(m + 1, {0, 0}));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        preSum[i][j] = preSum[i][j - 1];
        preSum[i][j].first += (grid[i - 1][j - 1] == 'X' ? 1 : 0);
        preSum[i][j].second += (grid[i - 1][j - 1] == 'Y' ? 1 : 0);
      }
    }

    int ans = 0;

    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        preSum[i][j].first = preSum[i][j].first + preSum[i - 1][j].first;
        preSum[i][j].second = preSum[i][j].second + preSum[i - 1][j].second;
        if (preSum[i][j].first == preSum[i][j].second &&
            preSum[i][j].first != 0) {
          ans++;
        }
      }
    }

    return ans;
    return 0;
  }
};

int main() { return 0; }
