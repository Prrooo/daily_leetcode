#include <bits/stdc++.h>
using namespace std;

// best solution
// time complexity O(n)

class Solution1 {
public:
  bool isTrionic(vector<int> &nums) {
    int n = nums.size(), i = 1;
    bool first = false;
    while (i < n && nums[i] > nums[i - 1]) {
      i++;
      first = true;
    }
    bool second = false;
    while (i < n && nums[i] < nums[i - 1]) {
      i++;
      second = true;
    }
    bool third = false;
    while (i < n && nums[i] > nums[i - 1]) {
      i++;
      third = true;
    }
    if (first && second && third && i == n) {
      return true;
    }
    return false;
  }
};

// brute force solution

class Solution {
public:
  bool is_sorted1(vector<int> &nums, int start, int end) {
    for (int i = start; i < end; i++) {
      if (nums[i] <= nums[i - 1])
        return false;
    }
    return true;
  }

  bool is_sorted2(vector<int> &nums, int start, int end) {
    for (int i = start; i < end; i++) {
      if (nums[i] >= nums[i - 1])
        return false;
    }
    return true;
  }

  bool isTrionic(vector<int> &nums) {
    int n = nums.size();
    for (int i = 1; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        bool first = is_sorted1(nums, 1, i + 1);
        bool second = is_sorted2(nums, i + 1, j + 1);
        bool third = is_sorted1(nums, j + 1, n);
        if (first && second && third)
          return true;
      }
    }
    return false;
  }
};

int main() { return 0; }
