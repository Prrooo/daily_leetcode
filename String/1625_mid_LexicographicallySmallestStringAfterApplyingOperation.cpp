#include <bits/stdc++.h>
#include <string>
using namespace std;

// best solution

class Solution1 {
public:
  string findLexSmallestString(string s, int a, int b) {
    int n = s.size();
    queue<string> qu;
    unordered_set<string> st;
    qu.push(s);
    string currMin = s;
    while (!qu.empty()) {
      string temp = qu.front();
      if (currMin > temp) {
        currMin = temp;
      }
      for (int i = 1; i < n; i += 2) {
        temp[i] = ((temp[i] - '0') + a) % 10 + '0';
      }
      if (st.find(temp) == st.end()) {
        qu.push(temp);
        st.insert(temp);
      }
      string rotated = qu.front().substr(n - b) + qu.front().substr(0, n - b);
      if (st.find(rotated) == st.end()) {
        qu.push(rotated);
        st.insert(rotated);
      }
      qu.pop();
    }
    return currMin;
  }
};

// work but not optimal

class Solution {
public:
  char solve(char s, int a) {
    int curr = s - '0';
    int sum = curr;
    for (int i = 0; i < 10; i++) {
      sum += a;
      curr = min(curr, sum % 10);
    }
    return curr + '0';
  }

  string rightShift(string s, int b, int shift, int n) {
    string st(n, '0');
    for (int i = 0; i < n; i++) {
      st[i] = s[(shift + i) % n];
    }
    return st;
  }

  string findLexSmallestString(string s, int a, int b) {
    int n = s.size();
    if (b % 2 == 0) {
      int i = 0, minVal = s[0], minIndex = 0;
      while (i < n) {
        if (i % 2 != 0) {
          s[i] = solve(s[i], a);
        } else if (i % b == 0) {
          if (minVal > (s[i] - '0')) {
            minVal = s[i] - '0';
            minIndex = i;
          }
        }
        i++;
      }
      return rightShift(s, b, minIndex, n);
    }
    int i = 0;
    while (i < n) {
      s[i] = solve(s[i], a);
      i++;
    }
    int minIndex = 0, minVal = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (minVal > s[i] - '0') {
        minVal = s[i] - '0';
        minIndex = i;
      } else if (minVal == s[i] - '0') {
        int j = minIndex, k = i;
        for (int z = 0; z < n; z++) {
          if ((s[j % n] - '0') > (s[k % n] - '0')) {
            minVal = s[i] - '0';
            minIndex = i;
          } else if ((s[j % n] - '0') < (s[k % n] - '0')) {
            break;
          }
          j++, k++;
        }
      }
    }
    return rightShift(s, b, minIndex, n);
  }
};

int main() { return 0; }
