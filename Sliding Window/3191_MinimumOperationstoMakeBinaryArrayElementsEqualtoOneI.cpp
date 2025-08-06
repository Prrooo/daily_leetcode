#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums){
  int n=nums.size();
  int i=2,count=0;
  while(i<n){
    if(nums[i-2]==0){
      nums[i-2]=!nums[i-2];
      nums[i-1]=!nums[i-1];
      nums[i]=!nums[i];
      count++;
    }
    i++;
  } 
  for(auto i : nums){
    if(i==0) return -1;
  }
  return count;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back(x);
  }
  cout<<minOperations(arr);
  return 0;
}
