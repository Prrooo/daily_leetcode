#include<bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>>& arr){
  map<vector<int>,int> row;
  int n=arr.size(),ans=0;
  for(int i=0;i<n;i++){
    vector<int> temp;
    for(int j=0;j<n;j++){
      temp.push_back(arr[i][j]);
    }
    row[temp]++;
  }
  for(int i=0;i<n;i++){
    vector<int> temp;
    for(int j=0;j<n;j++){
      temp.push_back(arr[j][i]);
    }
    ans+=row[temp];
  }
  return ans;
}

int main(){
  int n;
  vector<vector<int>> arr;
  for(int i=0;i<n;i++){
    vector<int> temp;
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      temp.push_back(x);
    }
    arr.push_back(temp);
  }
  cout<<equalPairs(arr);
  return 0;
}
