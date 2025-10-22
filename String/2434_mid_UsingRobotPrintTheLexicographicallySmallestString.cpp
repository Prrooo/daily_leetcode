//
// You are given a string s and a robot that currently holds an empty string t.
// Apply one of the following operations until s and t are both empty:
//
//     Remove the first character of a string s and give it to the robot. The
//     robot will append this character to the string t. Remove the last
//     character of a string t and give it to the robot. The robot will write
//     this character on paper.
//
// Return the lexicographically smallest string that can be written on the
// paper.
//
//
//
// Example 1:
//
// Input: s = "zza"
// Output: "azz"
// Explanation: Let p denote the written string.
// Initially p="", s="zza", t="".
// Perform first operation three times p="", s="", t="zza".
// Perform second operation three times p="azz", s="", t="".
//
// Example 2:
//
// Input: s = "bac"
// Output: "abc"
// Explanation: Let p denote the written string.
// Perform first operation twice p="", s="c", t="ba".
// Perform second operation twice p="ab", s="c", t="".
// Perform first operation p="ab", s="", t="c".
// Perform second operation p="abc", s="", t="".
//
// Example 3:
//
// Input: s = "bdda"
// Output: "addb"
// Explanation: Let p denote the written string.
// Initially p="", s="bdda", t="".
// Perform first operation four times p="", s="", t="bdda".
// Perform second operation four times p="addb", s="", t="".
//

#include <bits/stdc++.h>
using namespace std;

// best solution using the counting the frequence of the element in the string

class Solution {
public:
  char l(vector<int> &cnt) {
    for (int i = 0; i < 26; i++) {
      if (cnt[i] > 0)
        return i + 'a';
    }
    return 'a';
  }

  string robotWithString(string s) {
    int n = s.size();
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
      cnt[s[i] - 'a']++;
    }
    stack<char> st;
    string t = "";
    for (auto i : s) {
      st.push(i);
      cnt[i - 'a']--;
      while (!st.empty() && st.top() <= l(cnt)) {
        t += st.top();
        st.pop();
      }
    }
    while (!st.empty()) {
      t += st.top();
      st.pop();
    }
    return t;
  }
};

int main() { return 0; }
