#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/?envType=daily-question&envId=2026-02-02

class Solution {
public:
  int minCost(int n, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> gp(n);
    for (auto i : edges) {
      gp[i[0]].emplace_back(i[1], i[2]);
      gp[i[1]].emplace_back(i[0], 2 * i[2]);
    }

    vector<int> vis(n, false);
    vector<int> dis(n, INT_MAX);

    dis[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, 0});
    while (!pq.empty()) {
      int x = pq.top().second;
      if (x == (n - 1))
        return dis[x];
      if (vis[x])
        continue;
      pq.pop();
      for (auto i : gp[x]) {
        int y = i.first;
        int z = i.second;
        if (dis[x] + z < dis[y]) {
          dis[y] = dis[x] + z;
          pq.push({dis[y], y});
        }
      }
    }
    return -1;
  }
};

int main() { return 0; }
