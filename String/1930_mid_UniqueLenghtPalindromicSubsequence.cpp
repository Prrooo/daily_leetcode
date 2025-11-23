#include <bits/stdc++.h>
using namespace std;

// best solution according to me

class Solution1 {
public:
  int countPalindromicSubsequence(string s) {
    int n = s.size(), ans = 0;
    vector<pair<int, int>> count(26, {-1, -1});
    for (int i = 0; i < n; i++) {
      if (count[s[i] - 'a'].first == -1) {
        count[s[i] - 'a'].first = i;
      }
      count[s[i] - 'a'].second = i;
    }

    for (int i = 0; i < 26; i++) {
      if ((count[i].first == -1 && count[i].second == -1) ||
          (count[i].first == count[i].second))
        continue;

      unordered_set<char> temp;
      for (int j = count[i].first + 1; j < count[i].second; j++) {
        temp.insert(s[j]);
      }
      ans += temp.size();
    }
    return ans;
  }
};

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
