#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid){
  int n=grid.size();
  vector<int> count(n*n,0);
  vector<int> result(2,-1);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      count[grid[i][j]-1]++;
    }
  }

  for(int i=0;i<count.size();i++){
    if(count[i]==0){
      result[1]=i+1; 
    }
    if(count[i]==2){
      result[0]=i+1;
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
    for(int j=0;j<n;j++){
      int x;
      cin>>x;
      temp.push_back(x);
    }
    arr.push_back(temp);
  }
  vector<int> result=findMissingAndRepeatedValues(arr);
  cout<<result[0]<<" "<<result[1];
  return 0;
}
