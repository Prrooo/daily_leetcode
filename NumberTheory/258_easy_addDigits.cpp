// Given an integer num, repeatedly add all its digits until the result has only
// one digit, and return it.
//
//
//
// Example 1:
//
// Input: num = 38
// Output: 2
// Explanation: The process is
// 38 --> 3 + 8 --> 11
// 11 --> 1 + 1 --> 2
// Since 2 has only one digit, return it.
//
// Example 2:
//
// Input: num = 0
// Output: 0

#include <bits/stdc++.h>
using namespace std;

// bruteforce solution

class Solution {
public:
  int addDigits(int num) {
    while (num > 9) {
      int temp = num, sum = 0;
      while (temp > 0) {
        sum += temp % 10;
        temp = temp / 10;
      }
      num = sum;
    }
    return num;
  }
};

int main() { return 0; }
