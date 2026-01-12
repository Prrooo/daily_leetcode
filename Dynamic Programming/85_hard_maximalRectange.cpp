#include <bits/stdc++.h>
using namespace std;

// best soluiton

class Solution {
public:
  void solve(vector<int> &height, int &ans, int m) {
    stack<int> st;
    vector<int> index(m);
    for (int i = 0; i < m; i++) {
      while (!st.empty() && height[st.top()] >= height[i]) {
        st.pop();
      }
      if (st.empty()) {
        index[i] = 0;
      } else {
        index[i] = st.top() + 1;
      }
      st.push(i);
    }

    stack<int> nst;
    for (int i = m - 1; i >= 0; i--) {
      while (!nst.empty() && height[nst.top()] >= height[i]) {
        nst.pop();
      }
      int area = 0;
      if (nst.empty()) {
        area = height[i] * (m - index[i]);
        ans = max(ans, area);
      } else {
        area = height[i] * (nst.top() - index[i]);
        ans = max(ans, area);
      }
      nst.push(i);
    }
  }

  int maximalRectangle(vector<vector<char>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> height(m);
    int ans = INT_MIN;

    for (int i = 0; i < m; i++) {
      if (matrix[0][i] == '1') {
        height[i] = 1;
      } else {
        height[i] = 0;
      }
    }

    solve(height, ans, m);

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1') {
          height[j]++;
        } else {
          height[j] = 0;
        }
      }

      solve(height, ans, m);
    }
    return ans;
  }
};

// brute force solution

class Solution1 {
public:
  int findWidth(vector<vector<char>> &arr, int currR, int currC,
                vector<vector<int>> &dp, int n, int m) {
    if (currR >= n || currC >= m || currR < 0 || currC < 0)
      return 0;
    else if (arr[currR][currC] == '0')
      return 0;
    int width = 1;
    if (dp[currR][currC] != -1) {
      width = dp[currR][currC];
    } else {
      for (int i = currC + 1; i < m; i++) {
        if (arr[currR][i] == '1') {
          width++;
        } else {
          break;
        }
      }
      dp[currR][currC] = width;
    }
    return width;
  }

  void solve(vector<vector<char>> &arr, int currR, int currC,
             vector<vector<int>> &dp, int n, int m, int &ans) {
    int wdM = findWidth(arr, currR, currC, dp, n, m);
    int up = 1, down = 0;
    for (int i = currR - 1; i >= 0; i--) {
      if (findWidth(arr, i, currC, dp, n, m) >= wdM) {
        up++;
      } else {
        break;
      }
    }
    for (int i = currR + 1; i < n; i++) {
      if (findWidth(arr, i, currC, dp, n, m) >= wdM) {
        down++;
      } else {
        break;
      }
    }
    ans = max(ans, (up + down) * wdM);
  }

  int maximalRectangle(vector<vector<char>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1') {
          solve(matrix, i, j, dp, n, m, ans);
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
