#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums,int target){
  int n=nums.size();
  vector<vector<int>> res;
  sort(nums.begin(),nums.end());
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int p=j+1,q=n-1;
      while(p<q){
        int temp=nums[i]+nums[j]+nums[p]+nums[q];
        if(temp==target){
          res.push_back({nums[i],nums[j],nums[p],nums[q]});
        }
        else if(temp>target){
          q--;
        }
        else p++;
      }
    }
  }
  return res;
}

int main(){
  int n,target;
  cin>>n>>target;
  vector<int> arr;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back(x);
  }
  vector<vector<int>> res=fourSum(arr,target);
  for(auto i : res){
    for(int j : i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}
