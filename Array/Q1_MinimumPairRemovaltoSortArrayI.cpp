// Given an array nums, you can perform the following operation any number of
// times:
//
// Select the adjacent pair with the minimum sum in nums. If multiple such pairs
// exist, choose the leftmost one. Replace the pair with their sum. Return the
// minimum number of operations needed to make the array non-decreasing.
//
// An array is said to be non-decreasing if each element is greater than or
// equal to its previous element (if it exists).
//
// Example 1:
//
// Input: nums = [5,2,3,1]
//
// Output: 2
//
// Explanation:
//
// The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
// The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
// The array nums became non-decreasing in two operations.
//
// Example 2:
//
// Input: nums = [1,2,2]
//
// Output: 0
//
// Explanation:
//
// The array nums is already sorted.

#include <bits/stdc++.h>
using namespace std;
bool isSorted(vector<int> &nums, int n) {
  if (n == 1)
    return true;
  for (int i = 1; i < n; i++) {
    if (nums[i] < nums[i - 1])
      return false;
  }
  return true;
}

void solve(vector<int> nums, int &ans) {
  int n = nums.size();
  if (isSorted(nums, n))
    return;
  int p = 0, q = 0, sum = INT_MAX;
  for (int i = 1; i < n; i++) {
    if (nums[i - 1] + nums[i] < sum) {
      sum = nums[i - 1] + nums[i];
      p = i - 1;
      q = i;
    }
  }
  nums[p] = nums[p] + nums[q];
  for (int i = q; i < n - 1; i++) {
    nums[i] = nums[i + 1];
  }
  nums.pop_back();
  ans++;
  solve(nums, ans);
}

int minimumPairRemoval(vector<int> &nums) {
  if (nums.size() <= 1)
    return 0;
  int ans = 0;
  solve(nums, ans);
  return ans;
}
