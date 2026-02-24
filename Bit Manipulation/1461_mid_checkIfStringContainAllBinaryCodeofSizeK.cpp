#include <bits/stdc++.h>
using namespace std;

// time complexity O(n) where n is the length of the string s

class Solution {
public:
  void solve(string s, unordered_map<int, int> &mp, int val, int n) {
    int left = 0, right = 0;
    long long curr = 0;
    while (left < n && right < n) {
      while (right < n && right - left < val) {
        // curr = curr * 2 + s[right++] - '0';
        curr = (curr << 1) | s[right++] - '0';
      }
      mp[curr]++;
      if (s[left] == '1') {
        curr -= pow(2, val - 1);
      }
      left++;
    }
  }

  bool hasAllCodes(string s, int k) {
    int n = s.size();
    unordered_map<int, int> mp;
    solve(s, mp, k, n);
    long long sz = pow(2, k) - 1;
    for (int i = 0; i <= sz; i++) {
      if (mp.find(i) == mp.end()) {
        return false;
      }
    }
    return true;
  }
};

int main() { return 0; }
