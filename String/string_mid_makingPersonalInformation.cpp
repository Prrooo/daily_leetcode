#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  char small(char a) {
    if (a >= 65 && a <= 90)
      return a + 32;
    return a;
  }

  string maskPII(string s) {
    int n = s.size();
    char first = s[0];
    if ((s[0] >= 65 && s[0] <= 90) || (s[0] >= 97 && s[0] <= 122)) {
      bool check = false;
      string ans = "";
      ans += small(s[0]);
      ans += "*****";
      for (int i = 0; i < n; i++) {
        if (s[i] == '@') {
          check = true;
          ans += small(s[i - 1]);
        }
        if (check) {
          if (s[i] != '@' && s[i] != '.') {
            ans += small(s[i]);
          } else {
            ans += s[i];
          }
        }
      }
      return ans;
    } else {
      int count = 0;
      string ans = "", temp = "";
      for (int i = 0; i < n; i++) {
        if (s[i] != '+' && s[i] != '-' && s[i] != '(' && s[i] != ')' &&
            s[i] != ' ') {
          count++;
          temp += s[i];
        }
      }
      cout << count;
      if ((count - 10) != 0) {
        ans += '+';
        for (int i = 0; i < (count - 10); i++) {
          ans += '*';
        }
        ans += '-';
      }
      ans += "***-***-";
      for (int i = (count - 4); i < count; i++) {
        ans += temp[i];
      }
      return ans;
    }
    return "";
  }
};

int main() { return 0; }
