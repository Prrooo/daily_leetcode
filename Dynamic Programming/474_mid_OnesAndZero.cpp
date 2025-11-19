#include <bits/stdc++.h>
using namespace std;

// brute force solution
// error TLE

class Solution1 {
public:
  void solve(vector<pair<int, int>> &mp, int index, int count,
             pair<int, int> pt, pair<int, int> target, int n, int &ans) {
    if (index >= n) {
      ans = max(ans, count);
      return;
    }
    solve(mp, index + 1, count, pt, target, n, ans);
    if ((pt.first + mp[index].first) <= target.first &&
        (pt.second + mp[index].second) <= target.second) {
      pt.first += mp[index].first;
      pt.second += mp[index].second;
      solve(mp, index + 1, count + 1, pt, target, n, ans);
    }
  }

  int findMaxForm(vector<string> &strs, int zero, int one) {
    int n = strs.size();
    vector<pair<int, int>> count(n, {0, 0});
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < strs[i].size(); j++) {
        if (strs[i][j] == '1') {
          count[i].second++;
        } else {
          count[i].first++;
        }
      }
    }

    int ans = 0;

    solve(count, 0, 0, {0, 0}, {zero, one}, n, ans);

    return ans;
  }
};

int main() { return 0; }
