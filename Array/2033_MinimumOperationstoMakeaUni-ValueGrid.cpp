// You are given a 2D integer grid of size m x n and an integer x. In one
// operation, you can add x to or subtract x from any element in the grid.
//
// A uni-value grid is a grid where all the elements of it are equal.
//
// Return the minimum number of operations to make the grid uni-value. If it is
// not possible, return -1.
//
// Example 1:
//
// Input: grid = [[2,4],[6,8]], x = 2
// Output: 4
// Explanation: We can make every element equal to 4 by doing the following:
// - Add x to 2 once.
// - Subtract x from 6 once.
// - Subtract x from 8 twice.
// A total of 4 operations were used.
// Example 2:
//
// Input: grid = [[1,5],[2,3]], x = 1
// Output: 5
// Explanation: We can make every element equal to 3.
// Example 3:
//
// Input: grid = [[1,2],[3,4]], x = 2
// Output: -1
// Explanation: It is impossible to make every element equal.

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// WTF it work on the first try

int minOperations(vector<vector<int>> &grid, int x) {
  int row = grid.size(), col = grid[0].size(), count = 0;
  vector<int> test;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      test.push_back(grid[i][j]);
    }
  }
  sort(test.begin(), test.end());
  int tSize = test.size(), best = test[(tSize - 1) / 2];
  for (int i = 0; i < tSize; i++) {
    int goal = abs(test[i] - best);
    if (goal % x != 0)
      return -1;
    else {
      count += goal / x;
    }
  }
  return count;
}

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<vector<int>> arr;
  for (int i = 0; i < n; i++) {
    vector<int> temp;
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      temp.push_back(a);
    }
    arr.push_back(temp);
  }
  cout << minOperations(arr, x);
  return 0;
}
