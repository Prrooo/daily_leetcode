// 128. Longest Consecutive Sequence
// Solved
// Medium
// Topics
// premium lock iconCompanies
//
// Given an unsorted array of integers nums, return the length of the longest
// consecutive elements sequence.
//
// You must write an algorithm that runs in O(n) time.
//
//
//
// Example 1:
//
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.
//
// Example 2:
//
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
//
// Example 3:
//
// Input: nums = [1,0,1,2]
// Output: 3

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int curr = 1, ans = 0, n = nums.size();
  if (n == 0)
    return 0;
  for (int i = 1; i < n; i++) {
    if (nums[i - 1] == (nums[i] - 1)) {
      curr++;
    } else {
      ans = max(ans, curr);
      curr = 1;
    }
  }
  ans = max(ans, curr);
  return ans;
}

int main() { return 0; }
