#include <bits/stdc++.h>
using namespace std;

// brute force solution
// better solution existe

class Solution {
public:
  bool solve(string s, string temp, int n) {
    int m = temp.size();
    int i = 0;
    while (i < n) {
      for (int k = 0; k < m; k++) {
        if (s[i] != temp[k])
          return false;
        i++;
      }
    }
    return true;
  }

  bool repeatedSubstringPattern(string s) {
    int n = s.size();
    string temp = "";
    for (int i = 0; i < n - 1; i++) {
      temp += s[i];
      if (n % temp.size() == 0 && solve(s, temp, n)) {
        return true;
      }
    }
    return false;
  }
};

// not best solution but solution with more thinking

class Solution1 {
public:
  bool repeatedSubstringPattern(string s) {
    int n = s.size();
    string temp = "";
    for (int i = 0; i < n - 1; i++) {
      temp += s[i];
      int m = temp.size();
      if (n % m != 0)
        continue;
      string finalTemp = "";
      for (int j = 0; j < n / m; j++) {
        finalTemp += temp;
      }
      if (finalTemp == s)
        return true;
    }
    return false;
  }
};

int main() { return 0; }
