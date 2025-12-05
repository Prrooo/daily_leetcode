#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int timeRequiredToBuy(vector<int> &tickets, int k) {
    int n = tickets.size();
    queue<pair<int, int>> qu;
    for (int i = 0; i < n; i++) {
      qu.push({i, tickets[i]});
    }
    int time = 1;
    while (!qu.empty()) {
      qu.front().second--;
      if (qu.front().second == 0) {
        if (qu.front().first == k)
          break;
        qu.pop();
      } else {
        qu.push(qu.front());
        qu.pop();
      }
      time++;
    }
    return time;
  }
};

int main() { return 0; }
