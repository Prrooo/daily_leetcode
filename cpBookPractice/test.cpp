#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n, 0));
  for (auto i : arr) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }

  for (auto i : arr) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}
