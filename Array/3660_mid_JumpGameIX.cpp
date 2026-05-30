// You are given an integer array nums.
//
// From any index i, you can jump to another index j under the following rules:
//
//     Jump to index j where j > i is allowed only if nums[j] < nums[i].
//     Jump to index j where j < i is allowed only if nums[j] > nums[i].
//
// For each index i, find the maximum value in nums that can be reached by
// following any sequence of valid jumps starting at i.
//
// Return an array ans where ans[i] is the maximum value reachable starting from
// index i.
//
//
//
// Example 1:
//
// Input: nums = [2,1,3]
//
// Output: [2,2,3]
//
// Explanation:
//
//     For i = 0: No jump increases the value.
//     For i = 1: Jump to j = 0 as nums[j] = 2 is greater than nums[i].
//     For i = 2: Since nums[2] = 3 is the maximum value in nums, no jump
//     increases the value.
//
// Thus, ans = [2, 2, 3].
//
// Example 2:
//
// Input: nums = [2,3,1]
//
// Output: [3,3,3]
//
// Explanation:
//
//     For i = 0: Jump forward to j = 2 as nums[j] = 1 is less than nums[i] = 2,
//     then from i = 2 jump to j = 1 as nums[j] = 3 is greater than nums[2]. For
//     i = 1: Since nums[1] = 3 is the maximum value in nums, no jump increases
//     the value. For i = 2: Jump to j = 1 as nums[j] = 3 is greater than
//     nums[2] = 1.
//
// Thus, ans = [3, 3, 3].

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxValue(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 0);

    using Item = pair<int, int>;
    vector<Item> prevMax(n);

    Item prev = {INT_MIN, -1};
    for (int i = 0; i < n; ++i) {
      if (nums[i] > prev.first) {
        prev = {nums[i], i};
      }
      prevMax[i] = prev;
    }

    auto process = [&](auto &self, int r, int rightMin, int rightMax) -> void {
      auto [pMax, pivotIndex] = prevMax[r];
      int currMax = pMax <= rightMin ? pMax : rightMax;

      int nextRightMin = min(pMax, rightMin);
      for (int i = pivotIndex; i <= r; ++i) {
        ans[i] = currMax;
        nextRightMin = min(nextRightMin, nums[i]);
      }

      if (pivotIndex == 0) {
        return;
      }

      self(self, pivotIndex - 1, nextRightMin, currMax);
    };

    process(process, n - 1, INT_MAX, 0);

    return ans;
  }
};

int main() { return 0; }
