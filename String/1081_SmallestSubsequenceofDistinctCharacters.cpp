// Given a string s, return the lexicographically smallest subsequence of s that
// contains all the distinct characters of s exactly once.
//
//
//
// Example 1:
//
// Input: s = "bcabc"
// Output: "abc"
// Example 2:
//
// Input: s = "cbacdcbc"
// Output: "acdb"

#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {
  int n = s.size();
  vector<int> lastSeenIndex(26, -1);
  for (int i = 0; i < n; i++) {
    lastSeenIndex[s[i] - 'a'] = i;
  }
  vector<bool> visited(26, false);
  stack<char> st;
  for (int i = 0; i < n; i++) {
    if (visited[s[i] - 'a'])
      continue;
    while (!st.empty() && st.top() > s[i] &&
           i < lastSeenIndex[st.top() - 'a']) {
      visited[st.top() - 'a'] = false;
      st.pop();
    }
    st.push(s[i]);
    visited[s[i] - 'a'] = true;
  }
  string ans = "";
  while (!st.empty()) {
    ans = st.top() + ans;
    st.pop();
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << removeDuplicateLetters(s);
  return 0;
}
