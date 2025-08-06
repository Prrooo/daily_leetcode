// Given a collection of numbers, nums, that might contain duplicates, return
// all possible unique permutations in any order.
//
// Example 1:
//
// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// Example 2:
//
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//

#include <bits/stdc++.h>
using namespace std;

void solve(unordered_map<int, int> mp, vector<vector<int>> &ans,
           vector<int> temp, int n) {
  if (temp.size() == n) {
    ans.push_back(temp);
    return;
  }
  for (auto i : mp) {
    if (i.second > 0) {
      mp[i.first]--;
      temp.push_back(i.first);
      solve(mp, ans, temp, n);
      mp[i.first]++;
      temp.pop_back();
    }
  }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
  unordered_map<int, int> mp;
  vector<vector<int>> ans;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    mp[nums[i]]++;
  }
  vector<int> temp;
  solve(mp, ans, temp, n);
  return ans;
}

int main() { return 0; }

