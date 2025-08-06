#include<bits/stdc++.h>
using namespace std;

long long maximumTripletValue(vector<int> &nums){
  int n=nums.size();
  long long ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int z=j+1;z<n;z++){
        // ans=max(ans,(nums[i] - nums[j]) * nums[z]);
        long long a= nums[i] - nums[j] ;
        long long b= nums[z]; 
        if(a*b>ans) ans=a*b;
      }
    }
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
  cout<<maximumTripletValue(arr);
  return 0;
}
