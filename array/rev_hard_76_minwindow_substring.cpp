// Given two strings s and t of lengths m and n respectively, return the minimum
// window
//
// of s such that every character in t (including duplicates) is included in the
// window. If there is no such substring, return the empty string "".
//
// The testcases will be generated such that the answer is unique.
//
//
//
// Example 1:
//
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
// from string t.
//
// Example 2:
//
// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
//
// Example 3:
//
// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
//

#include <bits/stdc++.h>
using namespace std;

// best solutoin

class Solution {
public:
  string minWindow(string s, string t) {
    if (s.length() < t.length()) {
      return "";
    }

    unordered_map<char, int> charCount;
    for (char ch : t) {
      charCount[ch]++;
    }

    int targetCharsRemaining = t.length();
    int minWindow[2] = {0, INT_MAX};
    int startIndex = 0;

    for (int endIndex = 0; endIndex < s.length(); endIndex++) {
      char ch = s[endIndex];
      if (charCount.find(ch) != charCount.end() && charCount[ch] > 0) {
        targetCharsRemaining--;
      }
      charCount[ch]--;

      if (targetCharsRemaining == 0) {
        while (true) {
          char charAtStart = s[startIndex];
          if (charCount.find(charAtStart) != charCount.end() &&
              charCount[charAtStart] == 0) {
            break;
          }
          charCount[charAtStart]++;
          startIndex++;
        }

        if (endIndex - startIndex < minWindow[1] - minWindow[0]) {
          minWindow[0] = startIndex;
          minWindow[1] = endIndex;
        }

        charCount[s[startIndex]]++;
        targetCharsRemaining++;
        startIndex++;
      }
    }

    return minWindow[1] >= s.length()
               ? ""
               : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
  }
};

// works but TL

// string solve(string s, unordered_map<char, int> mp, int n, int index) {
//   string ans = "";
//   ans.push_back(s[index]);
//   mp[s[index]]--;
//   int i = index + 1;
//   while (!mp.empty() && i < n) {
//     if (mp.find(s[i]) != mp.end() && mp[s[i]] > 0) {
//       mp[s[i]]--;
//       if (mp[s[i]] <= 0)
//         mp.erase(s[i]);
//     }
//     ans.push_back(s[i]);
//     i++;
//   }
//   if (mp.empty())
//     return ans;
//   return "";
// }
//
// string minWindow(string s, string t) {
//   int n = s.size(), m = t.size();
//   string ans = "";
//   int ansSize = INT_MAX;
//   unordered_map<char, int> mp;
//   for (int i = 0; i < m; i++) {
//     mp[t[i]]++;
//   }
//   for (int i = 0; i < n; i++) {
//     if (mp.find(s[i]) != mp.end()) {
//       string temp = solve(s, mp, n, i);
//       if (temp != "" && temp.size() < ansSize) {
//         ansSize = temp.size();
//         ans = temp;
//       }
//     }
//   }
//   return ans;
// }

int main() { return 0; }
