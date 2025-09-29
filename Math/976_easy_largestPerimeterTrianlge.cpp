#include <bits/stdc++.h>
using namespace std;

class Solution3 {
public:
  int largestPerimeter(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = n - 1; i >= 2; i--) {
      if (nums[i - 2] + nums[i - 1] > nums[i]) {
        return nums[i - 2] + nums[i - 1] + nums[i];
      }
    }
    return 0;
  }
};

// work but also TLE

class Solution2 {
public:
  int largestPerimeter(vector<int> &nums) {
    int n = nums.size(), ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = n - 1; i >= 2; i--) {
      int left = 0, right = i - 1;
      while (left < right) {
        if (nums[left] + nums[right] > nums[i]) {
          for (int j = left; j < right; j++) {
            ans = max(ans, nums[i] + nums[right] + nums[j]);
          }
          right--;
        } else {
          left++;
        }
      }
    }
    return ans;
  }
};

// correct ans but TLE

class Solution {
public:
  int largestPerimeter(vector<int> &nums) {
    int n = nums.size(), ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (nums[i] + nums[j] > nums[k] && nums[i] + nums[k] > nums[j] &&
              nums[j] + nums[k] > nums[i]) {
            ans = max(ans, nums[i] + nums[j] + nums[k]);
          }
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
