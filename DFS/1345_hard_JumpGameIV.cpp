#include <bits/stdc++.h>
using namespace std;

// dfs
// error TLE because no knowledge for the target

// class Solution {
// public:
//     int solve(vector<int>& arr, vector<bool>& vis, int index, int step, int
//     n,
//               map<int, vector<int>>& mp) {
//         if (index >= n - 1)
//             return step;
//         if (index < 0 || index >= n)
//             return INT_MAX;
//         if (vis[index])
//             return INT_MAX;
//         vis[index] = true;
//         int first = solve(arr, vis, index + 1, step + 1, n, mp);
//         int second = solve(arr, vis, index - 1, step + 1, n, mp);
//         int third = INT_MAX;

//         for (auto i : mp[arr[index]]) {
//             if (i != index) {
//                 third = min(third, solve(arr, vis, i, step + 1, n, mp));
//             }
//         }
//         vis[index] = false;
//         return min({first, second, third});
//     }

//     int minJumps(vector<int>& arr) {
//         int n = arr.size();
//         vector<bool> vis(n, false);
//         map<int, vector<int>> mp;
//         for (int i = 0; i < n; i++) {
//             mp[arr[i]].push_back(i);
//         }
//         return solve(arr, vis, 0, 0, n, mp);
//     }
// };

// bfs best solution because using bfs we can find the min distance in less step

class Solution {
public:
  int minJumps(vector<int> &arr) {
    int n = arr.size();
    if (n == 1)
      return 0;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      mp[arr[i]].push_back(i);
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<int> vis(n, 0);
    vis[0] = 1;
    while (!q.empty()) {
      int node = q.front().first;
      int dist = q.front().second;
      q.pop();
      if (node == n - 1)
        return dist;
      if (node - 1 >= 0 && !vis[node - 1]) {
        vis[node - 1] = 1;
        q.push({node - 1, dist + 1});
      }
      if (node + 1 < n && !vis[node + 1]) {
        vis[node + 1] = 1;
        q.push({node + 1, dist + 1});
      }
      for (int next : mp[arr[node]]) {
        if (!vis[next]) {
          vis[next] = 1;
          q.push({next, dist + 1});
        }
      }
      mp[arr[node]].clear();
    }
    return -1;
  }
};

int main() { return 0; }
