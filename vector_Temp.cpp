#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr) {
  vector<int> ans;
  return ans;
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
  vector<int> result = solve(arr);
  for (auto i : result) {
    cout << i << " ";
  }
  return 0;
}
