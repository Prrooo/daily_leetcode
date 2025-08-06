// Given a string s, remove duplicate letters so that every letter appears once
// and only once. You must make sure your result is the smallest in
// lexicographical order among all possible results.
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

// solution approach
//
// We use lastseenIndex vector to store the last index of the charracter in the
// string to if present when we delete its dublicate before it

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
    // in this we will pop the stack top until the stack is empty and its top
    // have high value than the current charrcter in the string and the element
    // at the top of the stack is also present afterwords in the string
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
