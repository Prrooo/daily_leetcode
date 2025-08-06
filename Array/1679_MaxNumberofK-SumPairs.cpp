#include<bits/stdc++.h>
using namespace std;

int maxOperations(vector<int>& nums,int k){
  int n=nums.size();
  sort(nums.begin(),nums.end());
  int i=0,j=n-1,count=0;
  while(i<j){
    if(nums[i]+nums[j]==k){
      count++;
      i++;
      j--;
    }
    else if(nums[i]+nums[j]>k){
      j--;
    }
    else{
      i++;
    }
  }
  return count;
}

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> arr;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back(x);
  }
  cout<<maxOperations(arr,k);
  return 0;
}
