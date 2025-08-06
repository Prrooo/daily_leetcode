#include <bits/stdc++.h>
using namespace std;

int findLucky(vector<int> &arr) {
  unordered_map<int, int> count;
  int n = arr.size(), ans = -1;
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }
  for (auto i : count) {
    if (i.first == i.second && i.first > ans) {
      ans = i.first;
    }
  }
  return ans;
}

int main() { return 0; }
