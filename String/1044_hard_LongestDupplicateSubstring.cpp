#include <bits/stdc++.h>
using namespace std;

// brute force solution
// error TLE

class Solution1 {
public:
  string longestDupSubstring(string s) {
    int n = s.size();
    unordered_map<string, int> mp;
    string ans = "";
    for (int i = 0; i < n; i++) {
      string temp = "";
      for (int j = i; j < n; j++) {
        temp += s[j];
        mp[temp]++;
        if (mp[temp] > 1 && temp.size() > ans.size()) {
          ans = temp;
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
