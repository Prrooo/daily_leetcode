#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, zeroCount = 0, oneCount = 0;
  cin >> n;
  string s, r;
  cin >> s >> r;
  for (auto i : s) {
    if (i == '1')
      oneCount++;
    else
      zeroCount++;
  }
  for (int i = 0; i < n - 1; i++) {
    if (zeroCount == 0 || oneCount == 0) {
      cout << "NO" << endl;
      return;
    }
    if (r[i] == '0')
      oneCount--;
    else
      zeroCount--;
  }
  cout << "YES" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
