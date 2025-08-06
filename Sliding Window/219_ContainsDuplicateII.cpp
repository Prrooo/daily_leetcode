// Given an integer array nums and an integer k, return true if there are two
// distinct indices i and j in the array such that nums[i] == nums[j] and abs(i
// - j) <= k.
//
// Example 1:
//
// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:
//
// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:
//
// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k) {
  unordered_map<int, int> mp;
  int i = 0;
  for (int j = 0; j < nums.size(); j++) {
    if (j - i > k) {
      mp.erase(mp.find(nums[i]));
      i++;
    }
    mp[nums[j]]++;
    if (mp[nums[j]] > 1)
      return true;
  }
  return false;
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
  cout << containsNearbyDuplicate(arr, k);
  return 0;
}
