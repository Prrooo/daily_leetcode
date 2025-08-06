// Given an integer array nums of length n and an integer target, find three
// integers in nums such that the sum is closest to target.
//
// Return the sum of the three integers.
//
// You may assume that each input would have exactly one solution.
//
//
//
// Example 1:
//
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// we are using 3 pointer approach to solve this
// first we define i,right as the boundar and use left and right to move through
// in the boundary

#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());
  int n = nums.size(), ans = INT_MAX / 2;
  for (int i = 0; i < n; i++) {
    int left = i + 1, right = n - 1;
    while (left < right) {
      int currentSum = nums[i] + nums[left] + nums[right];
      if (abs(currentSum - target) < abs(ans - target)) {
        ans = currentSum;
      } else if (currentSum < target) {
        left++;
      } else if (currentSum > target) {
        right--;
      } else {
        return currentSum;
      }
    }
  }

  return ans;
}

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << threeSumClosest(arr, target);
  return 0;
}
