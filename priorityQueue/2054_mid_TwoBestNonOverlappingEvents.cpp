// You are given a 0-indexed 2D integer array of events where events[i] =
// [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends
// at endTimei, and if you attend this event, you will receive a value of
// valuei. You can choose at most two non-overlapping events to attend such that
// the sum of their values is maximized.
//
// Return this maximum sum.
//
// Note that the start time and end time is inclusive: that is, you cannot
// attend two events where one of them starts and the other ends at the same
// time. More specifically, if you attend an event with end time t, the next
// event must start at or after t + 1.
//
//
//
// -------------------------------------------------------------
//
// IMP QUESTIOn
//
// ---------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &events) {
    int n = events.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        qu;
    sort(events.begin(), events.end());
    int ans = 0, maxVal = 0;
    for (auto i : events) {
      while (!qu.empty() && qu.top().first < i[0]) {
        maxVal = max(maxVal, qu.top().second);
        qu.pop();
      }
      ans = max(ans, maxVal + i[2]);
      qu.push({i[1], i[2]});
    }
    return ans;
  }
};

int main() { return 0; }
