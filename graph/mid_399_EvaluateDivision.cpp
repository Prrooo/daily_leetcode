// You are given an array of variable pairs equations and an array of real
// numbers values, where equations[i] = [Ai, Bi] and values[i] represent the
// equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a
// single variable.
//
// You are also given some queries, where queries[j] = [Cj, Dj] represents the
// jth query where you must find the answer for Cj / Dj = ?.
//
// Return the answers to all queries. If a single answer cannot be determined,
// return -1.0.
//
// Note: The input is always valid. You may assume that evaluating the queries
// will not result in division by zero and that there is no contradiction.
//
// Note: The variables that do not occur in the list of equations are undefined,
// so the answer cannot be determined for them.
//
//
//
// Example 1:
//
// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
// [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]] Output:
// [6.00000,0.50000,-1.00000,1.00000,-1.00000] Explanation: Given: a / b = 2.0,
// b / c = 3.0 queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x =
// ? return: [6.0, 0.5, -1.0, 1.0, -1.0 ] note: x is undefined => -1.0 Example
// 2:
//
// Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
// queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]] Output:
// [3.75000,0.40000,5.00000,0.20000] Example 3:
//
// Input: equations = [["a","b"]], values = [0.5], queries =
// [["a","b"],["b","a"],["a","c"],["x","y"]] Output:
// [0.50000,2.00000,-1.00000,-1.00000]

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  string name;
  vector<pair<Node *, double>> next;
  Node(string name) {
    this->name = name;
    next = vector<pair<Node *, double>>();
  }
};

void solve(string node, string &goal, unordered_map<string, Node *> st,
           unordered_set<string> &vis, double &ans, double temp) {
  if (st.find(node) == st.end() || vis.find(node) != vis.end())
    return;
  vis.insert(node);
  if (node == goal) {
    ans = temp;
    return;
  }
  for (auto i : st[node]->next) {
    solve(i.first->name, goal, st, vis, ans, temp * i.second);
  }
}

vector<double> calcEquation(vector<vector<string>> &equations,
                            vector<double> &values,
                            vector<vector<string>> &queries) {
  unordered_map<string, Node *> st;
  vector<double> output;
  int n = equations.size();
  for (int i = 0; i < n; i++) {
    if (st.find(equations[i][0]) == st.end()) {
      Node *temp1 = new Node(equations[i][0]);
      st[equations[i][0]] = temp1;
    }
    if (st.find(equations[i][1]) == st.end()) {
      Node *temp2 = new Node(equations[i][1]);
      st[equations[i][1]] = temp2;
    }
    st[equations[i][0]]->next.push_back({st[equations[i][1]], values[i]});
    st[equations[i][1]]->next.push_back({st[equations[i][0]], 1 / values[i]});
  }
  for (auto i : queries) {
    if (st.find(i[0]) == st.end() || st.find(i[1]) == st.end()) {
      output.push_back(-1.0);
    } else {
      unordered_set<string> vis;
      double ans = -1, temp = 1.0;
      solve(i[0], i[1], st, vis, ans, temp);
      output.push_back(ans);
    }
  }
  return output;
}

int main() { return 0; }
