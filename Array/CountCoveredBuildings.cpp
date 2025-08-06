// You are given a positive integer n, representing an n x n city. You are also
// given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique
// building located at coordinates [x, y].
//
// A building is covered if there is at least one building in all four
// directions: left, right, above, and below.
//
// Return the number of covered buildings.
//
// Example 1:
//
// Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
//
// Output: 1
//
// Explanation:
//
// Only building [2,2] is covered as it has at least one building:
// above ([1,2])
// below ([3,2])
// left ([2,1])
// right ([2,3])
// Thus, the count of covered buildings is 1.
// Example 2:
//
// Input: n = 3, buildings = [[1,1],[1,2],[2,1],[2,2]]
//
// Output: 0
//
// Explanation:
//
// No building has at least one building in all four directions.
// Example 3:
//
// Input: n = 5, buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]]
//
// Output: 1
//
// Explanation:
//
// Only building [3,3] is covered as it has at least one building:
// above ([1,3])
// below ([5,3])
// left ([3,2])
// right ([3,5])
// Thus, the count of covered buildings is 1.
//

#include <bits/stdc++.h>
using namespace std;

int countCoveredBuildings(int n, vector<vector<int>> &bd) {
  vector<pair<int, int>> x(n + 1, {INT_MAX, INT_MIN});
  vector<pair<int, int>> y(n + 1, {INT_MAX, INT_MIN});
  int ans = 0;
  int sz = bd.size();
  for (int i = 0; i < sz; i++) {
    int xTemp = bd[i][0];
    int yTemp = bd[i][1];
    x[yTemp].first = min(x[yTemp].first, xTemp);
    x[yTemp].second = max(x[yTemp].second, xTemp);
    y[xTemp].first = min(y[xTemp].first, yTemp);
    y[xTemp].second = max(y[xTemp].second, yTemp);
  }
  for (int i = 0; i < sz; i++) {
    int xTemp = bd[i][0], yTemp = bd[i][1];
    if (xTemp > x[yTemp].first && xTemp < x[yTemp].second &&
        yTemp > y[xTemp].first && yTemp < y[xTemp].second) {
      ans++;
    }
  }
  return ans;
}

int main() { return 0; }
