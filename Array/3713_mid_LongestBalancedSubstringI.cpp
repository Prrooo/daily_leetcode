// You are given a string s consisting of lowercase English letters.
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
// Input: s = "zzabccy"
//
// Output: 4
//
// Explanation:
//
// The longest balanced substring is "zabc" because the distinct characters 'z',
// 'a', 'b', and 'c' each appear exactly 1 time.​​​​​​​
//
// Example 3:
//
// Input: s = "aba"
//
// Output: 2
//
// Explanation:
//
// ​​​​​​​One of the longest balanced substrings is "ab" because
// both distinct characters 'a' and 'b' each appear exactly 1 time. Another
// longest balanced substring is "ba".

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestBalanced(string s) {
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      vector<int> count(26, 0);
      for (int j = i; j < n; j++) {
        count[s[j] - 'a']++;
        int target = count[s[j] - 'a'];
        bool check = true;
        for (int z = 0; z < 26; z++) {
          if (count[z] != 0 && count[z] != target)
            check = false;
        }
        if (check)
          ans = max(ans, j - i + 1);
      }
    }
    return ans;
  }
};

int main() { return 0; }
