// You are given an integer mountain array arr of length n where the values
// increase to a peak element and then decrease.
//
// Return the index of the peak element.
//
// Your task is to solve it in O(log(n)) time complexity.
//
// Example 1:
//
// Input: arr = [0,1,0]
//
// Output: 1
//
// Example 2:
//
// Input: arr = [0,2,1,0]
//
// Output: 1
//
// Example 3:
//
// Input: arr = [0,10,5,2]
//
// Output: 1

#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr) {
  long long low = 0, high = arr.size() - 1, n = arr.size();
  while (low <= high) {
    long long mid = (high + low) / 2;
    if (mid - 1 >= 0 && mid + 1 < n && arr[mid] > arr[mid - 1] &&
        arr[mid] > arr[mid + 1]) {
      return mid;
    } else if (arr[mid] < arr[mid + 1]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
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
  cout << peakIndexInMountainArray(arr);
  return 0;
}

