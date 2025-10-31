// important question for new bit concept
// https://www.youtube.com/watch?v=5Vjt_w5Zi-A
// for reference

#include <bits/stdc++.h>
using namespace std;

// best solution using bit manipulation

class Solution {
public:
  vector<int> getSneakyNumbers(vector<int> &nums) {
    int XOR = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      XOR ^= nums[i];
    }
    for (int i = 0; i < n - 2; i++) {
      XOR ^= i;
    }
    int sep = 1 << __builtin_ctz(XOR);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (sep & nums[i])
        a ^= nums[i];
      else
        b ^= nums[i];
    }
    for (int i = 0; i < n - 2; i++) {
      if (sep & i)
        a ^= i;
      else
        b ^= i;
    }
    return {a, b};
  }
};

// using sorting
// not the best solution

class Solution {
public:
  vector<int> getSneakyNumbers(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<int> res;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        res.push_back(nums[i]);
      }
    }
    return res;
  }
};

int main() { return 0; }
