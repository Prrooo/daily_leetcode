#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int countPartitions(vector<int> &nums) {
    int n = nums.size();
    vector<int> preSum(n, 0);
    preSum[0] = nums[0];
    for (int i = 1; i < n; i++) {
      preSum[i] = preSum[i - 1] + nums[i];
    }

    int count = 0;

    for (int i = 0; i < n - 1; i++) {
      int leftSum = preSum[i];
      int rightSum = preSum[n - 1] - leftSum;
      if (abs(rightSum - leftSum) % 2 == 0)
        count++;
    }
    return count;
  }
};

int main() { return 0; }
