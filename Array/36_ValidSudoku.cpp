// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// 
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:
// 
// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
//  
// 
// Example 1:
// 
// 
// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:
// 
// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>> &arr, char ele, int r, int c) {
  int row = r * 3, col = c * 3, count = 0;
  for (int i = row; i < row + 3; i++) {
    for (int j = col; j < col + 3; j++) {
      if (arr[i][j] == ele)
        count++;
      if (count > 1)
        return false;
    }
  }
  return true;
}

bool isValidSudoku(vector<vector<char>> &arr) {
  unordered_map<int, unordered_map<int, int>> row;
  unordered_map<int, unordered_map<int, int>> col;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (arr[i][j] != '.') {
        col[j][arr[i][j]]++;
        row[i][arr[i][j]]++;
      }
    }
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (arr[i][j] != '.') {
        if (row[i][arr[i][j]] > 1 || col[j][arr[i][j]] > 1) {
          return false;
        }
        if (!check(arr, arr[i][j], i / 3, j / 3)) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  vector<vector<char>> arr(9, vector<char>(9));
  for (int i = 0; i < 9; i++) {
    vector<char> temp;
    for (int j = 0; j < 9; j++) {
      char x;
      cin >> x;
      temp.push_back(x);
    }
    arr.push_back(temp);
  }
  cout << isValidSudoku(arr);
  return 0;
}
