// You are given an integer array nums and two integers indexDiff and valueDiff.
//
// Find a pair of indices (i, j) such that:
//
// i != j,
// abs(i - j) <= indexDiff.
// abs(nums[i] - nums[j]) <= valueDiff, and
// Return true if such pair exists or false otherwise.
//
// Example 1:
//
// Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
// Output: true
// Explanation: We can choose (i, j) = (0, 3).
// We satisfy the three conditions:
// i != j --> 0 != 3
// abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
// abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
// Example 2:
//
// Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
// Output: false
// Explanation: After trying all the possible pairs (i, j), we cannot satisfy
// the three conditions, so we return false.

#include <bits/stdc++.h>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff,
                                   int valueDiff) {
  int n = nums.size();
  set<int> mp;
  for (int i = 0; i < n; i++) {
    if (i > indexDiff)
      mp.erase(nums[i - indexDiff - 1]);
    auto pos = mp.lower_bound(nums[i] - valueDiff);
    if (pos != mp.end() && *pos - nums[i] <= valueDiff) {
      return true;
    }
    mp.insert(nums[i]);
  }
  return false;
}

int main() {
  int n, diff, valDiff;
  cin >> n >> diff >> valDiff;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << containsNearbyAlmostDuplicate(arr, diff, valDiff);
  return 0;
}
