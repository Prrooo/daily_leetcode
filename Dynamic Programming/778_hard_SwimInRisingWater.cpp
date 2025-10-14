#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size(), ans = grid[0][0];
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    queue<pair<int, int>> qu;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    qu.push({0, 0});
    while (!qu.empty()) {
      int row = qu.front().first, col = qu.front().second;
      qu.pop();
      vis[row][col] = true;
      int newX, newY, temp = INT_MAX;
      for (int i = 0; i < 4; i++) {
        int x = row + dir[i][0], y = col + dir[i][1];
        if (x < 0 || y < 0 || x >= n || y >= n)
          continue;
        if (vis[x][y])
          continue;
        if (temp > grid[x][y]) {
          temp = grid[x][y];
          newX = x, newY = y;
        }
      }
      ans += temp;
      qu.push({newX, newY});
    }
    return ans;
  }
};

// work but error TLE

class Solution {
public:
  vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int solve(vector<vector<int>> &grid, vector<vector<bool>> &vis, int temp,
            int row, int col, int n, int &ans) {
    if (row == n - 1 && col == n - 1) {
      return min(ans, temp);
    }
    if (vis[row][col]) {
      return -1;
    }
    vis[row][col] = true;
    for (int i = 0; i < 4; i++) {
      int x = row + dir[i][0], y = col + dir[i][1];
      if (x < 0 || y < 0 || x >= n || y >= n)
        continue;
      if (vis[x][y])
        continue;
      int a = solve(grid, vis, max(temp, grid[x][y]), x, y, n, ans);
      if (a == -1) {
        continue;
      }
      ans = min(ans, a);
    }
    vis[row][col] = false;
    return ans;
  }

  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();
    int ans = INT_MAX;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    solve(grid, vis, grid[0][0], 0, 0, n, ans);
    return ans;
  }
};

int main() { return 0; }
