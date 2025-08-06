// You are given a string s. It may contain any number of '*' characters. Your
// task is to remove all '*' characters.
//
// While there is a '*', do the following operation:
//
// Delete the leftmost '*' and the smallest non-'*' character to its left. If
// there are several smallest characters, you can delete any of them. Return the
// lexicographically smallest resulting string after removing all '*'
// characters.
//
// Example 1:
//
// Input: s = "aaba*"
//
// Output: "aab"
//
// Explanation:
//
// We should delete one of the 'a' characters with '*'. If we choose s[3], s
// becomes the lexicographically smallest.
//
// Example 2:
//
// Input: s = "abc"
//
// Output: "abc"
//
// Explanation:
//
// There is no '*' in the string.
//
//

#include <bits/stdc++.h>
using namespace std;

string clearStars(string s) {
  vector<int> charCount(26, 0);
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      for (int j = 0; j < 26; j++) {
        if (charCount[j] > 0) {
          for (int z = i - 1; z >= 0; z--) {
            if (s[z] == ('a' + j)) {
              s[z] = '*';
              break;
            }
          }
          charCount[j]--;
          break;
        }
      }
    } else {
      charCount[s[i] - 'a']++;
    }
  }
  string ans = "";
  for (int i = 0; i < n; i++) {
    if (s[i] != '*') {
      ans.push_back(s[i]);
    }
  }
  return ans;
}

int main() { return 0; }
