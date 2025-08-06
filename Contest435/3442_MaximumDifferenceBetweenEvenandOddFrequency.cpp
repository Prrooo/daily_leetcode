// You are given a string s consisting of lowercase English letters. Your task
// is to find the maximum difference between the frequency of two characters in
// the string such that:
//
// One of the characters has an even frequency in the string.
// The other character has an odd frequency in the string.
// Return the maximum difference, calculated as the frequency of the character
// with an odd frequency minus the frequency of the character with an even
// frequency.
//
//
//
// Example 1:
//
// Input: s = "aaaaabbc"
//
// Output: 3
//
// Explanation:
//
// The character 'a' has an odd frequency of 5, and 'b' has an even frequency
// of 2. The maximum difference is 5 - 2 = 3.

#include <bits/stdc++.h>
using namespace std;

int maxDifference(string s) {

  int count[26] = {0};
  int n = s.size(), oddMax = INT_MIN, evenMax = INT_MAX;
  for (int i = 0; i < n; i++) {
    count[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (count[i] == 0)
      continue;
    if (count[i] % 2 != 0) {
      oddMax = max(oddMax, count[i]);
    } else {
      evenMax = min(evenMax, count[i]);
    }
  }
  return oddMax - evenMax;
}

int main() {
  string s;
  cin >> s;
  cout << maxDifference(s);
  return 0;
}
