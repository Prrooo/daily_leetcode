// book page no 48 for reference

#include <bits/stdc++.h>
using namespace std;

void recSubSet(vector<int> &arr, vector<vector<int>> &res, int n, int index,
               vector<int> temp) {
  if (index >= n) {
    res.push_back(temp);
    return;
  }
  recSubSet(arr, res, n, index + 1, temp);
  temp.push_back(arr[index]);
  recSubSet(arr, res, n, index + 1, temp);
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;

  // to generate all the subset 1st method is using recurssion
  vector<vector<int>> res;
  recSubSet(arr, res, arr.size(), 0, {});

  for (auto i : res) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  cout << res.size();
  return 0;
}
