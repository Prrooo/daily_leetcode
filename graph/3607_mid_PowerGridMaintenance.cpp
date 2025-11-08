#include <bits/stdc++.h>
using namespace std;

// lil bit better solution
// in this i store which element belong the which component and then maintain
// the ordered set of all the element belong to perticular component using
// compId and then with the help of compId i can get the smallest element of
// every component

class Solution {
public:
  void dfs(int no, unordered_map<int, set<int>> &compMp, vector<int> &compId,
           unordered_set<int> &vis, int &start, vector<vector<int>> &adj) {
    if (compId[no] != -1)
      return;
    compId[no] = start;
    compMp[start].insert(no);
    vis.insert(no);
    for (auto i : adj[no]) {
      if (vis.find(i) == vis.end()) {
        dfs(i, compMp, compId, vis, start, adj);
      }
    }
  }

  vector<int> processQueries(int c, vector<vector<int>> &connections,
                             vector<vector<int>> &queries) {
    vector<vector<int>> adj(c + 1);
    vector<bool> pw(c + 1, true);

    for (auto i : connections) {
      adj[i[0]].push_back(i[1]);
      adj[i[1]].push_back(i[0]);
    }

    unordered_map<int, set<int>> compMp;
    vector<int> compId(c + 1, -1);
    int start = 1;
    for (int i = 1; i <= c; i++) {
      unordered_set<int> vis;
      dfs(i, compMp, compId, vis, start, adj);
      start++;
    }

    vector<int> res;

    for (auto i : queries) {
      int first = i[0], second = i[1];
      if (first == 2) {
        pw[second] = false;
      } else {
        if (pw[second] == true) {
          res.push_back(second);
        } else {
          int id = compId[second];
          bool check = false;
          for (auto i : compMp[id]) {
            if (pw[i] == true) {
              res.push_back(i);
              check = true;
              break;
            } else {
              compMp[id].erase(i);
            }
          }
          if (!check)
            res.push_back(-1);
        }
      }
    }

    return res;
  }
};

// brute force solution time complexity O(n*m);
// error TLE

class Solution1 {
public:
  int solve(int no, unordered_map<int, vector<int>> &link, vector<bool> &pw) {
    int mn = INT_MAX;
    queue<int> qu;
    qu.push(no);
    unordered_set<int> vis;
    while (!qu.empty()) {
      int temp = qu.front();
      qu.pop();
      if (pw[temp]) {
        mn = min(mn, temp);
      }
      vis.insert(temp);
      for (auto i : link[temp]) {
        if (vis.find(i) == vis.end()) {
          qu.push(i);
        }
      }
    }
    return mn == INT_MAX ? -1 : mn;
  }

  vector<int> processQueries(int c, vector<vector<int>> &connections,
                             vector<vector<int>> &queries) {
    unordered_map<int, vector<int>> link;
    vector<bool> pw(c + 1, true);
    vector<int> ans;

    for (auto i : connections) {
      link[i[0]].push_back(i[1]);
      link[i[1]].push_back(i[0]);
    }

    for (auto i : queries) {
      if (i[0] == 2) {
        pw[i[1]] = false;
      } else {
        if (pw[i[1]] == true) {
          ans.push_back(i[1]);
        } else {
          ans.push_back(solve(i[1], link, pw));
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
