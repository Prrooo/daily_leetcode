// 151. Reverse Words in a String
// Solved
// Medium
// Topics
// Companies
// Given an input string s, reverse the order of the words.
//
// A word is defined as a sequence of non-space characters. The words in s will
// be separated by at least one space.
//
// Return a string of the words in reverse order concatenated by a single space.
//
// Note that s may contain leading or trailing spaces or multiple spaces between
// two words. The returned string should only have a single space separating the
// words. Do not include any extra spaces.

// Example 1:
//
// Input: s = "the sky is blue"
// Output: "blue is sky the"

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
  int n = s.size();
  string result = "", temp = "";
  for (int i = 0; i < n; i++) {
    if (s[i] == ' ') {
      continue;
    }
    while (i < n && s[i] != ' ') {
      temp += s[i];
      i++;
    }
    if (result == "") {
      result = temp;
    } else {
      result = temp + ' ' + result;
    }
    temp = "";
  }
  return result;
}

int main() {
  string s;
  cin >> s;
  cout << reverseWords(s);
  return 0;
}
