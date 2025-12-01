//
// You are given an array of strings tokens that represents an arithmetic
// expression in a Reverse Polish Notation.
//
// Evaluate the expression. Return an integer that represents the value of the
// expression.
//
// Note that:
//
//     The valid operators are '+', '-', '*', and '/'.
//     Each operand may be an integer or another expression.
//     The division between two integers always truncates toward zero.
//     There will not be any division by zero.
//     The input represents a valid arithmetic expression in a reverse polish
//     notation. The answer and all the intermediate calculations can be
//     represented in a 32-bit integer.
//
//
//
// Example 1:
//
// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
//
// Example 2:
//
// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int solve(int f, int s, string a) {
    if (a == "+")
      return f + s;
    if (a == "-")
      return f - s;
    if (a == "*")
      return f * s;
    return f / s;
  }

  int evalRPN(vector<string> &tokens) {
    int n = tokens.size();
    stack<double> st;
    for (int i = 0; i < n; i++) {
      string a = tokens[i];
      if (a == "+" || a == "-" || a == "*" || a == "/") {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        st.push(solve(second, first, a));
      } else {
        st.push(stoi(a));
      }
    }
    return st.top();
  }
};

int main() { return 0; }
