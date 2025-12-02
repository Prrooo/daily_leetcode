#include <bits/stdc++.h>
using namespace std;

// most brute force solution
// better solution exists

class Solution {
public:
  vector<int> exclusiveTime(int n, vector<string> &logs) {
    vector<pair<int, int>> st;
    vector<int> ans(n, 0);
    for (int i = 0; i < logs.size(); i++) {
      int f = -1, s = -1, m = logs[i].size();
      for (int j = 0; j < m; j++) {
        if (logs[i][j] == ':') {
          if (f == -1)
            f = j;
          else {
            s = j;
            break;
          }
        }
      }
      int id = stoi(logs[i].substr(0, f));
      string status = logs[i].substr(f + 1, s - f - 1);
      int time = stoi(logs[i].substr(s + 1, m));
      if (status == "start") {
        int temp = st.size();
        if (!st.empty()) {
          int id1 = st[temp - 1].first;
          int time1 = st[temp - 1].second;
          ans[id1] = ans[id1] + time - time1;
        }
        st.push_back({id, time});
      } else {
        int temp = st.size();
        int id1 = st[temp - 1].first;
        int time1 = st[temp - 1].second;
        ans[id1] += time - time1 + 1;
        st.pop_back();
        temp--;
        if (!st.empty()) {
          st[temp - 1].second = time + 1;
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
