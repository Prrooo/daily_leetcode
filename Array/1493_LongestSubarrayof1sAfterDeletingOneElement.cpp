// same as 1004 leetcode problem

// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the
// resulting array. Return 0 if there is no such subarray.
//
// Example 1:
//
// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3
// numbers with value of 1's. Example 2:
//
// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1]
// longest subarray with value of 1's is [1,1,1,1,1]. Example 3:
//
// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
//

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums) {
  int left = 0, maxLength = 0, zeroCount = 0, k = 1;

  for (int right = 0; right < nums.size(); ++right) {
    if (nums[right] == 0) {
      zeroCount++;
    }
    while (zeroCount > k) {
      if (nums[left] == 0) {
        zeroCount--;
      }
      left++;
    }
    maxLength = max(maxLength, right - left);
  }

  return maxLength;
}

int main() { return 0; }
