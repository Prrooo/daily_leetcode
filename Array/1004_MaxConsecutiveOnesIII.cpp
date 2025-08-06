// Given a binary array nums and an integer k, return the maximum number of
// consecutive 1's in the array if you can flip at most k 0's.
//
//
//
// Example 1:
//
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:
//
// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

#include <bits/stdc++.h>
using namespace std;

// best solution
int longestOnes(vector<int> &nums, int k) {
  int left = 0, maxLength = 0, zeroCount = 0;

  for (int right = 0; right < nums.size(); ++right) {
    if (nums[right] == 0) {
      zeroCount++;
    }
    while (zeroCount > k) {
      if (nums[left] == 0) {
        zeroCount--;
      }
      left++;
    }
    maxLength = max(maxLength, right - left + 1);
  }

  return maxLength;
}

// my solution little complex

// int longestOnes(vector<int> &nums, int k) {
//   int n = nums.size(), i = 0, j = 0, temp = k, count = 0, ans = INT_MIN;
//   while (j < n) {
//     if (nums[j] == 1) {
//       count++;
//       j++;
//     } else if (nums[j] == 0 && temp > 0) {
//       temp--;
//       count++;
//       j++;
//     } else if (nums[j] == 0 && temp <= 0 && k != 0) {
//       while (i < j && temp == 0) {
//         if (nums[i] == 0) {
//           temp++;
//         }
//         count--;
//         i++;
//       }
//     } else {
//       count = 0;
//       j++;
//     }
//     ans = max(ans, count);
//   }
//   return ans;
// }

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << longestOnes(arr, k);
  return 0;
}
