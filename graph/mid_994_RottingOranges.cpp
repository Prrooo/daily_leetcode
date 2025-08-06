// You are given an m x n grid where each cell can have one of three values:
//
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten
// orange becomes rotten.
//
// Return the minimum number of minutes that must elapse until no cell has a
// fresh orange. If this is impossible, return -1.
//
// Example 1:
//
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:
//
// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never
// rotten, because rotting only happens 4-directionally. Example 3:
//
// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer
// is just 0.
//

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid) {
  queue<pair<int, int>> qu;
  int n = grid.size(), m = grid[0].size(), good = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 2) {
        qu.push(make_pair(i, j));
      } else if (grid[i][j] == 1) {
        good++;
      }
    }
  }
  while (!qu.empty() && good > 0) {
    int sz = qu.size();
    ans++;
    for (int i = 0; i < sz; i++) {
      int row = qu.front().first, col = qu.front().second;
      qu.pop();
      if ((col + 1) < m && grid[row][col + 1] == 1) {
        qu.push(make_pair(row, col + 1));
        grid[row][col + 1] = 2;
        good--;
      }
      if ((col - 1) >= 0 && grid[row][col - 1] == 1) {
        qu.push(make_pair(row, col - 1));
        grid[row][col - 1] = 2;
        good--;
      }
      if ((row - 1) >= 0 && grid[row - 1][col] == 1) {
        qu.push(make_pair(row - 1, col));
        grid[row - 1][col] = 2;
        good--;
      }
      if ((row + 1) < n && grid[row + 1][col] == 1) {
        qu.push(make_pair(row + 1, col));
        grid[row + 1][col] = 2;
        good--;
      }
    }
  }
  return good > 0 ? -1 : ans;
}

int main() { return 0; }
