// Given an n x n binary grid, in one step you can choose two adjacent rows of
// the grid and swap them.
//
// A grid is said to be valid if all the cells above the main diagonal are
// zeros.
//
// Return the minimum number of steps needed to make the grid valid, or -1 if
// the grid cannot be valid.
//
// The main diagonal of a grid is the diagonal that starts at cell (1, 1) and
// ends at cell (n, n).
//
//
//
// Example 1:
//
// Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
// Output: 3
//
// Example 2:
//
// Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
// Output: -1
// Explanation: All rows are similar, swaps have no effect on the grid.
//
// Example 3:
//
// Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
// Output: 0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int find_index(vector<int> &nums, int target, int index, int n) {
    for (int i = index; i < n; i++) {
      if (nums[i] >= target)
        return i;
    }
    return -1;
  }

  int minSwaps(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> zeroCount;

    for (int i = 0; i < n; i++) {
      int count = 0;
      for (int j = n - 1; j >= 0; j--) {
        if (grid[i][j] == 0)
          count++;
        else
          break;
      }
      zeroCount.push_back(count);
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (zeroCount[i] < (n - 1 - i)) {
        int idx = find_index(zeroCount, n - 1 - i, i + 1, n);
        if (idx == -1)
          return -1;
        for (int j = idx; j > i; j--) {
          int temp = zeroCount[j - 1];
          zeroCount[j - 1] = zeroCount[j];
          zeroCount[j] = temp;
          ans++;
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
