#include <bits/stdc++.h>
using namespace std;

// two pointer approach
// we keep track of the max pointer from both the ends star and end

class Solution1 {
public:
  int trap(vector<int> &height) {
    int n = height.size(), ans = 0;
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = n - 1;
    while (left < right) {
      if (height[left] <= height[right]) {
        if (height[left] > height[leftMax]) {
          leftMax = left;
        } else {
          ans += height[leftMax] - height[left];
        }
        left++;
      } else {
        if (height[right] > height[rightMax]) {
          rightMax = right;
        } else {
          ans += height[rightMax] - height[right];
        }
        right--;
      }
    }
    return ans;
  }
};

// brute force solution
// error TLE

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size(), maxE = height[0], ans = 0;
    for (int i = 0; i < n; i++) {
      maxE = max(maxE, height[i]);
    }
    int i = 1;
    while (i <= maxE) {
      int left = -1;
      for (int j = 0; j < n; j++) {
        if (height[j] >= i) {
          if (left != -1) {
            ans += (j - left - 1);
          }
          left = j;
        }
      }
      i++;
    }
    return ans;
  }
};

int main() { return 0; }
