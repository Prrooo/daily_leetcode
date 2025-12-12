#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPossible(vector<int> &target) {
    priority_queue<int> qu;
    long long sum = 0;
    for (auto i : target) {
      qu.push(i);
      sum += i;
    }
    while (true) {
      int tp = qu.top();
      qu.pop();
      sum = sum - tp;
      if (tp == 1 || sum == 1)
        return true;
      if (sum > tp || sum == 0 || tp % sum == 0)
        return false;
      tp %= sum;
      sum += tp;
      qu.push(tp);
    }
    return true;
  }
};

int main() { return 0; }
