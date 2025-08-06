// Given a array arr of integers, return the sums of all subsets in the list.
// Return the sums in any order.
//
// Examples:
//
// Input: arr[] = [2, 3]
// Output: [0, 2, 3, 5]

// one way to solve this using for loop

#include <bits/stdc++.h>
using namespace std;

// void solve(vector<int> &arr, int index, int sum, vector<int> &result) {
//   result.push_back(sum);
//   for (int i = index; i < arr.size(); i++) {
//     sum += arr[i];
//     solve(arr, i + 1, sum, result);
//     sum -= arr[i];
//   }
// }
//
// vector<int> subsetSums(vector<int> &arr) {
//   int sum = 0;
//   vector<int> result;
//   solve(arr, 0, sum, result);
//   return result;
// }

// other way to solve this without for loop

void solve(vector<int> &arr, vector<int> &result, int index, int n, int sum) {
  if (index == n) {
    result.push_back(sum);
    return;
  }
  // without taking the sum of current element
  solve(arr, result, index + 1, n, sum);
  // with taking the sum of current element
  solve(arr, result, index + 1, n, sum + arr[index]);
}

vector<int> subsetSums(vector<int> &arr) {
  int n = arr.size(), sum = 0;
  vector<int> result;
  solve(arr, result, 0, n, sum);
  return result;
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
  vector<int> result = subsetSums(arr);
  for (auto i : result) {
    cout << i << " ";
  }
  return 0;
}
