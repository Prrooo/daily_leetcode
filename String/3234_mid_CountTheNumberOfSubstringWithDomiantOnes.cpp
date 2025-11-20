#include <bits/stdc++.h>
using namespace std;

// this is the brute force solution
// error TLE

class Solution1 {
public:
  int numberOfSubstrings(string s) {
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int oneCount = 0, zeroCount = 0;
      for (int j = i; j < n; j++) {
        if (s[j] == '0') {
          zeroCount++;
        } else {
          oneCount++;
        }
        if ((zeroCount * zeroCount) <= oneCount) {
          ans++;
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
