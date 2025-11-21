#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr) {
    cin >> i;
  }
  for (auto i : arr)
    cout << i << " ";
  cout << endl;
  return 0;
}
