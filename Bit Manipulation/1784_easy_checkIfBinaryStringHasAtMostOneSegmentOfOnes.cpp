// Given a binary string s ​​​​​without leading zeros, return
// true​​​ if s contains at most one contiguous segment of ones.
// Otherwise, return false.
//
//
//
// Example 1:
//
// Input: s = "1001"
// Output: false
// Explanation: The ones do not form a contiguous segment.
//
// Example 2:
//
// Input: s = "110"
// Output: true

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkOnesSegment(string s) {
    int count = 0, n = s.size();
    bool check = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && !check) {
        check = true;
        count++;
      }
      if (s[i] == '0')
        check = false;
    }
    return count == 1 ? true : false;
  }
};

int main() { return 0; }
