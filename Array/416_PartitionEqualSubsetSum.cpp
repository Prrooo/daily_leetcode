#include<bits/stdc++.h>
using namespace std;

// best solution 

// good solution by have TLE

void solve(vector<int> &arr,int sum,int tempSum,int index,int n,bool &check){
  if(index==n){
    if(tempSum*2==sum){
      check=true;
    } 
    return;
  } 
  solve(arr,sum,tempSum,index+1,n,check);
  tempSum+=arr[index];
  solve(arr,sum,tempSum,index+1,n,check);
}

bool canPartition(vector<int> &arr){
  int sum=0,n=arr.size();
  for(int i=0;i<n;i++){
    sum+=arr[i];
  }
  bool check=false;
  solve(arr,sum,0,0,n,check);
  return check;
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
  cout<<canPartition(arr);
  return 0;
}
