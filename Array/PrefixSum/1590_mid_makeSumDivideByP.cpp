#include <bits/stdc++.h>
using namespace std;

// brute force solution
// error TLE

class Solution {
public:
  int minSubarray(vector<int> &nums, int p) {
    int n = nums.size();
    vector<long long> preSum(n);
    preSum[0] = nums[0];
    for (int i = 1; i < n; i++) {
      preSum[i] = nums[i] + preSum[i - 1];
    }
    long long sum = preSum[n - 1];
    int ans = INT_MAX;
    if (sum % p == 0)
      return 0;
    else if (p > sum)
      return -1;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int len = j - i + 1;
        long long rm = preSum[j] - preSum[i] + nums[i];
        if ((sum - rm) % p == 0 && sum != rm) {
          ans = min(ans, len);
          break;
        }
      }
    }
    if (ans == INT_MAX)
      return -1;
    return ans;
  }
};

int main() { return 0; }
