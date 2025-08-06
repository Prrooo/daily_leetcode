// https://www.youtube.com/watch?v=vwZj1K0e9U8

// Given an integer array of size n, find all elements that appear more than ⌊
// n/3 ⌋ times.
//
//
//
// Example 1:
//
// Input: nums = [3,2,3]
// Output: [3]
// Example 2:
//
// Input: nums = [1]
// Output: [1]
// Example 3:
//
// Input: nums = [1,2]
// Output: [1,2]

#include <bits/stdc++.h>
using namespace std;

// best solution

bool valid(vector<int> &nums, int toCheck) {
  int count = 0, n = nums.size();
  for (int i = 0; i < n; i++) {
    if (nums[i] == toCheck) {
      count++;
    }
  }
  return count > n / 3 ? true : false;
}

vector<int> majorityElement(vector<int> &nums) {
  int first = INT_MIN, second = INT_MIN, fFre = 0, sFre = 0, n = nums.size();
  for (int i = 0; i < n; i++) {
    if (fFre == 0 && second != nums[i]) {
      fFre++;
      first = nums[i];
    } else if (sFre == 0 && first != nums[i]) {
      sFre++;
      second = nums[i];
    } else if (first == nums[i])
      fFre++;
    else if (second == nums[i])
      sFre++;
    else {
      fFre--, sFre--;
    }
  }
  vector<int> result;
  if (valid(nums, first))
    result.push_back(first);
  if (valid(nums, second))
    result.push_back(second);
  return result;
}

// good solution time complexity O(n) space complexity O(n)

// vector<int> majorityElement(vector<int>& nums){
//   unordered_map<int,int> mp;
//   vector<int> result;
//   int n=nums.size();
//   for(int i=0;i<n;i++){
//     mp[nums[i]]++;
//   }
//   for(auto i : mp){
//     if(i.second>n/3){
//       result.push_back(i.first);
//     }
//   }
//   return result;
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
  vector<int> result = majorityElement(arr);
  for (auto i : result) {
    cout << i << " ";
  }
  return 0;
}
