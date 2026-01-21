// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/editorial/?envType=daily-question&envId=2026-01-20
//
// for reference
//
// question
// Given a m x n matrix mat and an integer threshold, return the maximum
// side-length of a square with a sum less than or equal to threshold or return
// 0 if there is no such square.

// Example 1 :
//
//     Input : mat =
//                 [
//                   [ 1, 1, 3, 2, 4, 3, 2 ], [ 1, 1, 3, 2, 4, 3, 2 ],
//                   [ 1, 1, 3, 2, 4, 3, 2 ]
//                 ],
//             threshold = 4 Output : 2 Explanation
//     : The maximum side length of square with sum less than 4 is 2 as shown.
//
//       Example 2 :
//
//     Input : mat =
//                 [
//                   [ 2, 2, 2, 2, 2 ], [ 2, 2, 2, 2, 2 ], [ 2, 2, 2, 2, 2 ],
//                   [ 2, 2, 2, 2, 2 ], [ 2, 2, 2, 2, 2 ]
//                 ],
//             threshold = 1 Output : 0

#include <bits/stdc++.h>
using namespace std;

// best solution

class Solution {
public:
  int getRect(const vector<vector<int>> &P, int x1, int y1, int x2, int y2) {
    return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
  }

  int maxSideLength(vector<vector<int>> &mat, int threshold) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> P(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        P[i][j] =
            P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }

    int l = 1, r = min(m, n), ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      bool find = false;
      for (int i = 1; i <= m - mid + 1; ++i) {
        for (int j = 1; j <= n - mid + 1; ++j) {
          if (getRect(P, i, j, i + mid - 1, j + mid - 1) <= threshold) {
            find = true;
          }
        }
      }
      if (find) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }
};

int main() { return 0; }
