#include <bits/stdc++.h>
using namespace std;

queue<int> reverseQueue(queue<int> &q) {
  int n = q.size();
  stack<int> st;
  for (int i = 0; i < n; i++) {
    st.push(q.front());
    q.pop();
  }
  while (!st.empty()) {
    q.push(st.top());
    st.pop();
  }
  return q;
}

int main() {
  int n;
  cin >> n;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    q.push(x);
  }
  reverseQueue(q);
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}
