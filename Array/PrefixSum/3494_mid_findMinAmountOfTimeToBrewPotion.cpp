// this work but i should revise this once more

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long minTime(vector<int> &skill, vector<int> &mana) {
    int n = skill.size(), m = mana.size();
    vector<long long> temp(n, 0);
    for (int i = 0; i < m; i++) {
      temp[0] += skill[0] * mana[i];
      for (int j = 1; j < n; j++) {
        temp[j] = max(temp[j], temp[j - 1]) + 1LL * skill[j] * mana[i];
      }

      for (int j = n - 1; j > 0; j--) {
        temp[j - 1] = temp[j] - 1LL * skill[j] * mana[i];
      }
    }
    return temp[n - 1];
  }
};

int main() { return 0; }
