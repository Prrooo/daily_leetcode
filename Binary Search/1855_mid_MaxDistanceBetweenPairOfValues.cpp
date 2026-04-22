#include <bits/stdc++.h>
using namespace std;

// two pointer solution

class Solution {
public:
  int maxDistance(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();
    int ans = 0, i = 0, j = 0;
    while (i < n && j < m) {
      if (nums1[i] <= nums2[j]) {
        ans = max(ans, j - i);
        j++;
      } else {
        i++;
        if (i > j)
          j = i;
      }
    }
    return ans;
  }
};

// binary search solution force solution

class Solution1 {
public:
  int solve(vector<int> &nums, int target, int left, int m) {
    int right = m - 1, ans = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        ans = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }

  int maxDistance(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();
    int ans = 0, i = 0, j = 0;
    for (int i = 0; i < n; i++) {
      int index = solve(nums2, nums1[i], i, m);
      if (index == -1)
        continue;
      ans = max(ans, index - i);
    }
    return ans;
  }
};

int main() { return 0; }
