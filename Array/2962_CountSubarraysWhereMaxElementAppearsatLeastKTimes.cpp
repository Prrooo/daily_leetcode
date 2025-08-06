// You are given an integer array nums and a positive integer k.
//
// Return the number of subarrays where the maximum element of nums appears at
// least k times in that subarray.
//
// A subarray is a contiguous sequence of elements within an array.
//
// Example 1:
//
// Input: nums = [1,3,2,3,3], k = 2
// Output: 6
// Explanation: The subarrays that contain the element 3 at least 2 times are:
// [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3]. Example 2:
//
// Input: nums = [1,4,2,1], k = 3
// Output: 0
// Explanation: No subarray contains the element 4 at least 3 times.

#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int> &nums, int k) {
  int n = nums.size(), count = 0, tempMax = INT_MIN;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] > tempMax) {
      tempMax = nums[i];
    }
  }
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] == tempMax)
      count++;
    while (count >= k) {
      if (nums[j] == tempMax)
        count--;
      ans += n - i;
      j++;
    }
  }
  return ans;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << countSubarrays(arr, k);
  return 0;
}
