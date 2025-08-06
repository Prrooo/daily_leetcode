// You are given an array nums consisting of positive integers.
//
// We call a subarray of nums nice if the bitwise AND of every pair of elements
// that are in different positions in the subarray is equal to 0.
//
// Return the length of the longest nice subarray.
//
// A subarray is a contiguous part of an array.
//
// Note that subarrays of length 1 are always considered nice.
//
//
//
// Example 1:
//
// Input: nums = [1,3,8,48,10]
// Output: 3
// Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies
// the conditions:
// - 3 AND 8 = 0.
// - 3 AND 48 = 0.
// - 8 AND 48 = 0.
// It can be proven that no longer nice subarray can be obtained, so we
// return 3. Example 2:
//
// Input: nums = [3,1,5,11,13]
// Output: 1
// Explanation: The length of the longest nice subarray is 1. Any subarray of
// length 1 can be chosen.

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums, int start, int check) {
  for (int i = start; i < check; i++) {
    if (nums[i] & nums[check]) {
      return false;
    }
  }
  return true;
}

int longestNiceSubarray(vector<int> &nums) {
  int n = nums.size();
  int i = 0, j = 0, ans = 0;
  while (j < n) {
    if (solve(nums, i, j)) {
      j++;
    } else {
      ans = max(ans, j - i);
      i++;
      j = i;
    }
  }
  ans = max(ans, j - i);
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << longestNiceSubarray(arr);
  return 0;
}
