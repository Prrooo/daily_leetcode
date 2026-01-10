// Return the maximum dot product between non-empty subsequences of nums1 and
// nums2 with the same length.
//
// A subsequence of a array is a new array which is formed from the original
// array by deleting some (can be none) of the characters without disturbing the
// relative positions of the remaining characters. (ie, [2,3,5] is a subsequence
// of [1,2,3,4,5] while [1,5,3] is not).
//
//
//
// Example 1:
//
// Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
// Output: 18
// Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from
// nums2. Their dot product is (2*3 + (-2)*(-6)) = 18.
//
// Example 2:
//
// Input: nums1 = [3,-2], nums2 = [2,-6,7]
// Output: 21
// Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
// Their dot product is (3*7) = 21.
//
// Example 3:
//
// Input: nums1 = [-1,-1], nums2 = [1,1]
// Output: -1
// Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
// Their dot product is -1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int solve(int i, int j, vector<int> &nums1, vector<int> &nums2,
            vector<vector<int>> &dp, int n, int m) {
    if (i >= n || j >= m) {
      return -1e9;
    }
    if (dp[i][j] != INT_MIN) {
      return dp[i][j];
    }
    int val = nums1[i] * nums2[j];
    int take =
        (nums1[i] * nums2[j]) + solve(i + 1, j + 1, nums1, nums2, dp, n, m);
    int right = solve(i, j + 1, nums1, nums2, dp, n, m);
    int left = solve(i + 1, j, nums1, nums2, dp, n, m);
    return dp[i][j] = max({take, right, left, val});
  }

  int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
    return solve(0, 0, nums1, nums2, dp, n, m);
  }
};

int main() { return 0; }
