#include <bits/stdc++.h>
using namespace std;

int getSecondLargest(vector<int> arr) {
  int n = arr.size();
  if (n == 0 || n == 1)
    return -1;
  int larg = arr[0];
  int sec = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] > larg) {
      sec = larg;
      larg = arr[i];
    } else if (arr[i] > sec && arr[i] < larg) {
      sec = arr[i];
    }
  }
  if (sec == INT_MIN)
    return -1;
  return sec;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << getSecondLargest(arr);
  return 0;
}
