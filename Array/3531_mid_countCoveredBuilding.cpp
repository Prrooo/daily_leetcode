#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countCoveredBuildings(int n, vector<vector<int>> &bd) {
    vector<pair<int, int>> x(n + 1, pair<int, int>({INT_MAX, INT_MIN}));
    vector<pair<int, int>> y(n + 1, pair<int, int>({INT_MAX, INT_MIN}));
    int sz = bd.size();

    for (int i = 0; i < sz; i++) {
      int xTemp = bd[i][0], yTemp = bd[i][1];
      x[yTemp].first = min(x[yTemp].first, xTemp);
      x[yTemp].second = max(x[yTemp].second, xTemp);
      y[xTemp].first = min(y[xTemp].first, yTemp);
      y[xTemp].second = max(y[xTemp].second, yTemp);
    }
    int ans = 0;
    for (int i = 0; i < sz; i++) {
      int xTemp = bd[i][0], yTemp = bd[i][1];
      if (xTemp > x[yTemp].first && xTemp < x[yTemp].second &&
          yTemp > y[xTemp].first && yTemp < y[xTemp].second) {
        ans++;
      }
    }
    return ans;
  }
};

int main() { return 0; }
