#include <bits/stdc++.h>
using namespace std;

// best solution

class bestSolution {
public:
  bool betterSolve(vector<vector<char>> &board, vector<vector<int>> &row,
                   vector<vector<int>> &col, vector<vector<int>> &box) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          for (int x = 1; x <= 9; x++) {
            if (row[i][x] == 0 && col[j][x] == 0 &&
                box[3 * (i / 3) + (j / 3)][x] == 0) {
              row[i][x] = 1;
              col[j][x] = 1;
              box[3 * (i / 3) + (j / 3)][x] = 1;
              board[i][j] = x + '0';
              if (betterSolve(board, row, col, box))
                return true;
              row[i][x] = 0;
              col[j][x] = 0;
              box[3 * (i / 3) + (j / 3)][x] = 0;
              board[i][j] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }

  void solveSudoku(vector<vector<char>> &board) {
    vector<vector<int>> row(9, vector<int>(10, 0)), col(9, vector<int>(10, 0)),
        box(9, vector<int>(10, 0));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          row[i][board[i][j] - '0']++;
          col[j][board[i][j] - '0']++;
          box[3 * (i / 3) + (j / 3)][board[i][j] - '0']++;
        }
      }
    }
    betterSolve(board, row, col, box);
  }
};

// work fine

class Solution {
public:
  bool solve(vector<vector<char>> &board, vector<vector<int>> &row,
             vector<vector<int>> &col, vector<vector<int>> &box, int i, int j) {
    if (i >= 9 || j >= 9)
      return true;
    if (board[i][j] != '.') {
      if (j >= 8) {
        if (solve(board, row, col, box, i + 1, 0))
          return true;
      } else if (solve(board, row, col, box, i, j + 1))
        return true;
      return false;
    }
    for (int x = 1; x <= 9; x++) {
      if (row[i][x] == 0 && col[j][x] == 0 &&
          box[3 * (i / 3) + (j / 3)][x] == 0) {
        row[i][x] = 1;
        col[j][x] = 1;
        box[3 * (i / 3) + (j / 3)][x] = 1;
        board[i][j] = x + '0';
        if (j >= 8) {
          if (solve(board, row, col, box, i + 1, 0))
            return true;
        } else if (solve(board, row, col, box, i, j + 1))
          return true;
        row[i][x] = 0;
        col[j][x] = 0;
        box[3 * (i / 3) + (j / 3)][x] = 0;
        board[i][j] = '.';
      }
    }
    return false;
  }

  void solveSudoku(vector<vector<char>> &board) {
    vector<vector<int>> row(9, vector<int>(10, 0)), col(9, vector<int>(10, 0)),
        box(9, vector<int>(10, 0));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          row[i][board[i][j] - '0']++;
          col[j][board[i][j] - '0']++;
          box[3 * (i / 3) + (j / 3)][board[i][j] - '0']++;
        }
      }
    }
    solve(board, row, col, box, 0, 0);
  }
};

int main() { return 0; }
