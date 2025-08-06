#include <bits/stdc++.h>
using namespace std;

int largest(int arr[], int n) {
  int ans = arr[0];
  for (int i = 0; i < n; i++) {
    ans = max(ans, arr[i]);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << largest(arr, n);
}
