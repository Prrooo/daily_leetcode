#include <bits/stdc++.h>
using namespace std;

// work but TLE

class Solution {
public:
  bool solve(string s, unordered_set<string> &st, int index, int n) {
    if (index >= n)
      return true;
    string temp = "";
    for (int i = index; i < n; i++) {
      temp += s[i];
      if (st.find(temp) != st.end()) {
        if (solve(s, st, i + 1, n)) {
          return true;
        }
      }
    }
    return false;
  }

  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();
    unordered_set<string> st;
    for (auto i : wordDict) {
      st.insert(i);
    }
    return solve(s, st, 0, n);
  }
};

int main() { return 0; }
