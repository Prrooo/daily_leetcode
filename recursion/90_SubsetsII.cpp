// https://takeuforward.org/data-structure/subset-ii-print-all-the-unique-subsets/
//
// Given an integer array nums that may contain duplicates, return all possible
// subsets
//  (the power set).
//
// The solution set must not contain duplicate subsets. Return the solution in
// any order.
//
//
//
// Example 1:
//
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:
//
// Input: nums = [0]
// Output: [[],[0]]
//

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int index, vector<int> &temp,
           vector<vector<int>> &ans) {
  ans.push_back(temp);
  for (int i = index; i < nums.size(); i++) {
    if (i != index && nums[i] == nums[i - 1])
      continue;
    temp.push_back(nums[i]);
    solve(nums, i + 1, temp, ans);
    temp.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  vector<int> temp;
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  solve(nums, 0, temp, ans);
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
  vector<vector<int>> result = subsetsWithDup(arr);
  for (auto i : result) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
