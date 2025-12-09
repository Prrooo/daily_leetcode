#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr) {
  int n = arr.size();
  deque<int> maxEle;
  for (int i = 0; i < n; i++) {
    while (!maxEle.empty() && arr[i] > maxEle.back()) {
      maxEle.pop_back();
    }
    maxEle.push_back(arr[i]);
    cout << 0 << " " << i << " - " << maxEle.front() << endl;
  }

  cout << "-------------------------------" << endl;

  for (int i = 0; i < n; i++) {
    if (arr[i] == maxEle.front()) {
      maxEle.pop_front();
    }
    cout << i + 1 << " " << n - 1 << " - " << maxEle.front() << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr) {
    cin >> i;
  }

  solve(arr);
  return 0;
}
