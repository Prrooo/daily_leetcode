// You are given an array of positive integers nums and a positive integer k.
//
// A permutation of nums is said to form a divisible concatenation if, when you
// concatenate the decimal representations of the numbers in the order specified
// by the permutation, the resulting number is divisible by k.
//
// Return the lexicographically smallest permutation (when considered as a list
// of integers) that forms a divisible concatenation. If no such permutation
// exists, return an empty list.
//
//
//
// Example 1:
//
// Input: nums = [3,12,45], k = 5
//
// Output: [3,12,45]
//
// Explanation:
//
// Permutation	Concatenated Value	Divisible by 5
// [3, 12, 45]	31245	Yes
// [3, 45, 12]	34512	No
// [12, 3, 45]	12345	Yes
// [12, 45, 3]	12453	No
// [45, 3, 12]	45312	No
// [45, 12, 3]	45123	No
// The lexicographically smallest permutation that forms a divisible
// concatenation is [3,12,45].
//
// Example 2:
//
// Input: nums = [10,5], k = 10
//
// Output: [5,10]
//
// Explanation:
//
// Permutation	Concatenated Value	Divisible by 10
// [5, 10]	510	Yes
// [10, 5]	105	No
// The lexicographically smallest permutation that forms a divisible
// concatenation is [5,10].
//
// Example 3:
//
// Input: nums = [1,2,3], k = 5
//
// Output: []
//
// Explanation:
//
// Since no permutation of nums forms a valid divisible concatenation, return an
// empty list.
//
//

#include <bits/stdc++.h>
using namespace std;

// best solution

bool recursion(int mask, int reminder, int n, vector<int> &nums, int k,
               vector<vector<int>> &dp) {
  if (mask == (1 << n) - 1) {
    if (reminder == 0)
      return true;
    return false;
  }

  if (dp[mask][reminder] != -1) {
    return dp[mask][reminder];
  }

  bool res = false;
  for (int i = 0; i < n; i++) {
    if (!(1 & (mask >> i))) {
      int num = nums[i], multiplier = 1;
      while (num > 0) {
        multiplier *= 10, num /= 10;
      }

      int newReminder = ((1LL * reminder * multiplier) + nums[i]) % k;
      res |= recursion(mask | (1 << i), newReminder, n, nums, k, dp);
    }
  }

  return dp[mask][reminder] = res;
}

void buildArray(int pos, int mask, int reminder, int n, vector<int> &nums,
                int k, vector<int> &ans, vector<vector<int>> &dp) {
  if (pos == n)
    return;

  int newMask = mask, nextReminder = reminder;
  for (int i = 0; i < n; i++) {
    if (!(1 & (mask >> i))) {
      int num = nums[i], multiplier = 1;
      while (num > 0) {
        multiplier *= 10, num /= 10;
      }

      int newReminder = ((1LL * reminder * multiplier) + nums[i]) % k;
      bool res = recursion(mask | (1 << i), newReminder, n, nums, k, dp);

      if (res && ans[pos] > nums[i]) {
        newMask = mask | (1 << i);
        nextReminder = newReminder;

        ans[pos] = nums[i];
      }
    }
  }

  buildArray(pos + 1, newMask, nextReminder, n, nums, k, ans, dp);
}

vector<int> concatenatedDivisibility(vector<int> &nums, int k) {
  int n = nums.size();

  vector<vector<int>> dp(1 << n, vector<int>(k, -1));
  bool exist = recursion(0, 0, n, nums, k, dp);
  if (!exist)
    return {};

  vector<int> ans(n, INT_MAX);
  buildArray(0, 0, 0, n, nums, k, ans, dp);

  return ans;
}

// my solution ERROR TLE

// bool nextPermutation(vector<int> &nums, int n) {
//   int minIndex = -1;
//   for (int i = n - 2; i >= 0; i--) {
//     if (nums[i] < nums[i + 1]) {
//       minIndex = i;
//       break;
//     }
//   }
//   if (minIndex == -1)
//     return false;
//   for (int i = n - 1; i >= 0; i--) {
//     if (nums[i] > nums[minIndex]) {
//       swap(nums[i], nums[minIndex]);
//       reverse(nums.begin() + minIndex + 1, nums.end());
//       return true;
//     }
//   }
//   return false;
// }
//
// long long merge(vector<int> nums, int n, int k) {
//   string ans = "";
//   int res = 0;
//   for (int i = 0; i < n; i++) {
//     ans = ans + to_string(nums[i]);
//   }
//   for (int i = 0; i < ans.size(); i++) {
//     res = res * 10 + (ans[i] - '0');
//     res = res % k;
//   }
//   return res;
// }
//
// vector<int> concatenatedDivisibility(vector<int> &nums, int k) {
//   int n = nums.size();
//   sort(nums.begin(), nums.end());
//   bool check = true;
//   while (check) {
//     if (merge(nums, n, k) % k == 0)
//       return nums;
//     check = nextPermutation(nums, n);
//   }
//   return {};
// }

int main() { return 0; }
