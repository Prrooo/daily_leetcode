// You are given a 2D binary array grid. Find a rectangle with horizontal and
// vertical sides with the smallest area, such that all the 1's in grid lie
// inside this rectangle.
//
// Return the minimum possible area of the rectangle.
//
//
//
// Example 1:
//
// Input: grid = [[0,1,0],[1,0,1]]
//
// Output: 6
//
// Explanation:
//
// The smallest rectangle has a height of 2 and a width of 3, so it has an area
// of 2 * 3 = 6.
//
// Example 2:
//
// Input: grid = [[1,0],[0,0]]
//
// Output: 1
//
// Explanation:
//
// The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.
//
//

#include <bits/stdc++.h>
using namespace std;

int minimumArea(vector<vector<int>> &grid) {
  int colTop = INT_MAX, colBot = INT_MIN;
  int rowLeft = INT_MAX, rowRight = INT_MIN;
  int n = grid.size(), m = grid[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        colTop = min(colTop, i);
        colBot = max(colBot, i);
        rowLeft = min(rowLeft, j);
        rowRight = max(rowRight, j);
      }
    }
  }
  return (colBot - colTop + 1) * (rowRight - rowLeft + 1);
}

int main() { return 0; }
