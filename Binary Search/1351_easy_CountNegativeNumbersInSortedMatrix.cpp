#include <bits/stdc++.h>
using namespace std;

// brute force solutoin
// complexity O(n*m)
// space complexity O(1)

class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size(), count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] < 0) {
          count += m - j;
          break;
        }
      }
    }
    return count;
  }
};

// soluton using binary search
// optimal then before
// time complexity O(mLogn)

class Solution1 {
public:
  int solve(vector<int> &grid, int m) {
    int low = 0, high = m - 1, ans = m;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (grid[mid] < 0) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return m - ans;
  }

  int countNegatives(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size(), count = 0;
    for (int i = 0; i < n; i++) {
      count += solve(grid[i], m);
    }
    return count;
  }
};

int main() { return 0; }
