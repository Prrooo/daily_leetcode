#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool divideArray(vector<int> &nums){
  unordered_map<int,int> mp;
  int n=nums.size();
  for(int i=0;i<n;i++){
    mp[nums[i]]++;
  }
  for(int i=0;i<mp.size();i++){
    if(mp[i]%2!=0){
      return false;
    }
  } 
  return true;
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
  cout<<divideArray(arr);
}

