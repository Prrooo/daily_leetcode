#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int j = i - 1;
    int temp = arr[i];
    while (j >= 0 && arr[j] > arr[i]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

void buketSort(vector<int> &arr) {
  int n = arr.size(), k = 4, maxEle = INT_MIN;
  for (int i = 0; i < n; i++) {
    maxEle = max(maxEle, arr[i]);
  }
  vector<int> buket[k + 1];
  for (int i = 0; i < n; i++) {
    int index = (k * arr[i]) / maxEle;
    buket[index].push_back(arr[i]);
  }

  for (int i = 0; i < (k + 1); i++) {
    // insertionSort(buket[i]);
    sort(buket[i].begin(), buket[i].end());
  }

  // int index = 0;
  // for (int i = 0; i < (k + 1); i++) {
  //   for (int j = 0; j < buket[i].size(); i++) {
  //     cout << buket[i][j] << " ";
  //     arr[index++] = buket[i][j];
  //   }
  //   cout << endl;
  // }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr) {
    cin >> i;
  }
  buketSort(arr);
  for (auto i : arr) {
    cout << i << " ";
  }
  return 0;
}
