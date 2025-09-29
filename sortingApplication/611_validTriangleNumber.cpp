#include <bits/stdc++.h>
using namespace std;

// best solution using sorting

class Solution {
public:
  int triangleNumber(vector<int> &nums) {
    int n = nums.size(), count = 0;
    sort(nums.begin(), nums.end());
    for (int i = n - 1; i >= 2; i--) {
      int left = 0, right = i - 1;
      while (left < right) {
        if (nums[left] + nums[right] > nums[i]) {
          count += right - left;
          right--;
        } else {
          left++;
        }
      }
    }
    return count;
  }
};

// brute force solution
// error TLE

class Solution1 {
public:
  int triangleNumber(vector<int> &nums) {
    int n = nums.size(), count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (nums[i] + nums[j] > nums[k] && nums[i] + nums[k] > nums[j] &&
              nums[j] + nums[k] > nums[i])
            count++;
        }
      }
    }
    return count;
  }
};

int main() { return 0; }
