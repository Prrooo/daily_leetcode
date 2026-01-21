#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long largestSquareArea(vector<vector<int>> &bL,
                              vector<vector<int>> &tR) {
    int n = bL.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        int w = min(tR[i][0], tR[j][0]) - max(bL[i][0], bL[j][0]);
        int h = min(tR[i][1], tR[j][1]) - max(bL[i][1], bL[j][1]);
        ans = max(ans, min(w, h));
      }
    }
    return 1LL * ans * ans;
  }
};

int main() { return 0; }
