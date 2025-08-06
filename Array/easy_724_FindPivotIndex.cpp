// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
// 
// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
// 
// Return the leftmost pivot index. If no such index exists, return -1.
// 
//  
// 
// Example 1:
// 
// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11
// Example 2:
// 
// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.
// Example 3:
// 
// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0
//  


#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums) {
  int n = nums.size(), total = 0;
  vector<int> preSum;
  preSum.push_back(0);
  for (int i = 1; i < n; i++) {
    preSum.push_back(nums[i - 1] + preSum[i - 1]);
  }
  total = preSum[n - 1] + nums[n - 1];
  for (int i = 0; i < n; i++) {
    if ((total - nums[i] - preSum[i]) == preSum[i]) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << pivotIndex(arr);
  return 0;
}
