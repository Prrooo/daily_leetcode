// You are given an m x n integer matrix grid and an integer k.
//
// For every contiguous k x k submatrix of grid, compute the minimum absolute
// difference between any two distinct values within that submatrix.
//
// Return a 2D array ans of size (m - k + 1) x (n - k + 1), where ans[i][j] is
// the minimum absolute difference in the submatrix whose top-left corner is (i,
// j) in grid.
//
// Note: If all elements in the submatrix have the same value, the answer will
// be 0. A submatrix (x1, y1, x2, y2) is a matrix that is formed by choosing all
// cells matrix[x][y] where x1 <= x <= x2 and y1 <= y <= y2.
//
//
//
// Example 1:
//
// Input: grid = [[1,8],[3,-2]], k = 2
//
// Output: [[2]]
//
// Explanation:
//
//     There is only one possible k x k submatrix: [[1, 8], [3, -2]].
//     Distinct values in the submatrix are [1, 8, 3, -2].
//     The minimum absolute difference in the submatrix is |1 - 3| = 2. Thus,
//     the answer is [[2]].
//
// Example 2:
//
// Input: grid = [[3,-1]], k = 1
//
// Output: [[0,0]]
//
// Explanation:
//
//     Both k x k submatrix has only one distinct element.
//     Thus, the answer is [[0, 0]].
//
// Example 3:
//
// Input: grid = [[1,-2,3],[2,3,5]], k = 2
//
// Output: [[1,2]]
//
// Explanation:
//
//     There are two possible k × k submatrix:
//         Starting at (0, 0): [[1, -2], [2, 3]].
//             Distinct values in the submatrix are [1, -2, 2, 3].
//             The minimum absolute difference in the submatrix is |1 - 2| = 1.
//         Starting at (0, 1): [[-2, 3], [3, 5]].
//             Distinct values in the submatrix are [-2, 3, 5].
//             The minimum absolute difference in the submatrix is |3 - 5| = 2.
//     Thus, the answer is [[1, 2]].
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int solve(vector<vector<int>> &grid, int k, int row, int col) {
    vector<int> arr;
    for (int i = row; i < row + k; i++) {
      for (int j = col; j < col + k; j++) {
        arr.push_back(grid[i][j]);
      }
    }
    int n = arr.size();
    if (n == 1)
      return 0;
    sort(arr.begin(), arr.end());
    int first = arr[0], ans = INT_MAX;
    for (int i = 1; i < n; i++) {
      if (arr[i] == first)
        continue;
      ans = min(ans, abs(first - arr[i]));
      first = arr[i];
    }
    return ans == INT_MAX ? 0 : ans;
  }

  vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
    int n1 = ans.size(), m1 = ans[0].size();
    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < m1; j++) {
        ans[i][j] = solve(grid, k, i, j);
      }
    }
    return ans;
  }
};

int main() { return 0; }
