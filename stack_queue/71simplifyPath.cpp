#include <bits/stdc++.h>
using namespace std;

// my own soluiton
// ----------------------------------------------------------------------
string simplifyPath(string path) {
  int n = path.size();
  string ans = "";
  stack<string> st;
  for (int i = 0; i < n; i++) {
    string buffer = "";
    if (path[i] == '/') {
      continue;
    }
    while (path[i] != '/' && i < n) {
      buffer += path[i];
      i++;
    }
    if (buffer == "..") {
      if (!st.empty()) {
        st.pop();
      }
    } else if (buffer == ".") {
      continue;
    } else {
      st.push(buffer);
    }
  }
  stack<string> pr;
  while (!st.empty()) {
    ans = '/' + st.top() + ans;
    st.pop();
  }
  if (ans == "")
    return "/";
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << simplifyPath(s);
  return 0;
}
