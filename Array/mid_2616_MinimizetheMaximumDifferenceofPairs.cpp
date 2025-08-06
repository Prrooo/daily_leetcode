#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool solve(vector<int> &nums, int p, int mid, int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
      if ((nums[i + 1] - nums[i]) <= mid) {
        count++;
        i++;
      }
    }
    if (count >= p)
      return true;
    return false;
  }

  int minimizeMax(vector<int> &nums, int p) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int left = 0, right = nums[n - 1] - nums[0];
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (solve(nums, p, mid, n)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return right;
  }
};

int main() { return 0; }
