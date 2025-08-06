// 
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// 
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// 
//  
// 
// Example 1:
// 
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:
// 
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
// 

#include <bits/stdc++.h>
using namespace std;


// with dp solution working fine

int solve(vector<int> &nums, int n, int sum, int index, vector<int> &dp) {
  if (index >= n) {
    return sum;
  }
  if (dp[index] != -1)
    return dp[index] + sum;
  int first = solve(nums, n, sum, index + 1, dp);
  int second = solve(nums, n, sum += nums[index], index + 2, dp);
  dp[index] = max(first, second);
  cout << dp[index] << " ";
  return dp[index];
}

int rob(vector<int> &nums) {
  int n = nums.size();
  if (n == 0)
    return 0;
  else if (n == 1)
    return nums[0];
  vector<int> dp(n, -1);
  int first = solve(nums, n, 0, 0, dp);
  int second = solve(nums, n, 0, 1, dp);
  return max(first, second);
}

// solution without dp therefore TLE

int solve(vector<int> &nums, int n, int sum, int index) {
  if (index >= n)
    return sum;
  int first = solve(nums, n, sum, index + 1);
  int second = solve(nums, n, sum += nums[index], index + 2);
  return max(first, second);
}

int robWithoutDp(vector<int> &nums) {
  int n = nums.size();
  if (n == 0)
    return 0;
  else if (n == 1)
    return nums[0];
  int first = solve(nums, n, nums[0], 2);
  int second = solve(nums, n, nums[1], 3);
  return max(first, second);
}

int main() { return 0; }
