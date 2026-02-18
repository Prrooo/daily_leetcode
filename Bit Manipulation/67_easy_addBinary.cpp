//
// Given two binary strings a and b, return their sum as a binary string.
//
//
//
// Example 1:
//
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
//
// Input: a = "1010", b = "1011"
// Output: "10101"
//
//
//
// Constraints:
//
//     1 <= a.length, b.length <= 104
//     a and b consist only of '0' or '1' characters.
//     Each string does not contain leading zeros except for the zero itself.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int n = a.size(), m = b.size(), i = n - 1, j = m - 1, carry = 0;
    string res = "";
    while (i >= 0 || j >= 0) {
      if (i >= 0) {
        carry += a[i--] - '0';
      }
      if (j >= 0) {
        carry += b[j--] - '0';
      }
      res += carry % 2 + '0';
      carry /= 2;
    }
    if (carry) {
      res += '1';
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() { return 0; }
