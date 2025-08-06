// You are given a string s. We want to partition the string into as many parts
// as possible so that each letter appears in at most one part. For example, the
// string "ababcc" can be partitioned into ["abab", "cc"], but partitions such
// as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
//
// Note that the partition is done so that after concatenating all the parts in
// order, the resultant string should be s.
//
// Return a list of integers representing the size of these parts.
//
// Example 1:
//
// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
// splits s into less parts. Example 2:
//
// Input: s = "eccbbbbdec"
// Output: [10]

#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s) {
  unordered_map<int, pair<int, int>> mp;
  vector<int> res;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (mp.find(s[i]) != mp.end()) {
      mp[s[i]].second = i;
    } else {
      mp[s[i]].first = i;
      mp[s[i]].second = i;
    }
  }
  int upBond = mp[s[0]].second, lowBond = 0;
  for (int i = 0; i < n; i++) {
    if (i > upBond) {
      res.push_back(upBond - lowBond + 1);
      upBond = mp[s[i]].second;
      lowBond = i;
    }
    if (mp[s[i]].second > upBond) {
      upBond = mp[s[i]].second;
    }
  }
  res.push_back(upBond - lowBond + 1);
  // for (auto i : mp) {
  //   cout<<i.first<<":"<<i.second.first<<" "<<i.second.second<<endl;
  // }
  return res;
}

int main() {
  string s;
  cin >> s;
  vector<int> result = partitionLabels(s);
  for (auto i : result) {
    cout << i << " ";
  }
  return 0;
}
