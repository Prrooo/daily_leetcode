#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    bool hasZero = false;
    set<int> fixedSet;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) {
        hasZero = true;
      } else if (a[i] != -1) {
        fixedSet.insert(a[i]);
      }
    }

    if (hasZero) {
      cout << "NO\n";
    } else if (fixedSet.size() <= 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
