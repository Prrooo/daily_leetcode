#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumDistance(vector<int> &nums) {
    int n = nums.size(), ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      int a = i, b, c, count = 1;
      for (int j = i + 1; j < n; j++) {
        if (nums[j] == nums[i]) {
          if (count == 1)
            b = j;
          else
            c = j;
          count++;
        }
        if (count == 3) {
          ans = min(ans, abs(a - b) + abs(b - c) + abs(c - a));
          break;
        }
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

int main() { return 0; }
