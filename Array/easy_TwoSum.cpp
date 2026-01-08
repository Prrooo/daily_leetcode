#include <bits/stdc++.h>
using namespace std;

// good solution

class Solution1 {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
      int need = target - nums[i];
      if (mp.find(need) != mp.end()) {
        return {mp[need], i};
      }
      mp[nums[i]] = i;
    }
    return {};
  }
};

// not best solution
// not recommended

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<pair<int, int>> arr;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      arr.push_back({nums[i], i});
    }
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
      if ((arr[left].first + arr[right].first) == target) {
        return {arr[left].second, arr[right].second};
      } else if ((arr[left].first + arr[right].first) > target) {
        right--;
      } else {
        left++;
      }
    }
    return {};
  }
};

int main() { return 0; }
