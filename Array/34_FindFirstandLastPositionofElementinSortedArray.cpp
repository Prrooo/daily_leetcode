// Given an array of integers nums sorted in non-decreasing order, find the
// starting and ending position of a given target value.
//
// If target is not found in the array, return [-1, -1].
//
// You must write an algorithm with O(log n) runtime complexity.
//
// Example 1:
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:
//
// Input: nums = [], target = 0
// Output: [-1,-1]
//

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int target, vector<int> &res, bool dir) {
  int low = 0, high = nums.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (nums[mid] == target && dir) {
      res[0] = mid;
      high = mid - 1;
    } else if (nums[mid] == target && !dir) {
      res[1] = mid;
      low = mid + 1;
    } else if (nums[mid] > target) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
}

vector<int> searchRange(vector<int> &nums, int target) {
  vector<int> res(2, -1);
  solve(nums, target, res, true);
  solve(nums, target, res, false);
  return res;
}

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  vector<int> res = searchRange(arr, target);
  cout << res[0] << res[1];
  return 0;
}
