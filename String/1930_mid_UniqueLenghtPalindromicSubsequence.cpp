#include <bits/stdc++.h>
using namespace std;

// brute force solution
// error TLE

class Solution {
public:
  int countPalindromicSubsequence(string s) {
    int n = s.size(), ans = 0;
    unordered_set<string> st;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          string temp = "";
          temp += s[i];
          temp += s[j];
          temp += s[k];
          if (s[i] == s[k] && st.find(temp) == st.end()) {
            ans++;
            st.insert(temp);
          }
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
