// The n-queens puzzle is the problem of placing n queens on an n x n chessboard
// such that no two queens attack each other.
//
// Given an integer n, return all distinct solutions to the n-queens puzzle. You
// may return the answer in any order.
//
// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space,
// respectively.
//
//
//
// Example 1:
//
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as
// shown above
//
// Example 2:
//
// Input: n = 1
// Output: [["Q"]]
//
// V

#include <bits/stdc++.h>
using namespace std;

// solve using backtracking also refere page 50 in the cp book for reference

class Solution {
public:
  void search(int n, vector<vector<string>> &res, vector<int> column,
              vector<int> diag1, vector<int> diag2, vector<string> temp,
              int y) {
    if (y == n) {
      res.push_back(temp);
      return;
    }
    for (int x = 0; x < n; x++) {
      if (column[x] || diag1[x + y] || diag2[x - y + n - 1])
        continue;
      column[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
      temp[y][x] = 'Q';
      search(n, res, column, diag1, diag2, temp, y + 1);
      temp[y][x] = '.';
      column[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> col(n, 0), dig1(n * 2, 0), dig2(n * 2, 0);
    vector<string> temp(n, string(n, '.'));
    search(n, res, col, dig1, dig2, temp, 0);
    return res;
  }
};

int main() { return 0; }
