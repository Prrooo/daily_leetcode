#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    int n = costs.size();
    vector<int> diff;
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
      totalCost += costs[i][0];
      diff.push_back(costs[i][1] - costs[i][0]);
    }
    sort(diff.begin(), diff.end());
    for (int i = 0; i < n / 2; i++) {
      totalCost += diff[i];
    }
    return totalCost;
  }
};

int main() { return 0; }
