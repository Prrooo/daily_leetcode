// Given an integer array nums, return the number of reverse pairs in the array.
//
// A reverse pair is a pair (i, j) where:
//
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].
//
//
// Example 1:
//
// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
// Example 2:
//
// Input: nums = [2,4,3,5,1]
// Output: 3
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
// (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

#include <bits/stdc++.h>
using namespace std;

void countPair(vector<int> &nums, int start, int mid, int end, int &count) {
  int first = start, second = mid + 1;
  while (first <= mid && second <= end) {
    long long temp = (long long)2 * nums[second];
    if (nums[first] > temp) {
      count += mid - first + 1;
      second++;
    } else {
      first++;
    }
  }
}

void merge(vector<int> &arr, int s, int mid, int e) {
  vector<int> temp;
  int i = s, j = mid + 1;
  while (i <= mid && j <= e) {
    if (arr[i] > arr[j]) {
      temp.push_back(arr[j++]);
    } else {
      temp.push_back(arr[i++]);
    }
  }
  while (i <= mid)
    temp.push_back(arr[i++]);
  while (j <= e)
    temp.push_back(arr[j++]);

  int z = 0;
  for (int i = s; i <= e; i++) {
    arr[i] = temp[z++];
  }
}

void solve(vector<int> &nums, int start, int end, int &count) {
  if (start >= end)
    return;
  int mid = (start + end) / 2;
  solve(nums, start, mid, count);
  solve(nums, mid + 1, end, count);
  countPair(nums, start, mid, end, count);
  merge(nums, start, mid, end);
}

int reversePairs(vector<int> &nums) {
  int count = 0, n = nums.size();
  solve(nums, 0, n - 1, count);
  return count;
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
  cout << reversePairs(arr);
  return 0;
}
