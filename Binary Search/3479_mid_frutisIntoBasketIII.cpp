#include <bits/stdc++.h>
using namespace std;

int isFind(vector<int> &baskets, int num, int n) {
  int left = 0, right = n - 1, index = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (baskets[mid] >= num) {
      index = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return index;
}

int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
  int ans = 0, n = fruits.size();
  sort(baskets.begin(), baskets.end());
  for (int i = 0; i < n; i++) {
    int index = isFind(baskets, fruits[i], n);
    if (index != -1) {
      baskets[index] = -1;
    } else {
      ans++;
    }
  }
  return ans;
}

int main() { return 0; }
