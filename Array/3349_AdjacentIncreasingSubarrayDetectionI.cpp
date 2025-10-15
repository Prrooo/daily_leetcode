// Given an array nums of n integers and an integer k, determine whether there
// exist two adjacent
//
// of length k such that both subarrays are strictly increasing. Specifically,
// check if there are two subarrays starting at indices a and b (a < b), where:
//
//     Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly
//     increasing. The subarrays must be adjacent, meaning b = a + k.
//
// Return true if it is possible to find two such subarrays, and false
// otherwise.
//
//
//
// Example 1:
//
// Input: nums = [2,5,7,8,9,2,3,4,3,1], k = 3
//
// Output: true
//
// Explanation:
//
//     The subarray starting at index 2 is [7, 8, 9], which is strictly
//     increasing. The subarray starting at index 5 is [2, 3, 4], which is also
//     strictly increasing. These two subarrays are adjacent, so the result is
//     true.
//
// Example 2:
//
// Input: nums = [1,2,3,4,4,4,4,5,6,7], k = 5
//
// Output: false
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool hasIncreasingSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    int inc = 1, pre = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1]) {
        inc++;
      } else {
        pre = inc;
        inc = 1;
      }
      if (min(inc, pre) >= k || inc >= 2 * k)
        return true;
    }
    return false;
  }
};

int main() { return 0; }
