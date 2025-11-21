#include <bits/stdc++.h>
using namespace std;

// best solution

class Solution {
public:
  int numberOfSubstrings(string s) {
    int n = s.size();
    int ans = 0;
    vector<int> count(n, 0);
    count[0] = s[0] == '1' ? 1 : 0;
    for (int i = 1; i < n; i++) {
      count[i] = count[i - 1] + (s[i] == '1' ? 1 : 0);
    }

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int oneCount = count[j] - ((i - 1) < 0 ? 0 : count[i - 1]);
        int zeroCount = (j - i + 1) - oneCount;
        if ((zeroCount * zeroCount) > oneCount) {
          int jump = (zeroCount * zeroCount) - oneCount;
          j += jump - 1;
        } else if ((zeroCount * zeroCount) == oneCount) {
          ans++;
        } else {
          ans++;
          int jump = sqrt(oneCount) - zeroCount;
          int next = jump + j;
          if (next >= n) {
            ans += (n - j - 1);
            break;
          } else {
            ans += jump;
          }
          j = next;
        }
      }
    }
    return ans;
  }
};

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
