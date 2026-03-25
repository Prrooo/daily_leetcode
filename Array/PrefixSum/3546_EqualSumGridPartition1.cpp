// You are given an m x n matrix grid of positive integers. Your task is to
// determine if it is possible to make either one horizontal or one vertical cut
// on the grid such that:
//
//     Each of the two resulting sections formed by the cut is non-empty.
//     The sum of the elements in both sections is equal.
//
// Return true if such a partition exists; otherwise return false.
//
//
//
// Example 1:
//
// Input: grid = [[1,4],[2,3]]
//
// Output: true
//
// Explanation:
//
// A horizontal cut between row 0 and row 1 results in two non-empty sections,
// each with a sum of 5. Thus, the answer is true.
//
// Example 2:
//
// Input: grid = [[1,3],[2,4]]
//
// Output: false
//
// Explanation:
//
// No horizontal or vertical cut results in two non-empty sections with equal
// sums. Thus, the answer is false.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canPartitionGrid(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<long long>> hor(n, vector<long long>(m + 1, 0));
    vector<vector<long long>> ver(n + 1, vector<long long>(m, 0));
    long long total = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        total += grid[i][j];
        hor[i][j + 1] = hor[i][j] + grid[i][j];
        ver[i + 1][j] = ver[i][j] + grid[i][j];
      }
    }

    long long curr = 0;

    for (int i = 0; i < n; i++) {
      curr += hor[i][m];
      long long left = total - curr;
      if (curr == left)
        return true;
      else if (curr > left)
        break;
    }

    curr = 0;

    for (int j = 0; j < m; j++) {
      curr += ver[n][j];
      long long left = total - curr;
      if (curr == left)
        return true;
      else if (curr > left)
        break;
    }

    return false;
  }
};

int main() { return 0; }
