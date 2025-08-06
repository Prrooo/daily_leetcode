// You are given an integer array nums consisting of n elements, and an integer k.
// 
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
// 
//  
// 
// Example 1:
// 
// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
// Example 2:
// 
// Input: nums = [5], k = 1
// Output: 5.00000
//  


#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int> &nums, int k) {
  int sum = 0, i = 0, j = 0, n = nums.size();
  double ans = INT_MIN, temp;
  while (j < n) {
    while (j - i + 1 <= k) {
      sum += nums[j];
      j++;
    }
    temp = (double)sum / k;
    if (temp > ans) {
      ans = temp;
    }
    sum -= nums[i++];
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
  cout << findMaxAverage(arr, k);
  return 0;
}

