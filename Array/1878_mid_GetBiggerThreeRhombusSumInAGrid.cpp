#include <bits/stdc++.h>
#include <iterator>
#include <random>
using namespace std;

class Solution {
public:
  priority_queue<int> pq;

  bool is_safe(int row, int col, int n, int m) {
    return row >= 0 && row < n && col >= 0 && col < m;
  }

  void solve(vector<vector<int>> &grid, int row, int col, int n, int m) {
    pq.push(grid[row][col]);
    int i = row + 1, j = col - 1;
    while (is_safe(i, j, n, m)) {
      int i1 = row + 1, j1 = col++;
      while (is_safe(i1, j1, n, m)) {
        int i2 = i1 + (i - row), j2 = j1 - abs(col - j);
        if (is_safe(i2, j2, n, m)) {
          pq.push(grid[row][col] + grid[i][j] + grid[i1][j1] + grid[i2][j2]);
        }
        i1++, j1++;
      }
      i++, j--;
    }
  }

  vector<int> getBiggestThree(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        solve(grid, i, j, n, m);
      }
    }
    set<int> st;
    int i = 0;
    while (st.size() < 3 && !pq.empty()) {
      st.insert(pq.top());
      pq.pop();
    }
    vector<int> ans(st.rbegin(), st.rend());
    return ans;
  }
};

int main() { return 0; }
