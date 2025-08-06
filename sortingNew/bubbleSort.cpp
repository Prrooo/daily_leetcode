// BubbleSort
// We sort the array using multiple passes. After the first pass, the maximum
// element goes to end (its correct position). Same way, after second pass, the
// second largest element goes to second last position and so on. In every pass,
// we process only those elements that have already not moved to correct
// position. After k passes, the largest k elements must have been moved to the
// last k positions. In a pass, we consider remaining elements and compare all
// adjacent and swap if larger element is before a smaller element. If we keep
// doing this, we get the largest (among the remaining elements) at its correct
// position.

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr) {
  int n = arr.size();
  if (n == 1)
    return;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
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
  bubbleSort(arr);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
