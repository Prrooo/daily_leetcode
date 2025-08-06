// You are given two strings word1 and word2. Merge the strings by adding
// letters in alternating order, starting with word1. If a string is longer than
// the other, append the additional letters onto the end of the merged string.

// Return the merged string.
//
// Example 1:

// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"
// Explanation: The merged string will be merged as so:
// word1:  a   b   c
// word2:    p   q   r
// merged: a p b q c r

#include <bits/stdc++.h>
using namespace std;

string myWay(string word1, string word2) {
  int i = 0, j = 0;
  int n1 = word1.size(), n2 = word2.size();
  string ans = "";
  while (i < n1 && j < n2) {
    ans += word1[i];
    ans += word2[j];
    i++, j++;
  }
  while (i < n1) {
    ans += word1[i];
    i++;
  }
  while (j < n2) {
    ans += word2[j];
    j++;
  }
  return ans;
}

// simple way to do that
string mergeAlternately(string word1, string word2) {
  int i = 0;
  int n1 = word1.size(), n2 = word2.size();
  string result = "";
  while (i < n1 || i < n2) {
    if (i < n1) {
      result += word1[i];
    }
    if (i < n2) {
      result += word2[i];
    }
    i++;
  }
  return result;
}

int main() {
  string word1, word2;
  cin >> word1 >> word2;
  cout << mergeAlternately(word1, word2);
  return 0;
}
