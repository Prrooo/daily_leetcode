// https://www.youtube.com/watch?v=32Ll35mhWg0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2
//
// Given an array of integers nums containing n + 1 integers where each integer
// is in the range [1, n] inclusive.
//
// There is only one repeated number in nums, return this repeated number.
//
// You must solve the problem without modifying the array nums and using only
// constant extra space.
//
// Example 1:
//
// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:
//
// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:
//
// Input: nums = [3,3,3,3,3]
// Output: 3

#include <bits/stdc++.h>
using namespace std;

// best solution time complexity O(n) space compl. O(1)

int findDuplicate(vector<int> &nums) {
  int fast = 0, slow = 0;
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (fast != slow);
  fast = 0;
  while (fast != slow) {
    fast = nums[fast];
    slow = nums[slow];
  }
  return slow;
}

// TLE, complexity O(n*n)
// int findDuplicate(vector<int> &nums){
//   int n=nums.size();
//   for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//       if(nums[i]==nums[j]) return nums[i];
//     }
//   }
//   return -1;
// }

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << findDuplicate(arr);
  return 0;
}
