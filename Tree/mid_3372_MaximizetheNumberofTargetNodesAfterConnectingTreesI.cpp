// There exist two undirected trees with n and m nodes, with distinct labels in
// ranges [0, n - 1] and [0, m - 1], respectively.
//
// You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m
// - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge
// between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates
// that there is an edge between nodes ui and vi in the second tree. You are
// also given an integer k.
//
// Node u is target to node v if the number of edges on the path from u to v is
// less than or equal to k. Note that a node is always target to itself.
//
// Return an array of n integers answer, where answer[i] is the maximum possible
// number of nodes target to node i of the first tree if you have to connect one
// node from the first tree to another node in the second tree.
//
// Note that queries are independent from each other. That is, for every query
// you will remove the added edge before proceeding to the next query.
//
// Example 1:
//
// Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 =
// [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2
//
// Output: [9,7,9,8,8]
//
// Explanation:
//
// For i = 0, connect node 0 from the first tree to node 0 from the second tree.
// For i = 1, connect node 1 from the first tree to node 0 from the second tree.
// For i = 2, connect node 2 from the first tree to node 4 from the second tree.
// For i = 3, connect node 3 from the first tree to node 4 from the second tree.
// For i = 4, connect node 4 from the first tree to node 4 from the second tree.
//
// Example 2:
//
// Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k =
// 1
//
// Output: [6,3,3,3,3]
//
// Explanation:
//
// For every i, connect node i of the first tree with any node of the second
// tree.

#include <bits/stdc++.h>
using namespace std;

// my solution

class Solution {
public:
  void solve(unordered_map<int, vector<int>> &tree1, int node, int &ans, int k,
             int current, unordered_set<int> &visit) {
    visit.insert(node);
    if (current <= k)
      ans++;
    else
      return;
    for (int i = 0; i < tree1[node].size(); i++) {
      if (visit.find(tree1[node][i]) == visit.end()) {
        solve(tree1, tree1[node][i], ans, k, current + 1, visit);
      }
    }
  }

  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2, int k) {
    unordered_map<int, vector<int>> tree1, tree2;
    unordered_set<int> secondMax;
    int n = edges1.size(), m = edges2.size();
    for (int i = 0; i < max(n, m); i++) {
      if (i < n) {
        tree1[edges1[i][0]].push_back(edges1[i][1]);
        tree1[edges1[i][1]].push_back(edges1[i][0]);
      }
      if (i < m) {
        tree2[edges2[i][0]].push_back(edges2[i][1]);
        tree2[edges2[i][1]].push_back(edges2[i][0]);
      }
    }
    vector<int> res(tree1.size(), 0);
    int maxEdges = 0, secondAns = 0;
    unordered_set<int> visit;
    for (auto i : tree2) {
      secondAns = 0;
      visit.clear();
      solve(tree2, i.first, secondAns, k, 1, visit);
      maxEdges = max(maxEdges, secondAns);
    }
    for (auto i : tree1) {
      int ans = 0;
      visit.clear();
      solve(tree1, i.first, ans, k, 0, visit);
      res[i.first] = ans + maxEdges;
    }
    return res;
  }
};

int main() { return 0; }
