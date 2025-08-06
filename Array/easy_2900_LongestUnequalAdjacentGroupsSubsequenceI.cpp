// You are given a string array words and a binary array groups both of length
// n.
//
// A subsequence of words is alternating if for any two consecutive strings in
// the sequence, their corresponding elements at the same indices in groups are
// different (that is, there cannot be consecutive 0 or 1).
//
// Your task is to select the longest alternating subsequence from words.
//
// Return the selected subsequence. If there are multiple answers, return any of
// them.
//
// Note: The elements in words are distinct.
//
// Example 1:
//
// Input: words = ["e","a","b"], groups = [0,0,1]
//
// Output: ["e","b"]
//
// Explanation: A subsequence that can be selected is ["e","b"] because
// groups[0] != groups[2]. Another subsequence that can be selected is ["a","b"]
// because groups[1] != groups[2]. It can be demonstrated that the length of the
// longest subsequence of indices that satisfies the condition is 2.
//
// Example 2:
//
// Input: words = ["a","b","c","d"], groups = [1,0,1,1]
//
// Output: ["a","b","c"]
//
// Explanation: A subsequence that can be selected is ["a","b","c"] because
// groups[0] != groups[1] and groups[1] != groups[2]. Another subsequence that
// can be selected is ["a","b","d"] because groups[0] != groups[1] and groups[1]
// != groups[3]. It can be shown that the length of the longest subsequence of
// indices that satisfies the condition is 3.
//
//

#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &words, vector<int> &group, vector<string> &first,
           int index, int n) {
  int check = group[index];
  for (int i = index; i < n; i++) {
    if (group[i] == check) {
      first.push_back(words[i]);
      check == 1 ? check = 0 : check = 1;
    }
  }
}

vector<string> getLongestSubsequence(vector<string> &words,
                                     vector<int> &groups) {
  vector<string> first, second;
  int n = words.size();
  solve(words, groups, first, 0, n);
  for (int i = 1; i < n; i++) {
    if (groups[i] != groups[0]) {
      cout << i << endl;
      solve(words, groups, second, i, n);
      break;
    }
  }
  return first.size() > second.size() ? first : second;
}

int main() { return 0; }
