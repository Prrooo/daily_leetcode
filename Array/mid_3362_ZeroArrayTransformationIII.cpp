#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<vector<int>> &queries, vector<int> temp,
           int &ans, int tempMin, int index, int n) {
  if (index >= n) {
    ans = max(ans, tempMin);
    return;
  }
  solve(nums, queries, temp, ans, tempMin, index + 1, n);
  for (int i = queries[index][0]; i <= queries[index][1]; i++) {
    if ((temp[i] - 1) >= nums[i]) {
      temp[i]--;
    } else {
      return;
    }
  }
  solve(nums, queries, temp, ans, tempMin + 1, index + 1, n);
}

int maxRemoval(vector<int> &nums, vector<vector<int>> &queries) {
  int n = nums.size(), ans = -1, tempMin = 0;
  vector<int> temp(n, 0);
  for (auto i : queries) {
    for (int j = i[0]; j <= i[1]; j++) {
      temp[j]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (temp[i] < nums[i])
      return -1;
  }
  solve(nums, queries, temp, ans, tempMin, 0, queries.size());
  return ans;
}

int main() { return 0; }
