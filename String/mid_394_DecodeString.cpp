// Given an encoded string, return its decoded string.
//
// The encoding rule is: k[encoded_string], where the encoded_string inside the
// square brackets is being repeated exactly k times. Note that k is guaranteed
// to be a positive integer.
//
// You may assume that the input string is always valid; there are no extra
// white spaces, square brackets are well-formed, etc. Furthermore, you may
// assume that the original data does not contain any digits and that digits are
// only for those repeat numbers, k. For example, there will not be input like
// 3a or 2[4].
//
// The test cases are generated so that the length of the output will never
// exceed 105.
//
// Example 1:
//
// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Example 2:
//
// Input: s = "3[a2[c]]"
// Output: "accaccacc"
// Example 3:
//
// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"
//

#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
  string ans = "";
  int n = s.size();
  stack<char> st;
  for (int i = 0; i < n; i++) {
    if (s[i] >= 97 && s[i] <= 122) {
      ans += s[i];
    } else {
      int no = 0;
      string temp = "";
      while (s[i] != '[') {
        no = no * 10 + (s[i] - '0');
        i++;
      }
      i++;
      st.push('[');
      while (!st.empty() && i < n) {
        if (s[i] == '[') {
          st.push(s[i]);
        } else if (s[i] == ']') {
          st.pop();
        }
        if (!st.empty())
          temp += s[i++];
      }
      temp = decodeString(temp);
      for (int j = 0; j < no; j++) {
        ans += temp;
      }
    }
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << decodeString(s);
  return 0;
}
