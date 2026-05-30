#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int quickmul(int x, int y) {
  int ret = 1;
  int cur = x;
  while (y) {
    if (y & 1) {
      ret = (long long)ret * cur % mod;
    }
    cur = (long long)cur * cur % mod;
    y >>= 1;
  }
  return ret;
}

int main() {
  cout << quickmul(2, mod - 2) << endl;
  return 0;
}
