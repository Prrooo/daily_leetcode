#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> ans;
    ll base = 10;
    while (base + 1 <= n) {
      if (n % (base + 1) == 0) {
        ans.push_back(n / (base + 1));
      }
      if (base > n / 10) {
        break;
      }
      base *= 10;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); i++) {
      cout << ans[i];
      if (i < ans.size() - 1) {
        cout << " ";
      }
    }
    if (ans.size() > 0) {
      cout << endl;
    }
  }
  return 0;
}
