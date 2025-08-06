// https://www.youtube.com/watch?v=q8UcbJDHp3M

// Given a set of distinct positive integers nums, return the largest subset
// answer such that every pair (answer[i], answer[j]) of elements in this subset
// satisfies:
//
// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.
//
// Example 1:
//
// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
// Example 2:
//
// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]

#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums) {
  int n = nums.size(), max = 1;
  sort(nums.begin(), nums.end());
  vector<int> dp(n + 1, 1);
  vector<int> ans;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]) {
        dp[i] = 1 + dp[j];
        if (dp[i] > max)
          max = dp[i];
      }
    }
  }
  int pre = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (dp[i] == max && (pre % nums[i] == 0 || pre == -1)) {
      max--;
      ans.push_back(nums[i]);
      pre = nums[i];
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  vector<int> result = largestDivisibleSubset(arr);
  for (auto i : result) {
    cout << i << " ";
  }
  return 0;
}
