// There are n cities. Some of them are connected, while some are not. If city a
// is connected directly with city b, and city b is connected directly with city
// c, then city a is connected indirectly with city c.
//
// A province is a group of directly or indirectly connected cities and no other
// cities outside of the group.
//
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
// ith city and the jth city are directly connected, and isConnected[i][j] = 0
// otherwise.
//
// Return the total number of provinces.
//
// Example 1:
//
// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:
//
//
// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

void solve(vector<vector<int>> &isConnected, vector<int> &visit, int index,
           int n) {
  visit[index] = 1;
  for (int i = 0; i < n; i++) {
    if (visit[i] != 1 && isConnected[index][i] == 1) {
      solve(isConnected, visit, i, n);
    }
  }
}

int findCircleNum(vector<vector<int>> &isConnected) {
  int ans = 0, n = isConnected.size();
  vector<int> visit(n, 0);
  for (int i = 0; i < n; i++) {
    if (visit[i] == 0) {
      ans++;
      solve(isConnected, visit, i, n);
    }
  }
  return ans;
}

int main() { return 0; }
