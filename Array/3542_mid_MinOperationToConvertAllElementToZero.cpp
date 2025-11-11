#include <bits/stdc++.h>
using namespace std;

// this solution work but error TLE

class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    stack<pair<int, int>> st;
    int i = 0, count = 0;
    while (i < n) {
      if (nums[i] == 0) {
        i++;
        continue;
      }
      count++;
      int j = i, minEle = INT_MAX;
      while (j < n && nums[j] != 0) {
        st.push({nums[j], j});
        minEle = min(minEle, nums[j]);
        j++;
      }
      while (!st.empty()) {
        if (st.top().first == minEle) {
          nums[st.top().second] = 0;
        }
        st.pop();
      }
    }
    return count;
  }
};

int main() { return 0; }
