// There is a malfunctioning keyboard where some letter keys do not work. All
// other keys on the keyboard work properly.
//
// Given a string text of words separated by a single space (no leading or
// trailing spaces) and a string brokenLetters of all distinct letter keys that
// are broken, return the number of words in text you can fully type using this
// keyboard.
//
//
//
// Example 1:
//
// Input: text = "hello world", brokenLetters = "ad"
// Output: 1
// Explanation: We cannot type "world" because the 'd' key is broken.
//
// Example 2:
//
// Input: text = "leet code", brokenLetters = "lt"
// Output: 1
// Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
//
// Example 3:
//
// Input: text = "leet code", brokenLetters = "e"
// Output: 0
// Explanation: We cannot type either word because the 'e' key is broken.
//
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    int ans = 0, i = 0, n = text.size();
    unordered_set<char> st;
    for (auto i : brokenLetters) {
      st.insert(i);
    }
    bool check = true;
    while (i < n) {
      check = true;
      while (i < n && text[i] != ' ') {
        if (st.find(text[i]) != st.end()) {
          check = false;
        }
        i++;
      }
      if (check)
        ans++;
      i++;
    }
    return ans;
  }
};

int main() { return 0; }
