#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>&  nums,int k){
  set<int> st;
  for(int i=0;i<nums.size();i++){
    if(nums[i]<k) return -1;
    else if(nums[i]>k) st.insert(nums[i]);
  }
  return st.size();
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
  cout<<minOperations(arr,k);
  return 0;
}
