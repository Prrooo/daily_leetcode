//  https://www.youtube.com/watch?v=wqAbIbFvlD8
//  video solution 
//  ----------------------------
//  view my solution for better understanding
//  -----------------------------------

// There are several consecutive houses along a street, each of which has some
// money inside. There is also a robber, who wants to steal money from the
// homes, but he refuses to steal from adjacent homes.
//
// The capability of the robber is the maximum amount of money he steals from
// one house of all the houses he robbed.
//
// You are given an integer array nums representing how much money is stashed in
// each house. More formally, the ith house from the left has nums[i] dollars.
//
// You are also given an integer k, representing the minimum number of houses
// the robber will steal from. It is always possible to steal at least k houses.
//
// Return the minimum capability of the robber out of all the possible ways to
// steal at least k houses.

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// best solution
// ---------------------------------------------------------------------------------
bool canStealKHouses(const vector<int> &nums, int k, int capability) {
  int count = 0;
  int i = 0;
  while (i < nums.size()) {
    if (nums[i] <= capability) {
      count++;
      i += 2;
    } else {
      i++;
    }
  }
  return count >= k;
}

// int minCapability(vector<int> &nums, int k) {
//   int left = *min_element(nums.begin(), nums.end());
//   int right = *max_element(nums.begin(), nums.end());
// 
//   while (left < right) {
//     int mid = left + (right - left) / 2;
//     if (canStealKHouses(nums, k, mid)) {
//       right = mid;
//     } else {
//       left = mid + 1;
//     }
//   }
// 
//   return left;
// }


// my solution ------------------------------------------------------------
// working fine best solution easy to understand  

int minCapability(vector<int>& nums,int k){
  int left=*min_element(nums.begin(),nums.end());
  int right=*max_element(nums.begin(),nums.end());
  int n=nums.size();
  while(left<right){
    int mid=(left+right)/2,steal=0;
    for(int i=0;i<n;){
      if(nums[i]<=mid){
        steal++;
        i+=2;
      } 
      else i++;
    }
    if(steal>=k) right=mid;
    else left=mid+1;
  }
  return right;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << minCapability(arr, k);
  return 0;
}
