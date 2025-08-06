// You are given a positive integer days representing the total number of days
// an employee is available for work (starting from day 1). You are also given a
// 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents
// the starting and ending days of meeting i (inclusive).
//
// Return the count of days when the employee is available for work but no
// meetings are scheduled.
//
// Note: The meetings may overlap.
//
// Example 1:
//
// Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
//
// Output: 2
//
// Explanation:
//
// There is no meeting scheduled on the 4th and 8th days.
//
// Example 2:
//
// Input: days = 5, meetings = [[2,4],[1,3]]
//
// Output: 1
//
// Explanation:
//
// There is no meeting scheduled on the 5th day.
//
// Example 3:
//
// Input: days = 6, meetings = [[1,6]]
//
// Output: 0
//
// Explanation:
//
// Meetings are scheduled for all working days.

#include <bits/stdc++.h>
#include <map>
using namespace std;

int countDays(int days, vector<vector<int>> &meetings) {
  map<int, int> mp;
  int n = meetings.size(), count = 0, tempMax = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (mp.find(meetings[i][0]) != mp.end() &&
        meetings[i][1] < mp[meetings[i][0]]) {
      continue;
    } else {
      mp[meetings[i][0]] = meetings[i][1];
    }
    tempMax = max(tempMax, meetings[i][1]);
  }
  int m = mp.size();
  int temp = -1;
  for (auto i : mp) {
    if (temp == -1)
      temp = i.second;
    else if (temp < i.first) {
      count += i.first - temp - 1;
      temp = i.second;
    } else if (temp < i.second) {
      temp = i.second;
    }
  }
  if (mp.begin()->first != 1 && mp.begin()->first > 1) {
    count += mp.begin()->first - 1;
  }
  if (tempMax != days && tempMax < days) {
    count += days - tempMax;
  }
  return count;
}

int main() {
  int n, days;
  cin >> n >> days;
  vector<vector<int>> arr;
  for (int i = 0; i < n; i++) {
    vector<int> temp;
    for (int i = 0; i < 2; i++) {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    arr.push_back(temp);
  }
  cout << countDays(days, arr);
  return 0;
}
