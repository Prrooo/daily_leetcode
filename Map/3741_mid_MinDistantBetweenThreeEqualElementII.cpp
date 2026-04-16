#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  int minimumDistance(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> count;
    vector<int> next(n, -1);
    for (int i = n - 1; i >= 0; i--) {
      if (count.find(nums[i]) != count.end()) {
        next[i] = count[nums[i]];
      }
      count[nums[i]] = i;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      int second = next[i];
      if (second != -1) {
        int third = next[second];
        if (third != -1) {
          ans =
              min(ans, abs(i - second) + abs(second - third) + abs(third - i));
        }
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

int main() { return 0; }
