#include <bits/stdc++.h>
using namespace std;

// There is an m x n rectangular island that borders both the Pacific Ocean and
// Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
// and the Atlantic Ocean touches the island's right and bottom edges.
//
// The island is partitioned into a grid of square cells. You are given an m x n
// integer matrix heights where heights[r][c] represents the height above sea
// level of the cell at coordinate (r, c).
//
// The island receives a lot of rain, and the rain water can flow to neighboring
// cells directly north, south, east, and west if the neighboring cell's height
// is less than or equal to the current cell's height. Water can flow from any
// cell adjacent to an ocean into the ocean.
//
// Return a 2D list of grid coordinates result where result[i] = [ri, ci]
// denotes that rain water can flow from cell (ri, ci) to both the Pacific and
// Atlantic oceans.
//
//
//
// Example 1:
//
// Input: heights =
// [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]] Output:
// [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]] Explanation: The following cells
// can flow to the Pacific and Atlantic oceans, as shown below: [0,4]: [0,4] ->
// Pacific Ocean
//        [0,4] -> Atlantic Ocean
// [1,3]: [1,3] -> [0,3] -> Pacific Ocean
//        [1,3] -> [1,4] -> Atlantic Ocean
// [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
//        [1,4] -> Atlantic Ocean
// [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
//        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
// [3,0]: [3,0] -> Pacific Ocean
//        [3,0] -> [4,0] -> Atlantic Ocean
// [3,1]: [3,1] -> [3,0] -> Pacific Ocean
//        [3,1] -> [4,1] -> Atlantic Ocean
// [4,0]: [4,0] -> Pacific Ocean
//        [4,0] -> Atlantic Ocean
// Note that there are other possible paths for these cells to flow to the
// Pacific and Atlantic oceans.
//
// Example 2:
//
// Input: heights = [[1]]
// Output: [[0,0]]
// Explanation: The water can flow from the only cell to the Pacific and
// Atlantic oceans.
//

class Solution {
public:
  int n, m;
  vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void dfs(vector<vector<int>> &heights, int i, int j,
           vector<vector<bool>> &vis) {
    if (vis[i][j])
      return;
    vis[i][j] = true;

    for (auto &a : direction) {
      int x = i + a[0], y = j + a[1];
      if (x < 0 || x >= n || y < 0 || y >= m)
        continue;
      if (heights[x][y] < heights[i][j])
        continue;
      dfs(heights, x, y, vis);
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    n = heights.size(), m = heights[0].size();
    vector<vector<bool>> pacific(n, vector<bool>(m, false));
    vector<vector<bool>> atlantic(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
      dfs(heights, i, 0, pacific);
      dfs(heights, i, m - 1, atlantic);
    }
    for (int j = 0; j < m; j++) {
      dfs(heights, 0, j, pacific);
      dfs(heights, n - 1, j, atlantic);
    }
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (pacific[i][j] && atlantic[i][j]) {
          res.push_back({i, j});
        }
      }
    }
    return res;
  }
};

int main() { return 0; }
