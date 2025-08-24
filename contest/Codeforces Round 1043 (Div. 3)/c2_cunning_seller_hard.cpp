#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

typedef long long ll;

ll p[30];

void precompute_powers() {
  p[0] = 1;
  for (int i = 1; i < 30; i++) {
    p[i] = p[i - 1] * 3;
  }
}

ll cost(int i) {
  if (i == 0)
    return 3;
  return p[i + 1] + i * p[i - 1];
}

int main() {
  precompute_powers();
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    vector<int> digits;
    ll temp = n;
    while (temp) {
      digits.push_back(temp % 3);
      temp /= 3;
    }
    if (digits.empty()) {
      digits.push_back(0);
    }
    int L = digits.size() - 1;
    ll S = accumulate(digits.begin(), digits.end(), 0);
    if (k < S) {
      cout << -1 << endl;
      continue;
    }
    ll T_max = 0;
    for (int i = 0; i <= L; i++) {
      if (digits[i] > 0 && i > 0) {
        T_max += digits[i] * (p[i] - 1) / 2;
      }
    }
    ll cost_min = 0;
    for (int i = 0; i <= L; i++) {
      if (digits[i] > 0) {
        cost_min += digits[i] * cost(i);
      }
    }
    ll M = min(n, k);
    if (M % 2 != S % 2) {
      M--;
    }
    while (M >= S && (M - S) / 2 > T_max) {
      M -= 2;
    }
    if (M < S) {
      cout << -1 << endl;
    } else {
      ll T = (M - S) / 2;
      vector<ll> breaks(L + 1, 0);
      if (L > 0) {
        breaks[L] = min(T, (ll)digits[L]);
        ll rem = T - breaks[L];
        for (int i = L - 1; i >= 1; i--) {
          breaks[i] = min(rem, (ll)digits[i] + 3 * breaks[i + 1]);
          rem -= breaks[i];
        }
      }
      ll reduction = 0;
      for (int i = 1; i <= L; i++) {
        reduction += breaks[i] * p[i - 1];
      }
      ll ans = cost_min - reduction;
      cout << ans << endl;
    }
  }
  return 0;
}
