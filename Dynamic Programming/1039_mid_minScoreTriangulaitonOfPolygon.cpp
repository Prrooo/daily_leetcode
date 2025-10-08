// nice question should revise
//
// You have a convex n-sided polygon where each vertex has an integer value. You
// are given an integer array values where values[i] is the value of the ith
// vertex in clockwise order.
//
// Polygon triangulation is a process where you divide a polygon into a set of
// triangles and the vertices of each triangle must also be vertices of the
// original polygon. Note that no other shapes other than triangles are allowed
// in the division. This process will result in n - 2 triangles.
//
// You will triangulate the polygon. For each triangle, the weight of that
// triangle is the product of the values at its vertices. The total score of the
// triangulation is the sum of these weights over all n - 2 triangles.
//
// Return the minimum possible score that you can achieve with some
// triangulation of the polygon.
//
//
//
// Example 1:
//
// Input: values = [1,2,3]
//
// Output: 6
//
// Explanation: The polygon is already triangulated, and the score of the only
// triangle is 6.
//
// Example 2:
//
// Input: values = [3,7,4,5]
//
// Output: 144
//
// Explanation: There are two triangulations, with possible scores: 3*7*5 +
// 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144. The minimum score is 144.
//
// Example 3:
//
// Input: values = [1,3,1,4,1,5]
//
// Output: 13
//
// Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1
// = 13.
//
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> dp;

  Solution() : dp(51, vector<int>(51, 0)) {}

  int minScoreTriangulation(vector<int> &values, int i = 0, int j = 0,
                            int res = 0) {
    if (j == 0)
      j = values.size() - 1;
    if (dp[i][j] != 0)
      return dp[i][j];
    for (int k = i + 1; k < j; k++) {
      res = min(res == 0 ? INT_MAX : res,
                minScoreTriangulation(values, i, k) +
                    values[i] * values[k] * values[j] +
                    minScoreTriangulation(values, k, j));
    }
    return dp[i][j] = res;
  }
};

int main() { return 0; }
