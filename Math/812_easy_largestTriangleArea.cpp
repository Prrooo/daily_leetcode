// Given an array of points on the X-Y plane points where points[i] = [xi, yi],
// return the area of the largest triangle that can be formed by any three
// different points. Answers within 10-5 of the actual answer will be accepted.
//
//
//
// Example 1:
//
// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// Output: 2.00000
// Explanation: The five points are shown in the above figure. The red triangle
// is the largest.
//
// Example 2:
//
// Input: points = [[1,0],[0,0],[0,1]]
// Output: 0.50000
//

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// work best solution

class Solution {
public:
  double largestTriangleArea(vector<vector<int>> &nums) {
    int n = nums.size();
    double ans = 0;
    for (int i = n - 1; i >= 2; i--) {
      for (int j = i - 1; j >= 1; j--) {
        for (int k = j - 1; k >= 0; k--) {
          int x1 = nums[i][0], y1 = nums[i][1];
          int x2 = nums[j][0], y2 = nums[j][1];
          int x3 = nums[k][0], y3 = nums[k][1];
          ans = max(
              ans, 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
