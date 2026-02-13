// You are given a string s consisting only of the characters 'a', 'b', and 'c'.
//
// A of s is called balanced if all distinct characters in the substring appear
// the same number of times.
//
// Return the length of the longest balanced substring of s.
//
//
//
// Example 1:
//
// Input: s = "abbac"
//
// Output: 4
//
// Explanation:
//
// The longest balanced substring is "abba" because both distinct characters 'a'
// and 'b' each appear exactly 2 times.
//
// Example 2:
//
// Input: s = "aabcc"
//
// Output: 3
//
// Explanation:
//
// The longest balanced substring is "abc" because all distinct characters 'a',
// 'b' and 'c' each appear exactly 1 time.
//
// Example 3:
//
// Input: s = "aba"
//
// Output: 2
//
// Explanation:
//
// One of the longest balanced substrings is "ab" because both distinct
// characters 'a' and 'b' each appear exactly 1 time. Another longest balanced
// substring is "ba".
//
//
//
// Constraints:
//
//     1 <= s.length <= 105
//     s contains only the characters 'a', 'b', and 'c'.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestBalanced(string s) {
    int n = s.size();
    int ans = 1, count = 1;
    // single longest consicutive char
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1]) {
        count++;
        ans = max(ans, count);
      } else {
        count = 1;
      }
    }

    // for two character
    vector<pair<char, char>> pt = {{'a', 'b'}, {'b', 'c'}, {'a', 'c'}};
    for (auto i : pt) {
      char a = i.first;
      char b = i.second;
      char other = 'a' + 'b' + 'c' - a - b;
      unordered_map<int, int> mp;
      count = 0;
      mp[0] = -1;
      for (int i = 0; i < n; i++) {
        if (s[i] == a)
          count++;
        else if (s[i] == b)
          count--;
        else {
          mp.clear();
          count = 0;
          mp[0] = i;
        }
        if (mp.find(count) != mp.end()) {
          ans = max(ans, i - mp[count]);
        } else {
          mp[count] = i;
        }
      }
    }

    // for three char
    map<vector<int>, int> tMp;
    tMp[{0, 0, 0}] = -1;
    vector<int> temp(3, 0);
    for (int i = 0; i < n; i++) {
      temp[s[i] - 'a']++;
      int mn = min({temp[0], temp[1], temp[2]});
      for (int i = 0; i < 3; i++) {
        temp[i] -= mn;
      }
      if (tMp.find(temp) != tMp.end()) {
        ans = max(ans, i - tMp[temp]);
      } else {
        tMp[temp] = i;
      }
    }
    return ans;
  }
};

int main() { return 0; }
