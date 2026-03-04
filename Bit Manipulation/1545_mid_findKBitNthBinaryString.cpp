#include <bits/stdc++.h>
using namespace std;

// recursion time compleixity O(n) space complexity O(n)

class Solution {
public:
  char findKthBit(int n, int k) {
    if (n == 1)
      return '0';
    int len = 1 << n;
    int mid = len / 2;
    if (mid == k)
      return '1';
    else if (k < mid) {
      return findKthBit(n - 1, k);
    } else {
      char ans = findKthBit(n - 1, len - k);
      return (ans == '0') ? '1' : '0';
    }
  }
};

// brute force
// time complexity O(2^n) space complexity O(2^n)

class Solution1 {
public:
  string solve(string s) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0')
        s[i] = '1';
      else
        s[i] = '0';
    }
    reverse(s.begin(), s.end());
    return s;
  }

  char findKthBit(int n, int k) {
    vector<string> arr(n);
    arr[0] = "0";
    for (int i = 1; i < n; i++) {
      arr[i] = arr[i - 1] + "1" + solve(arr[i - 1]);
    }
    return arr[n - 1][k - 1];
  }
};

int main() { return 0; }
