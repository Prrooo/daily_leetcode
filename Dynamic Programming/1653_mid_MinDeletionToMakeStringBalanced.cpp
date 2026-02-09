// You are given a string s consisting only of characters 'a' and
// 'b'​​​​.
//
// You can delete any number of characters in s to make s balanced. s is
// balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b'
// and s[j]= 'a'.
//
// Return the minimum number of deletions needed to make s balanced.
//
//
//
// Example 1:
//
// Input: s = "aababbab"
// Output: 2
// Explanation: You can either:
// Delete the characters at 0-indexed positions 2 and 6 ("aababbab" ->
// "aaabbb"), or Delete the characters at 0-indexed positions 3 and 6
// ("aababbab" -> "aabbbb").
//
// Example 2:
//
// Input: s = "bbaaaaabb"
// Output: 2
// Explanation: The only solution is to delete the first two characters

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumDeletions(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    int bCount = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'b') {
        bCount++;
        dp[i + 1] = dp[i];
      } else {
        dp[i + 1] = min(dp[i] + 1, bCount);
      }
    }
    return dp[n];
  }
};

int main() { return 0; }
