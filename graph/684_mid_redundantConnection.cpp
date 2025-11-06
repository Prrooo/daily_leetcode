#include <bits/stdc++.h>
using namespace std;

// brute force solution but works

class Solution {
public:
  bool dfs(int no, int parent, unordered_map<int, vector<int>> &mp,
           unordered_set<int> &vis) {
    vis.insert(no);
    for (auto i : mp[no]) {
      if (vis.find(i) != vis.end() && i != parent) {
        return true;
      } else if (vis.find(i) == vis.end()) {
        dfs(i, no, mp, vis);
      }
    }
    return false;
  }

  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    unordered_map<int, vector<int>> mp;
    for (auto i : edges) {
      mp[i[0]].push_back(i[1]);
      mp[i[1]].push_back(i[0]);
      unordered_set<int> vis;
      if (dfs(i[0], -1, mp, vis)) {
        return i;
      }
    }
    return {};
  }
};

int main() { return 0; }
