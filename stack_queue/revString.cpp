#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  stack<char> st;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    st.push(s[i]);
  }
  string ans = "";
  // new better way
  while (!st.empty()) {
    ans = st.top() + ans;
    st.pop();
  }
  cout << ans;
  return 0;
}
