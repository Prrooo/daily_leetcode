#include <bits/stdc++.h>
using namespace std;

// this soluiton work but i think better soluiton exists

class Solution {
public:
  int mod = 1e9 + 7;
  int numSub(string s) {
    int count = 0, n = s.size(), ans = 0;
    int i = 0;
    while (i < n) {
      if (s[i] == '0') {
        count = 0;
        i++;
      } else {
        while (i < n && s[i] == '1') {
          count++;
          ans = (ans + count) % mod;
          i++;
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
