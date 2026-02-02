// You are given two 0-indexed strings source and target, both of length n and
// consisting of lowercase English letters. You are also given two 0-indexed
// character arrays original and changed, and an integer array cost, where
// cost[i] represents the cost of changing the character original[i] to the
// character changed[i].
//
// You start with the string source. In one operation, you can pick a character
// x from the string and change it to the character y at a cost of z if there
// exists any index j such that cost[j] == z, original[j] == x, and changed[j]
// == y.
//
// Return the minimum cost to convert the string source to the string target
// using any number of operations. If it is impossible to convert source to
// target, return -1.
//
// Note that there may exist indices i, j such that original[j] == original[i]
// and changed[j] == changed[i].
//
//
//
// Example 1:
//
// Input: source = "abcd", target = "acbe", original =
// ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost =
// [2,5,5,1,2,20] Output: 28 Explanation: To convert the string "abcd" to string
// "acbe":
// - Change value at index 1 from 'b' to 'c' at a cost of 5.
// - Change value at index 2 from 'c' to 'e' at a cost of 1.
// - Change value at index 2 from 'e' to 'b' at a cost of 2.
// - Change value at index 3 from 'd' to 'e' at a cost of 20.
// The total cost incurred is 5 + 1 + 2 + 20 = 28.
// It can be shown that this is the minimum possible cost.
//
// Example 2:
//
// Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed =
// ["c","b"], cost = [1,2] Output: 12 Explanation: To change the character 'a'
// to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing
// the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To
// change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.
//
// Example 3:
//
// Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"],
// cost = [10000] Output: -1 Explanation: It is impossible to convert source to
// target because the value at index 3 cannot be changed from 'd' to 'e'.

#include <bits/stdc++.h>
using namespace std;

// best solution using dijkstra

class Solution {
public:
  vector<long long> dijkstra(int src, vector<vector<int>> &mp) {
    vector<long long> shrt(26, LLONG_MAX);
    set<pair<long long, int>> st;

    shrt[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
      auto [dis, curr] = *st.begin();
      st.erase(st.begin());

      for (int i = 0; i < 26; i++) {
        if (mp[curr][i] != INT_MAX && dis + mp[curr][i] < shrt[i]) {

          shrt[i] = dis + mp[curr][i];
          st.insert({shrt[i], i});
        }
      }
    }
    return shrt;
  }

  long long minimumCost(string source, string target, vector<char> &original,
                        vector<char> &changed, vector<int> &cost) {

    int n = original.size();
    vector<vector<int>> mp(26, vector<int>(26, INT_MAX));

    for (int i = 0; i < n; i++) {
      mp[original[i] - 'a'][changed[i] - 'a'] =
          min(mp[original[i] - 'a'][changed[i] - 'a'], cost[i]);
    }

    long long ans = 0;
    vector<vector<long long>> shortestPath(26);

    for (int i = 0; i < source.size(); i++) {
      int s = source[i] - 'a';
      int t = target[i] - 'a';

      if (shortestPath[s].empty()) {
        shortestPath[s] = dijkstra(s, mp);
      }

      if (shortestPath[s][t] == LLONG_MAX)
        return -1;

      ans += shortestPath[s][t];
    }
    return ans;
  }
};

// -----------------------------------------------

class Solution1 {
public:
  int solve(char org, char target, int sum, vector<vector<int>> &mp,
            vector<int> &vis, vector<int> &costs) {

    if (vis[org - 'a'] == 1)
      return -1;

    if (org == target)
      return sum;

    vis[org - 'a'] = 1;

    int temp = INT_MAX;

    for (int i = 0; i < 26; i++) {
      if (mp[org - 'a'][i] != -1) {
        int sumTemp =
            solve('a' + i, target, sum + mp[org - 'a'][i], mp, vis, costs);

        if (sumTemp != -1)
          temp = min(temp, sumTemp);
      }
    }

    vis[org - 'a'] = -1;

    return temp == INT_MAX ? -1 : temp;
  }

  long long minimumCost(string source, string target, vector<char> &original,
                        vector<char> &changed, vector<int> &cost) {

    vector<vector<int>> mp(26, vector<int>(26, -1));
    int n = original.size();

    for (int i = 0; i < n; i++) {
      int u = original[i] - 'a';
      int v = changed[i] - 'a';
      if (mp[u][v] == -1)
        mp[u][v] = cost[i];
      else
        mp[u][v] = min(mp[u][v], cost[i]);
    }

    long long costs = 0;

    for (int i = 0; i < source.size(); i++) {
      vector<int> vis(26, -1);
      int temp = solve(source[i], target[i], 0, mp, vis, cost);
      if (temp == -1)
        return -1;
      costs += temp;
    }

    return costs;
  }
};

int main() { return 0; }
