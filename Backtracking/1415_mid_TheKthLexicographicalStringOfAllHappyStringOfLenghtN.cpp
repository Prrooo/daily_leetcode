// A happy string is a string that:
//
//     consists only of letters of the set ['a', 'b', 'c'].
//     s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is
//     1-indexed).
//
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings
// and strings "aa", "baa" and "ababbc" are not happy strings.
//
// Given two integers n and k, consider a list of all happy strings of length n
// sorted in lexicographical order.
//
// Return the kth string of this list or return an empty string if there are
// less than k happy strings of length n.
//
//
//
// Example 1:
//
// Input: n = 1, k = 3
// Output: "c"
// Explanation: The list ["a", "b", "c"] contains all happy strings of length 1.
// The third string is "c".
//
// Example 2:
//
// Input: n = 1, k = 4
// Output: ""
// Explanation: There are only 3 happy strings of length 1.
//
// Example 3:
//
// Input: n = 3, k = 9
// Output: "cab"
// Explanation: There are 12 different happy string of length 3 ["aba", "abc",
// "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You
// will find the 9th string = "cab"

#include <bits/stdc++.h>
using namespace std;

// another solution
// work but little worse

class Solution1 {
public:
  vector<string> finalString;

  void solve(string currString, int n, int k) {
    if (currString.size() == n) {
      k--;
      finalString.push_back(currString);
      return;
    }
    for (char curr = 'a'; curr <= 'c'; curr++) {
      if (currString.size() > 0 && currString.back() == curr)
        continue;
      solve(currString + curr, n, k);
    }
  }

  string getHappyString(int n, int k) {
    solve("", n, k);
    if (finalString.size() < k)
      return "";
    return finalString[k - 1];
  }
};

// one solution

class Solution {
public:
  vector<int> tracker = {'a', 'b', 'c'};

  void lexicoShort(string &s, int start, int n) {
    for (int i = start; i < n; i++) {
      s[i] = s[i - 1] == 'c' || s[i - 1] == 'b' ? 'a' : 'b';
    }
  }

  string solve(string &s, int k, int n) {
    if (k <= 0)
      return s;
    int i = n - 1;
    while (i >= 1) {
      if (s[i] != 'c' && s[i - 1] != tracker[s[i] - 'a' + 1]) {
        s[i] = tracker[s[i] - 'a' + 1];
        lexicoShort(s, i + 1, n);
        return solve(s, k - 1, n);
      } else if ((s[i] - 'a' + 2) <= 2 && s[i - 1] != tracker[s[i] - 'a' + 2]) {
        s[i] = tracker[s[i] - 'a' + 2];
        lexicoShort(s, i + 1, n);
        return solve(s, k - 1, n);
      } else {
        i--;
      }
    }
    if (s[0] == 'c')
      return "";
    s[0] = tracker[s[0] - 'a' + 1];
    lexicoShort(s, 1, n);
    return solve(s, k - 1, n);
  }

  string getHappyString(int n, int k) {
    string perfect = "";
    char temp = 'a';
    for (int i = 0; i < n; i++) {
      perfect += temp;
      temp = temp == 'a' ? 'b' : 'a';
    }
    return solve(perfect, k - 1, n);
  }
};

int main() {
  Solution *temp = new Solution();
  temp->getHappyString(1, 1);
  return 0;
}
