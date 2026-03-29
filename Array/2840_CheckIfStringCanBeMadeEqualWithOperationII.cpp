#include <bits/stdc++.h>
using namespace std;

// brute force solution

class Solution {
public:
  int next_index(string &s, char target, int index, int n) {
    for (int i = index; i < n; i += 2) {
      if (s[i] == target)
        return i;
    }
    return -1;
  }

  bool checkStrings(string s1, string s2) {
    int n = s1.size();
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        int index = next_index(s1, s2[i], i + 2, n);
        if (index != -1) {
          s1[index] = s1[i];
          s1[i] = s2[i];
        } else {
          return false;
        }
      }
    }
    return true;
  }
};

int main() { return 0; }
