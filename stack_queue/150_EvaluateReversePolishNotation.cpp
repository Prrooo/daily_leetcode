#include <bits/stdc++.h>
using namespace std;

long resolve(int n1, int n2, string opt) {
  if (opt == "+")
    return n1 + n2;
  else if (opt == "-")
    return n1 - n2;
  else if (opt == "*")
    return n1 * n2;
  return n1 / n2;
}

int evalRPN(vector<string> &tokens) {
  int n = tokens.size();
  stack<int> result;
  for (int i = 0; i < n; i++) {
    if (tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/" ||
        tokens[i] == "-") {
      int n1 = result.top();
      result.pop();
      int n2 = result.top();
      result.pop();
      result.push(resolve(n2, n1, tokens[i]));
    } else {
      int no = stoi(tokens[i]);
      result.push(no);
    }
  }
  return result.top();
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << evalRPN(arr);
  return 0;
}
