// Given two strings s and goal, return true if and only if s can become goal
// after some number of shifts on s.
//
// A shift on s consists of moving the leftmost character of s to the rightmost
// position.
//
//     For example, if s = "abcde", then it will be "bcdea" after one shift.
//
//
//
// Example 1:
//
// Input: s = "abcde", goal = "cdeab"
// Output: true
//
// Example 2:
//
// Input: s = "abcde", goal = "abced"
// Output: false
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool solve(string s, string goal, int index, int n) {
    for (int i = 0; i < n; i++) {
      if (s[i] != goal[index % n])
        return false;
      index++;
    }
    return true;
  }

  bool rotateString(string s, string goal) {
    int n = s.size(), m = goal.size();
    if (n != m)
      return false;
    for (int i = 0; i < n; i++) {
      if (s[0] == goal[i] && solve(s, goal, i, n)) {
        return true;
      }
    }
    return false;
  }
};

int main() { return 0; }
