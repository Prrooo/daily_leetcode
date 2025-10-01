// Given an integer array nums, return the length of the longest strictly
// increasing
//
// .
//
//
//
// Example 1:
//
// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
// length is 4.
//
// Example 2:
//
// Input: nums = [0,1,0,3,2,3]
// Output: 4
//
// Example 3:
//
// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
//
//

#include <bits/stdc++.h>
using namespace std;

// best solution

class Solution {
public:
  int solve(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (right + left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

  int lengthOfLIS(vector<int> &nums) {
    vector<int> res;
    for (auto i : nums) {
      if (res.empty() || res.back() < i) {
        res.push_back(i);
      } else {
        res[solve(res, i)] = i;
      }
    }
    return res.size();
  }
};

int main() { return 0; }
