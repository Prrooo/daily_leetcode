#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      count++;
    }
  }
  cout << n << " " << count << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    solve(i);
  }
  return 0;
}
