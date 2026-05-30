#include <bits/stdc++.h>
using namespace std;

int divideConq(vector<int> &arr, int left, int right) {
  int i = left - 1;
  int pivot = right;
  for (int j = left; j < right; j++) {
    if (arr[j] < arr[pivot]) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[right]);
  return i + 1;
}

void quickSort(vector<int> &arr, int left, int right) {
  if (left < right) {
    int pivot = divideConq(arr, left, right);
    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr) {
    cin >> i;
  }
  quickSort(arr, 0, n - 1);
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
