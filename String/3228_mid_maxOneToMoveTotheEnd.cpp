// You can perform the following operation on the string any number of times:
//
//     Choose any index i from the string where i + 1 < s.length such that s[i]
//     == '1' and s[i + 1] == '0'. Move the character s[i] to the right until it
//     reaches the end of the string or another '1'. For example, for s =
//     "010010", if we choose i = 1, the resulting string will be s = "000110".
//
// Return the maximum number of operations that you can perform.
//
//
//
// Example 1:
//
// Input: s = "1001101"
//
// Output: 4
//
// Explanation:
//
// We can perform the following operations:
//
//     Choose index i = 0. The resulting string is s = "0011101".
//     Choose index i = 4. The resulting string is s = "0011011".
//     Choose index i = 3. The resulting string is s = "0010111".
//     Choose index i = 2. The resulting string is s = "0001111".
//
// Example 2:
//
// Input: s = "00111"
//
// Output: 0

#include <bits/stdc++.h>
using namespace std;

// best solution

class Solution {
public:
  int maxOperations(string s) {
    int n = s.size();
    int oneCount = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        oneCount++;
      } else {
        while ((i + 1) < n && s[i + 1] == '0') {
          i++;
        }
        ans += oneCount;
      }
    }
    return ans;
  }
};

// brute force solution
// error TLE

class Solution1 {
public:
  int maxOperations(string s) {
    int n = s.size(), count = 0;
    for (int a = 0; a < n; a++) {
      for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
          int j = i;
          while ((j + 1) < n && s[j + 1] == '0') {
            j++;
          }
          if (i != j) {
            count++;
            s[j] = '1';
            s[i] = '0';
          }
        }
      }
    }
    return count;
  }
};

int main() { return 0; }
