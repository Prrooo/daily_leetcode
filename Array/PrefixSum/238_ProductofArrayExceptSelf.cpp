// 238. Product of Array Except Self
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an integer array nums, return an array answer such that answer[i] is
// equal to the product of all the elements of nums except nums[i].
//
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
// integer.
//
// You must write an algorithm that runs in O(n) time and without using the
// division operation.
//
//
//
// Example 1:
//
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:
//
// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
  int n = nums.size();
  vector<int> result(n);
  vector<int> leftPro(n);
  vector<int> rightPro(n);
  for (int i = 0; i < n; i++) {
    if (i - 1 >= 0) {
      leftPro[i] = leftPro[i - 1] * nums[i];
    } else {
      leftPro[i] = nums[i];
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i + 1 < n) {
      rightPro[i] = rightPro[i + 1] * nums[i];
    } else {
      rightPro[i] = nums[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      result[i] = rightPro[i + 1];
    } else if (i == n - 1) {
      result[i] = leftPro[i - 1];
    } else {
      result[i] = rightPro[i + 1] * leftPro[i - 1];
    }
  }
  return result;
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
  vector<int> result = productExceptSelf(arr);
  for (auto i : result) {
    cout << i << " ";
  }
  return 0;
}
