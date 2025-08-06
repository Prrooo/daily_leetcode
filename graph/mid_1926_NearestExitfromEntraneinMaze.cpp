//
// You are given an m x n matrix maze (0-indexed) with empty cells (represented
// as '.') and walls (represented as '+'). You are also given the entrance of
// the maze, where entrance = [entrancerow, entrancecol] denotes the row and
// column of the cell you are initially standing at.
//
// In one step, you can move one cell up, down, left, or right. You cannot step
// into a cell with a wall, and you cannot step outside the maze. Your goal is
// to find the nearest exit from the entrance. An exit is defined as an empty
// cell that is at the border of the maze. The entrance does not count as an
// exit.
//
// Return the number of steps in the shortest path from the entrance to the
// nearest exit, or -1 if no such path exists.
//
// Example 1:
//
//
// Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]],
// entrance = [1,2] Output: 1 Explanation: There are 3 exits in this maze at
// [1,0], [0,2], and [2,3]. Initially, you are at the entrance cell [1,2].
// - You can reach [1,0] by moving 2 steps left.
// - You can reach [0,2] by moving 1 step up.
// It is impossible to reach [2,3] from the entrance.
// Thus, the nearest exit is [0,2], which is 1 step away.
// Example 2:
//
//
// Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
// Output: 2
// Explanation: There is 1 exit in this maze at [1,2].
// [1,0] does not count as an exit since it is the entrance cell.
// Initially, you are at the entrance cell [1,0].
// - You can reach [1,2] by moving 2 steps right.
// Thus, the nearest exit is [1,2], which is 2 steps away.
// Example 3:
//
//
// Input: maze = [[".","+"]], entrance = [0,0]
// Output: -1
// Explanation: There are no exits in this maze.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // best solution
  int nearestExit(vector<vector<char>> &maze, vector<int> entrance) {
    queue<pair<int, int>> qu;
    int count = 0, rowSize = maze.size(), colSize = maze[0].size();
    qu.push(make_pair(entrance[0], entrance[1]));
    while (!qu.empty()) {
      int n = qu.size();
      count++;
      for (int i = 0; i < n; i++) {
        int row = qu.front().first, col = qu.front().second;
        qu.pop();
        if ((maze[row][col] == '.') && (row == 0 || row == (rowSize - 1) ||
                                        col == 0 || col == (colSize - 1))) {
          return count;
        }
        maze[row][col] = '+';
        if ((col + 1) < colSize && maze[row][col + 1] == '.') {
          qu.push(make_pair(row, col + 1));
        }
        if ((col - 1) >= 0 && maze[row][col - 1] == '.') {
          qu.push(make_pair(row, col - 1));
        }
        if ((row - 1) >= 0 && maze[row - 1][col] == '.') {
          qu.push(make_pair(row - 1, col));
        }
        if ((row + 1) < rowSize && maze[row + 1][col] == '.') {
          qu.push(make_pair(row + 1, col));
        }
      }
    }
    return -1;
  }

  // dp solution not best TLE
  // int solve(vector<vector<int>> &dp, vector<vector<char>> maze,
  //           vector<int> &start, int i, int j, int step, int row, int col) {
  //   if (i >= row || i < 0 || j >= col || j < 0 || maze[i][j] == '+') {
  //     return INT_MAX;
  //   }
  //   if (dp[i][j] != -1 && dp[i][j] != INT_MAX) {
  //     return step + dp[i][j];
  //   } else if (dp[i][j] == INT_MAX)
  //     return INT_MAX;
  //   else if ((i == 0 || j == 0 || i == row - 1 || j == col - 1) &&
  //            (i != start[0] || j != start[1])) {
  //     dp[i][j] = 0;
  //     return step;
  //   }
  //   maze[i][j] = '+';
  //   int left = solve(dp, maze, start, i, j - 1, step + 1, row, col);
  //   int right = solve(dp, maze, start, i, j + 1, step + 1, row, col);
  //   int up = solve(dp, maze, start, i - 1, j, step + 1, row, col);
  //   int down = solve(dp, maze, start, i + 1, j, step + 1, row, col);
  //   int ans = min(left, min(right, min(up, down)));
  //   if (ans == INT_MAX) {
  //     dp[i][j] = INT_MAX;
  //     return ans;
  //   }
  //   dp[i][j] = ans - step;
  //   return ans;
  // }

  // int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
  //   int n = maze.size(), m = maze[0].size();
  //   vector<vector<int>> dp(n, vector<int>(m, -1));
  //   int ans = solve(dp, maze, entrance, entrance[0], entrance[1], 0, n, m);
  //   return ans == INT_MAX ? -1 : ans;
  // }
};

int main() { return 0; }
