#include <bits/stdc++.h>
using namespace std;

// first try

class Solution {
public:
  vector<string> buildArray(vector<int> &target, int n) {
    int m = target.size(), index = 0;
    vector<string> ans;
    stack<int> st;
    for (int i = 1; i <= n; i++) {
      if (index >= m)
        break;
      if (i != target[index]) {
        st.push(i);
        ans.push_back("Push");
      } else {
        int tt = (index - 1 < 0) ? 0 : target[index - 1];
        while (!st.empty() && st.top() != tt) {
          st.pop();
          ans.push_back("Pop");
        }
        st.push(i);
        ans.push_back("Push");
        index++;
      }
    }
    return ans;
  }
};

int main() { return 0; }
