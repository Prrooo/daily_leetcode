// The frequency of an element is the number of times it occurs in an array.
//
// You are given an integer array nums and an integer k. In one operation, you
// can choose an index of nums and increment the element at that index by 1.
//
// Return the maximum possible frequency of an element after performing at most
// k operations.
//
//
//
// Example 1:
//
// Input: nums = [1,2,4], k = 5
// Output: 3
// Explanation: Increment the first element three times and the second element
// two times to make nums = [4,4,4]. 4 has a frequency of 3.
//
// Example 2:
//
// Input: nums = [1,4,8,13], k = 5
// Output: 2
// Explanation: There are multiple optimal solutions:
// - Increment the first element three times to make nums = [4,4,8,13]. 4 has a
// frequency of 2.
// - Increment the second element four times to make nums = [1,8,8,13]. 8 has a
// frequency of 2.
// - Increment the third element five times to make nums = [1,4,13,13]. 13 has a
// frequency of 2.
//
// Example 3:
//
// Input: nums = [3,9,6], k = 2
// Output: 1
//

#include <bits/stdc++.h>
using namespace std;

// best soluiton

int maxFrequency(vector<int> &nums, int k) {
  long left = 0, right = 0, total = 0, ans = 0, n = nums.size();
  sort(nums.begin(), nums.end());
  while (right < n) {
    total += nums[right];
    while ((right - left + 1) * nums[right] > total + k) {
      total -= nums[left++];
    }
    ans = max(ans, right - left + 1);
    right++;
  }
  return ans;
}

// my solution not the best

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    int n = nums.size(), ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = n - 1; i >= 0; i--) {
      int j = i, temp = 0;
      while (j >= 0 && k > 0) {
        if (nums[i] - nums[j] <= k) {
          k -= nums[i] - nums[j];
          temp++;
        } else
          break;
        j--;
      }
      ans = max(ans, temp);
    }
    return ans;
  }
};

int main() { return 0; }
