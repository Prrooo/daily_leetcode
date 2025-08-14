#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    x--;

    int total_walls = 0;
    for (char c : s) {
      if (c == '#') {
        total_walls++;
      }
    }

    int left_empty = 0;
    for (int i = 0; i < x; i++) {
      if (s[i] == '.') {
        left_empty++;
      }
    }

    int right_empty = 0;
    for (int i = x + 1; i < n; i++) {
      if (s[i] == '.') {
        right_empty++;
      }
    }

    cout << total_walls + min(left_empty, right_empty) << '\n';
  }
  return 0;
}
