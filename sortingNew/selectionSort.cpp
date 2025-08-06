// selectionSort
// First we find the smallest element and swap it with the first element. This
// way we get the smallest element at its correct position.
// Then we find the smallest among remaining elements (or second smallest) and
// swap it with the second element. We keep doing this until we get all elements
// moved to correct position.

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr) {
  int n = arr.size();
  if (n == 1)
    return;
  for (int i = 0; i < n; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
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
  selectionSort(arr);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
