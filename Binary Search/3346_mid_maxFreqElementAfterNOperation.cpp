#include <bits/stdc++.h>
using namespace std;

// best brute force solution

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k, int numOperations) {
    int n = nums.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      int temp = 1, tempMax = 1, tempMin = 1;
      int minVal = nums[i] - k, maxVal = nums[i] + k;
      int numOp = numOperations, minOp = numOperations - 1,
          maxOp = numOperations - 1;
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        if (nums[i] == nums[j]) {
          temp++;
        } else if (abs(nums[i] - nums[j]) <= k && numOp > 0) {
          temp++;
          numOp--;
        }

        if (numOperations > 1) {
          if (minVal == nums[j])
            tempMin++;
          else if (abs(minVal - nums[j]) <= k && minOp > 0) {
            tempMin++;
            minOp--;
          }

          if (maxVal == nums[j])
            tempMax++;
          else if (abs(maxVal - nums[j]) <= k && maxOp > 0) {
            tempMax++;
            maxOp--;
          }
        }
      }
      ans = max(ans, max(temp, max(tempMax, tempMin)));
    }
    return ans;
  }
};

int main() { return 0; }
