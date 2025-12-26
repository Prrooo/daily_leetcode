#include <bits/stdc++.h>
using namespace std;

int main() {
  // 2D vector with 4 columns (index 0 to 3)
  // vector<vector<int>> m = {{1, 8, 3, 4}, {1, 9, 1, 5}, {1, 4, 2, 6}};
  //
  // cout << "Before sorting:" << endl;
  // for (const auto &row : m) {
  //   for (int elem : row) {
  //     cout << elem << " ";
  //   }
  //   cout << endl;
  // }
  //
  // // Sort based on the 3rd column (index 2) in ascending order
  // sort(m.begin(), m.end(), [](const vector<int> &a, const vector<int> &b) {
  //   return a.at(2) < b.at(2); // Use .at() for bounds checking
  // });
  //
  // cout << "\nAfter sorting by the 3rd column (ascending):" << endl;
  // for (const auto &row : m) {
  //   for (int elem : row) {
  //     ::cout << elem << " ";
  //   }
  //   cout << endl;
  // }

  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> qu;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    qu.push(x);
  }

  while (!qu.empty()) {
    cout << qu.top() << " ";
    qu.pop();
  }

  return 0;
}
