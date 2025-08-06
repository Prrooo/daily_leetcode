// You are given an integer array nums.
//
// A
//
// sub of nums with length x is called valid if it satisfies:
//
//     (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] +
//     sub[x - 1]) % 2.
//
// Return the length of the longest valid subsequence of nums.
//
// A subsequence is an array that can be derived from another array by deleting
// some or no elements without changing the order of the remaining elements.
//
//
//
// Example 1:
//
// Input: nums = [1,2,3,4]
//
// Output: 4
//
// Explanation:
//
// The longest valid subsequence is [1, 2, 3, 4].
//
// Example 2:
//
// Input: nums = [1,2,1,1,2,1,2]
//
// Output: 6
//
// Explanation:
//
// The longest valid subsequence is [1, 2, 1, 2, 1, 2].
//
// Example 3:
//
// Input: nums = [1,3]
//
// Output: 2
//
// Explanation:
//
// The longest valid subsequence is [1, 3]
//
//
//
// revise important concept

#include <bits/stdc++.h>
using namespace std;

int maximumLength(vector<int> &nums) {
  int n = nums.size();
  if (n == 2)
    return 2;
  bool z = nums[0] & 1;
  int ans[3] = {!z, z, 1};
  for (int i = 1; i < n; i++) {
    bool x = nums[i] & 1;
    ans[x]++;
    if (x != z) {
      z = x;
      ans[2]++;
    }
  }
  return max({ans[0], ans[1], ans[2]});
}

int main() { return 0; }
