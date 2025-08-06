#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums){
  int n=nums.size(),ans=INT_MIN,sum=0; 
  for(int i=0;i<n;i++){
    sum+=nums[i];
    if(sum>ans) ans=sum;
    if(sum<0) sum=0;
  }
  return ans;
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
  cout<<maxSubArray(arr);
  return 0;
}
