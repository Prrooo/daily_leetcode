#include <bits/stdc++.h>
using namespace std;

// easy to understand solution

class Solution {
public:
  int maximumGain(string s, int x, int y) {
    stack<char> st;
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
      if (!st.empty() && x >= y && s[i] == 'b' && st.top() == 'a') {
        st.pop();
        count = count + x;
      } else if (!st.empty() && y >= x && s[i] == 'a' && st.top() == 'b') {
        st.pop();
        count = count + y;
      } else {
        st.push(s[i]);
      }
    }
    string rem = "";
    while (!st.empty()) {
      rem += st.top();
      st.pop();
    }
    reverse(rem.begin(), rem.end());

    for (int i = 0; i < rem.length(); i++) {
      if (!st.empty() && x <= y && rem[i] == 'b' && st.top() == 'a') {
        st.pop();
        count = count + x;
      } else if (!st.empty() && y <= x && rem[i] == 'a' && st.top() == 'b') {
        st.pop();
        count = count + y;
      } else {
        st.push(rem[i]);
      }
    }

    return count;
  }
};

// work but TLE

int solve(string s, int x, int y, stack<char> st, int index, int n, int ans) {
  if (index >= n)
    return ans;

  char topEle;
  if (!st.empty()) {
    topEle = st.top();
  } else {
    topEle = 'x';
  }
  if (topEle == 'a' || topEle == 'b') {
    if (topEle == 'a' && s[index] == 'b') {
      if (x > y) {
        st.pop();
        return solve(s, x, y, st, index + 1, n, ans + x);
      } else {
        st.push(s[index]);
        int ans1 = solve(s, x, y, st, index + 1, n, ans);
        st.pop();
        st.pop();
        int ans2 = solve(s, x, y, st, index + 1, n, ans + x);
        return max(ans1, ans2);
      }
    } else if (topEle == 'b' && s[index] == 'a') {
      if (y > x) {
        st.pop();
        return solve(s, x, y, st, index + 1, n, ans + y);
      } else {
        st.push(s[index]);
        int ans1 = solve(s, x, y, st, index + 1, n, ans);
        st.pop();
        st.pop();
        int ans2 = solve(s, x, y, st, index + 1, n, ans + y);
        return max(ans1, ans2);
      }
    }
  }
  st.push(s[index]);
  return solve(s, x, y, st, index + 1, n, ans);
}

int maximumGain(string s, int x, int y) {
  stack<char> st;
  int n = s.size(), ans = 0;
  if (n == 0 || n == 1)
    return 0;
  st.push(s[0]);
  return solve(s, x, y, st, 1, n, ans);
}

int main() { return 0; }
