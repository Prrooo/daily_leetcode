// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
// 
// Example 1:
// 
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:
// 
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &nums){
  sort(nums.begin(),nums.end());
  int n=nums.size();
  vector<vector<int>> result;
  result.push_back({nums[0][0],nums[0][1]});
  for(int i=1;i<n;i++){
    int tempSize=result.size();
    if(result[tempSize-1][1]>=nums[i][0] && result[tempSize-1][1]<nums[i][1]){
      result[tempSize-1][1]=nums[i][1];
    }
    else if(result[tempSize-1][1]<nums[i][0]){
      result.push_back({nums[i][0],nums[i][1]});
    }
  }
  return result;
}

int main(){
  int n;
  cin>>n;
  vector<vector<int>> arr;
  for(int i=0;i<n;i++){
    vector<int> temp;
    for(int j=0;j<2;j++){
      int x;
      cin>>x;
      temp.push_back(x);
    }
    arr.push_back(temp); 
  }
  vector<vector<int>> result=merge(arr);
  for(auto i : result){
    for(auto j : i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}
