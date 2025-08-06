// You are given an integer array nums. You are initially positioned at the
// array's first index, and each element in the array represents your maximum
// jump length at that position.
//
// Return true if you can reach the last index, or false otherwise.
//
//
//
// Example 1:
//
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:
//
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
// jump length is 0, which makes it impossible to reach the last index.
//

#include <bits/stdc++.h>
using namespace std;

// best solution
class Solution {
public:
  bool canJump(vector<int> &nums) {
    int goal = nums.size() - 1;

    for (int i = nums.size() - 2; i >= 0; i--) {
      if (i + nums[i] >= goal) {
        goal = i;
      }
    }

    return goal == 0;
  }
};

// my solution not best but work no TLE

void solve(vector<int> &nums, vector<int> &tempAns, int index, int n) {
  if (index >= n - 1) {
    tempAns[n - 1] = 1;
    return;
  } else if ((nums[index] + index) >= n - 1) {
    tempAns[index] = 1;
    return;
  }
  solve(nums, tempAns, index + 1, n);
  if (tempAns[index] == 1 || nums[index] == 0)
    return;
  for (int i = 1; i <= nums[index]; i++) {
    if (tempAns[index + i] == 1) {
      tempAns[index] = 1;
      return;
    }
  }
  return;
}

bool canJump(vector<int> &nums) {
  int n = nums.size();
  vector<int> tempAns(n, -1);
  solve(nums, tempAns, 0, n);
  return tempAns[0] == -1 ? false : true;
}

// solve the problem but TLE

// bool solve(vector<int> &nums, int n, int index) {
//   if (index >= n - 1 || (nums[index] + index) >= n - 1)
//     return true;
//   if (nums[index] <= 0)
//     return false;
//   for (int i = 1; i <= nums[index]; i++) {
//     if (solve(nums, n, index + i))
//       return true;
//   }
//   return false;
// }
//
// bool canJump(vector<int> &nums) {
//   int n = nums.size(), index = 0;
//   return solve(nums, n, index);
// }

int main() { return 0; }
