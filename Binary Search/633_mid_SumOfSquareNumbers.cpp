// Given a non-negative integer c, decide whether there're two integers a and b
// such that a2 + b2 = c.
//
//
//
// Example 1:
//
// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5
//
// Example 2:
//
// Input: c = 3
// Output: false

#include <bits/stdc++.h>
using namespace std;

// optimal solution

class Solution {
public:
  bool judgeSquareSum(int c) {
    int left = 0, right = sqrt(c);
    while (left <= right) {
      long long sum = 1LL * left * left + 1LL * right * right;
      if (sum == c)
        return true;
      else if (sum > c)
        right--;
      else
        left++;
    }
    return false;
  }
};

// not best solution

class Solution1 {
public:
  bool solve(int target) {
    int left = 0, right = sqrt(target);
    while (left <= right) {
      int mid = left + (right - left) / 2;
      long long temp = mid * mid;
      if (temp == target) {
        return true;
      } else if (temp > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return false;
  }

  bool judgeSquareSum(int c) {
    int right = sqrt(c);
    for (int i = 0; i <= right; i++) {
      if (solve(c - (i * i))) {
        return true;
      }
    }
    return false;
  }
};

int main() { return 0; }
