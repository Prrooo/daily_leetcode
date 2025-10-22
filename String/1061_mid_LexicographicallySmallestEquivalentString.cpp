#include <bits/stdc++.h>
using namespace std;

// brute force solution using dp
// work with the worst time complexity

class Solution1 {
public:
  char solve(unordered_map<char, vector<char>> &mp, char target) {
    queue<char> qu;
    qu.push(target);
    unordered_set<char> vis;
    char ans = target;
    while (!qu.empty()) {
      char top = qu.front();
      qu.pop();
      vis.insert(top);
      vector<char> temp = mp[top];
      for (int i = 0; i < temp.size(); i++) {
        if (vis.find(temp[i]) == vis.end()) {
          ans = min(ans, temp[i]);
          qu.push(temp[i]);
        }
      }
    }
    return ans;
  }

  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.size();
    unordered_map<char, vector<char>> mp;
    for (int i = 0; i < n; i++) {
      mp[s1[i]].push_back(s2[i]);
      mp[s2[i]].push_back(s1[i]);
    }

    vector<char> dp(26, '-1');

    for (int i = 0; i < 26; i++) {
      dp[i] = solve(mp, i + 'a');
    }

    for (int i = 0; i < baseStr.size(); i++) {
      if (dp[baseStr[i] - 'a'] != '-1') {
        baseStr[i] = dp[baseStr[i] - 'a'];
      }
    }
    return baseStr;
  }
};

// brute force solutino work but
// error TLE

class Solution {
public:
  char solve(unordered_map<char, vector<char>> &mp, char target) {
    queue<char> qu;
    qu.push(target);
    unordered_set<char> vis;
    char ans = target;
    while (!qu.empty()) {
      char top = qu.front();
      qu.pop();
      vis.insert(top);
      vector<char> temp = mp[top];
      for (int i = 0; i < temp.size(); i++) {
        if (vis.find(temp[i]) == vis.end()) {
          ans = min(ans, temp[i]);
          qu.push(temp[i]);
        }
      }
    }
    return ans;
  }

  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.size();
    unordered_map<char, vector<char>> mp;
    for (int i = 0; i < n; i++) {
      mp[s1[i]].push_back(s2[i]);
      mp[s2[i]].push_back(s1[i]);
    }
    for (int i = 0; i < baseStr.size(); i++) {
      baseStr[i] = solve(mp, baseStr[i]);
    }
    return baseStr;
  }
};

int main() { return 0; }
