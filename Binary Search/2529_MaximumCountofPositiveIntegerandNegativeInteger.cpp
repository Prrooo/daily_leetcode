#include <bits/stdc++.h>
using namespace std;

// brute force approach time complexity O(n) space complexity O(1)

// int maximumCount(vector<int> &nums){
//   int posCount=0,negCount=0;
//   for(int i=0;i<nums.size();i++){
//     if(nums[i]<0) negCount++;
//     else if(nums[i]>0) posCount++;
//   }
//   return max(posCount,negCount);
// }

// ----------------------------------------------------------------------------------------------
// best solution below time complexity O(logN)
// using binary search 

int maximumCount(vector<int> &nums) {
  int n = nums.size();
  int l = 0, r = n - 1;
  while (l <= r) {
    int mid = (r + l) / 2;
    if (nums[mid] < 0) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  int pos = l;
  while (pos < n) {
    if (nums[pos] == 0) {
      pos++;
    } else {
      break;
    }
  }
  return max(l, n - pos);
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
  cout << maximumCount(arr);
  return 0;
}
