#include <bits/stdc++.h>
using namespace std;

int priority(char b) {
  if (b == '^')
    return 4;
  else if (b == '*')
    return 3;
  else if (b == '/')
    return 2;
  else if (b == '+' || b == '-')
    return 1;
  return -1;
}

string infixToPostfix(string &s) {
  int n = s.size();
  string ans = "";
  stack<char> st;
  for (int i = 0; i < n; i++) {
    // we print all the character from a-z OR A-Z
    if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)) {
      ans += s[i];
    } else if (s[i] == '(') {
      st.push(s[i]);
    }
    // pop out of symbol form stack until we get '('
    else if (s[i] == ')') {
      while (!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      st.pop();
    } else {
      if (st.empty()) {
        st.push(s[i]);
      }
      // if the priority of stack stop element is greater than current element
      // we pop the stack top and print and then push the new element in stack
      // else if prioirty is not greater than we just push in the stack
      else if (priority(s[i]) < priority(st.top())) {
        ans += st.top();
        st.pop();
        st.push(s[i]);
      } else {
        st.push(s[i]);
      }
    }
  }
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << infixToPostfix(s);
  return 0;
}
