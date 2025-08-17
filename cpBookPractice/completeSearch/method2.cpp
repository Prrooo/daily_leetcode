// bitmanipulation way book page no 48 for reference

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &x : arr)
    cin >> x;

  // another way to generate all the subset of the array a better way

  for (int i = 0; i < (1 << n); i++) {
    vector<int> subSet;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j))
        subSet.push_back(arr[j]);
    }
    for (auto i : subSet)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
