// You are given a 0-indexed array nums of size n consisting of non-negative
// integers.
//
// You need to apply n - 1 operations to this array where, in the ith operation
// (0-indexed), you will apply the following on the ith element of nums:
//
// If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to
// 0. Otherwise, you skip this operation. After performing all the operations,
// shift all the 0's to the end of the array.
//
// For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end,
// is [1,2,1,0,0,0]. Return the resulting array.
//
// Note that the operations are applied sequentially, not all at once.
//
//
//
// Example 1:
//
// Input: nums = [1,2,2,1,1,0]
// Output: [1,4,2,0,0,0]
// Explanation: We do the following operations:
// - i = 0: nums[0] and nums[1] are not equal, so we skip this operation.
// - i = 1: nums[1] and nums[2] are equal, we multiply nums[1] by 2 and change
// nums[2] to 0. The array becomes [1,4,0,1,1,0].
// - i = 2: nums[2] and nums[3] are not equal, so we skip this operation.
// - i = 3: nums[3] and nums[4] are equal, we multiply nums[3] by 2 and change
// nums[4] to 0. The array becomes [1,4,0,2,0,0].
// - i = 4: nums[4] and nums[5] are equal, we multiply nums[4] by 2 and change
// nums[5] to 0. The array becomes [1,4,0,2,0,0]. After that, we shift the 0's
// to the end, which gives the array [1,4,2,0,0,0]. Example 2:
//
// Input: nums = [0,1]
// Output: [1,0]
// Explanation: No operation can be applied, we just shift the 0 to the end.

#include <bits/stdc++.h>
using namespace std;

// my solution using swap method

// vector<int> applyOperations(vector<int> &arr){
//   int n=arr.size(),i=0;
//   while(i+1<n){
//     if(arr[i]==arr[i+1]){
//       arr[i]*=2;
//       arr[i+1]=0;
//     }
//     i++;
//   }
//   int j=n-1;
//   i=0;
//   while(i<j){
//     if(arr[i]==0){
//       int k=i;
//       while(k<j){
//         arr[k]=arr[k+1];
//         k++;
//       }
//       arr[j]=0;
//       j--;
//     }
//     else{
//       i++;
//     }
//   }
//   return arr;
// }

// little bit easy solution

vector<int> applyOperations(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      arr[i] *= 2;
      arr[i + 1] = 0;
    }
  }
  // we use two pointer approach
  // j is used to trace the positon of where we need to insert the non zero
  // value and i represent the current value in the arr
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) {
      arr[j] = arr[i];
      j++;
    }
  }
  // now for remaning space in the vector we store zero in the array
  while (j < n) {
    arr[j] = 0;
    j++;
  }
  return arr;
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
  vector<int> ans = applyOperations(arr);
  for (auto i : ans) {
    cout << i << " ";
  }
  return 0;
}
