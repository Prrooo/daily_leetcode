// refere page no 49 for details

#include <bits/stdc++.h>
using namespace std;

// using recurssion choose whether to take the element or not

void allPermutation(vector<int> &arr, vector<vector<int>> &res, int n,
                    vector<int> temp) {
  if (temp.size() == n) {
    res.push_back(temp);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] == -1)
      continue;

    temp.push_back(arr[i]);
    int old = arr[i];
    arr[i] = -1;
    allPermutation(arr, res, n, temp);
    arr[i] = old;
    temp.pop_back();
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;

  vector<vector<int>> res;
  allPermutation(arr, res, n, {});
  for (auto i : res) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
