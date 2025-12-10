// You are given an integer array nums.
//
// A special triplet is defined as a triplet of indices (i, j, k) such that:
//
//     0 <= i < j < k < n, where n = nums.length
//     nums[i] == nums[j] * 2
//     nums[k] == nums[j] * 2
//
// Return the total number of special triplets in the array.
//
// Since the answer may be large, return it modulo 109 + 7.
//
//
//
// Example 1:
//
// Input: nums = [6,3,6]
//
// Output: 1
//
// Explanation:
//
// The only special triplet is (i, j, k) = (0, 1, 2), where:
//
//     nums[0] = 6, nums[1] = 3, nums[2] = 6
//     nums[0] = nums[1] * 2 = 3 * 2 = 6
//     nums[2] = nums[1] * 2 = 3 * 2 = 6
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int MOD = 1e9 + 7;
  int specialTriplets(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> lCount;
    unordered_map<int, int> rCount;
    int count = 0;

    for (int i = 0; i < n; i++) {
      rCount[nums[i]]++;
    }

    for (int i = 0; i < n; i++) {
      int target = nums[i] * 2;

      int lct = lCount[target];
      lCount[nums[i]]++;
      int rct = rCount[target] - lct;
      if (target == nums[i])
        rct--;
      count = (count + (1LL * lct * rct) % MOD) % MOD;
    }
    return count;
  }
};

int main() { return 0; }
