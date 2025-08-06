#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      st.push(s[i]);
    } else {
      if (st.empty())
        return false;
      else if (s[i] == ')' && st.top() != '(')
        return false;
      else if (s[i] == ']' && st.top() != '[')
        return false;
      else if (s[i] == '}' && st.top() != '{')
        return false;
      st.pop();
    }
  }
  if (!st.empty())
    return false;
  return true;
}

int main() {
  string s;
  cin >> s;
  cout << isValid(s);
  return 0;
}
