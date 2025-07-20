// Given a pattern and a string s, find if s follows the same pattern.
//
// Here follow means a full match, such that there is a bijection between a
// letter in pattern and a non-empty word in s. Specifically:
//
//     Each letter in pattern maps to exactly one unique word in s.
//     Each unique word in s maps to exactly one letter in pattern.
//     No two letters map to the same word, and no two words map to the same
//     letter.
//
//
//
// Example 1:
//
// Input: pattern = "abba", s = "dog cat cat dog"
//
// Output: true
//
// Explanation:
//
// The bijection can be established as:
//
//     'a' maps to "dog".
//     'b' maps to "cat".
//
// Example 2:
//
// Input: pattern = "abba", s = "dog cat cat fish"
//
// Output: false
//
// Example 3:
//
// Input: pattern = "aaaa", s = "dog cat cat dog"
//
// Output: false
// a

#include <bits/stdc++.h>
using namespace std;

// best solution time complexity solution

bool wordPattern(string pattern, string s) {
  int n = pattern.size(), m = s.size();
  int i = 0, j = 0;
  unordered_map<char, string> mp;
  unordered_set<string> seenWord;
  while (i < n && j < m) {
    string temp = "";
    while (j < m && s[j] == ' ')
      j++;
    while (j < m && s[j] != ' ') {
      temp.push_back(s[j++]);
    }
    if (mp.find(pattern[i]) == mp.end()) {
      if (seenWord.find(temp) == seenWord.end()) {
        mp[pattern[i]] = temp;
        seenWord.insert(temp);
      } else
        return false;
    } else if (mp[pattern[i]] != temp)
      return false;
    i++;
  }
  if (i < n || j < m)
    return false;
  return true;
}

// not the best solution but work

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    int n = pattern.size(), m = s.size();
    int i = 0, j = 0;
    unordered_map<char, string> mp;
    while (i < n && j < m) {
      string temp = "";
      while (j < m && s[j] == ' ')
        j++;
      while (j < m && s[j] != ' ') {
        temp.push_back(s[j]);
        j++;
      }
      if (mp.find(pattern[i]) == mp.end()) {
        for (auto i : mp) {
          if (i.second == temp)
            return false;
        }
        mp[pattern[i]] = temp;
      } else if (mp[pattern[i]] != temp)
        return false;
      i++;
    }
    if (i < n || j < m)
      return false;
    return true;
  }
};

int main() { return 0; }
