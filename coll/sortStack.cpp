#include <bits/stdc++.h>
using namespace std;

void sortSt(stack<int> &st) {
  priority_queue<int, vector<int>, greater<int>> pq;
  while (!st.empty()) {
    pq.push(st.top());
    st.pop();
  }
  while (!pq.empty()) {
    st.push(pq.top());
    pq.pop();
  }
}

int main() {
  int n;
  cin >> n;
  stack<int> st;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.push(x);
  }
  sortSt(st);
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
}
