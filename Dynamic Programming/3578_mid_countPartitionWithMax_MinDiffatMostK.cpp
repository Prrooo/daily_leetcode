#include <bits/stdc++.h>
using namespace std;

// brute force solution using dp
// error TLE

class Solution {
public:
  int MOD = 1e9 + 7;

  int solve(vector<int> &nums, int index, int n, int k, vector<int> &dp) {
    if (index >= n)
      return 1;
    if (dp[index] != -1)
      return dp[index];
    int count = 0;
    int tempMin = INT_MAX, tempMax = INT_MIN;
    for (int i = index; i < n; i++) {
      tempMin = min(tempMin, nums[i]);
      tempMax = max(tempMax, nums[i]);
      if ((tempMax - tempMin) <= k) {
        long long temp = count + solve(nums, i + 1, n, k, dp);
        count = temp % MOD;
      }
    }
    return dp[index] = count;
  }

  int countPartitions(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, 0, n, k, dp);
  }
};

int main() { return 0; }
