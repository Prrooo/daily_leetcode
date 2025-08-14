#include <bits/stdc++.h>
using namespace std;

int mySolve(vector<int> &arr) {
  int n = arr.size();
  int sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum < 0) {
      sum = 0;
    }
    ans = max(ans, sum);
  }
  return ans;
}

int bookSolve(vector<int> &arr) {
  int n = arr.size();
  int sum = 0, best = 0;
  for (int i = 0; i < n; i++) {
    sum = max(sum, sum + arr[i]);
    best = max(best, sum);
  }
  return best;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &x : arr)
    cin >> x;
  cout << mySolve(arr) << endl;
  cout << bookSolve(arr) << endl;
  return 0;
}
