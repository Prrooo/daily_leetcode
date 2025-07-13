// Given a string s consisting of words and spaces, return the length of the
// last word in the string.
//
// A word is a maximal
//
// consisting of non-space characters only.
//
//
//
// Example 1:
//
// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
//
// Example 2:
//
// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
//
// Example 3:
//
// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.

#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {
  int n = s.size();
  int i = n - 1, count = 0;
  while (i >= 0) {
    if (s[i] != ' ')
      break;
    i--;
  }
  while (i >= 0) {
    if (s[i] == ' ')
      break;
    count++;
    i--;
  }
  return count;
}

int min() { return 0; }
