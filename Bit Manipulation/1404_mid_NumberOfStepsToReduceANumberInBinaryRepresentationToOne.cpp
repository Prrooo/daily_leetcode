#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool solve(string &s, int index, int n) {
    int i = index;
    while (i >= 0 && s[i] == '1') {
      s[i] = '0';
      i--;
    }
    if (i < 0) {
      s = '1' + s;
      return true;
    }
    s[i] = '1';
    return false;
  }

  int numSteps(string s) {
    int n = s.size(), count = 0;
    int i = n - 1;
    while (i >= 1) {
      if (s[i] == '1') {
        if (solve(s, i, n)) {
          i++;
        }
      } else {
        i--;
      }
      count++;
    }
    return count;
  }
};

int main() { return 0; }
