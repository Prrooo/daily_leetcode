#include <bits/stdc++.h>
using namespace std;

// best solution

class Solution {
public:
  int repeatedNTimes(vector<int> &nums) {

    for (int i = 0; i < nums.size() - 2; i++) {
      if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2]) {
        return nums[i];
      }
    }

    return nums[nums.size() - 1];
  }
};

// brute force solution

class Solution1 {
public:
  int repeatedNTimes(vector<int> &nums) {
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      mp[nums[i]]++;
      if (mp[nums[i]] == (n / 2))
        return nums[i];
    }
    return -1;
  }
};

int main() { return 0; }
