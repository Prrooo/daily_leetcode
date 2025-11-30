// https://www.youtube.com/watch?v=mfyk9G29SPg&t=1036s

#include <bits/stdc++.h>
using namespace std;

// best solution

class Solution {
public:
  long long maxSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    long long ans = LLONG_MIN;
    vector<long long> minPrefix(k, LLONG_MAX / 2);
    minPrefix[k - 1] = 0;
    long long prefix = 0;
    for (int i = 0; i < n; i++) {
      prefix += nums[i];
      ans = max(ans, prefix - minPrefix[i % k]);
      minPrefix[i % k] = min(minPrefix[i % k], prefix);
    }
    return ans;
  }
};

// best brute force solution
// error TLE

class Solution1 {
public:
  long long maxSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    long long ans = LLONG_MIN;
    vector<long long> preSum(n);
    preSum[0] = nums[0];
    for (int i = 1; i < n; i++) {
      preSum[i] = nums[i] + preSum[i - 1];
    }
    for (int i = 0; i < n - k + 1; i++) {
      int j = i + k - 1;
      while (j < n) {
        int len = (j - i) + 1;
        if (len % k == 0) {
          ans = max(ans, preSum[j] - preSum[i] + nums[i]);
          j = j + k;
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
