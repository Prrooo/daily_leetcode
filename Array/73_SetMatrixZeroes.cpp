#include <bits/stdc++.h>
#include <utility>
using namespace std;

void solve(vector<vector<int>> &matrix, int row, int col, int n, int j) {
  for (int i = 0; i < j; i++) {
    matrix[row][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    matrix[i][col] = 0;
  }
}

void setZeroes(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  vector<pair<int, int>> toZero;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 0) {
        toZero.push_back(make_pair(i, j));
      }
    }
  }
  for (auto i : toZero) {
    solve(matrix, i.first, i.second, n, m);
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> arr;
  for (int i = 0; i < n; i++) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    arr.push_back(temp);
  }
  return 0;
}
