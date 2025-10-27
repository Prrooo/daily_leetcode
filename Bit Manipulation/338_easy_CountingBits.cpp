// Given an integer n, return an array ans of length n + 1 such that for each i
// (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
//
//
//
// Example 1:
//
// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
//
// Example 2:
//
// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101
//

#include <bits/stdc++.h>
using namespace std;

// using dp

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    int pre = 1;
    for (int i = 1; i <= n; i++) {
      if (pre * 2 == i) {
        pre = i;
      }
      dp[i] = dp[i - pre] + 1;
    }
    return dp;
  }
};

int main() { return 0; }
