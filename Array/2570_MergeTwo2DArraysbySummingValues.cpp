// You are given two 2D integer arrays nums1 and nums2.
//
// nums1[i] = [idi, vali] indicate that the number with the id idi has a value
// equal to vali. nums2[i] = [idi, vali] indicate that the number with the id
// idi has a value equal to vali. Each array contains unique ids and is sorted
// in ascending order by id.
//
// Merge the two arrays into one array that is sorted in ascending order by id,
// respecting the following conditions:
//
// Only ids that appear in at least one of the two arrays should be included in
// the resulting array. Each id should be included only once and its value
// should be the sum of the values of this id in the two arrays. If the id does
// not exist in one of the two arrays, then assume its value in that array to be
// 0. Return the resulting array. The returned array must be sorted in ascending
// order by id.
//
//
//
// Example 1:
//
// Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
// Output: [[1,6],[2,3],[3,2],[4,6]]
// Explanation: The resulting array contains the following:
// - id = 1, the value of this id is 2 + 4 = 6.
// - id = 2, the value of this id is 3.
// - id = 3, the value of this id is 2.
// - id = 4, the value of this id is 5 + 1 = 6.
// Example 2:
//
// Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
// Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
// Explanation: There are no common ids, so we just include each id with its
// value in the resulting list.

#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,vector<vector<int>> &nums2){
  int n1=nums1.size();
  int n2=nums2.size();
  int i=0,j=0;
  vector<vector<int>> result;
  while(i<n1 && j<n2){
    vector<int> temp;
    if(nums1[i][0]==nums2[j][0]){
      temp.push_back(nums1[i][0]);
      temp.push_back(nums1[i][1]+nums2[j][1]);
      i++,j++;
    }
    else if(nums1[i][0]<nums2[j][0]){
      temp.push_back(nums1[i][0]);
      temp.push_back(nums1[i][1]);
      i++;
    }
    else{
      temp.push_back(nums2[j][0]);
      temp.push_back(nums2[j][1]);
      j++;
    }
    result.push_back(temp);
  }
  while(i<n1){
    result.push_back(nums1[i]);
    i++;
  }
  while(j<n2){
    result.push_back(nums2[j]);
    j++;
  }
  return result;
}

int main() { 
  return 0;
}
