#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& grid,int gd,int count){
}

vector<int> maxPoints(vector<vector<int>>& grid,vector<int> &que){
  vector<int> ans;
  int k=que.size(),count=0;
  for(int i=0;i<k;i++){
    count=0;
    solve(grid,que[i],count);
    ans.push_back(count);
  }
  return ans;
}

int main(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<vector<int>> arr;
  vector<int> que;
  for(int i=0;i<n;i++){
    vector<int> temp;
    for(int j=0;j<m;j++){
      int x;
      cin>>x;
      temp.push_back(x);
    }
    arr.push_back(temp);
  }
  for(int i=0;i<k;i++){
    int x;
    cin>>x;
    que.push_back(x);
  }
  vector<int> result=maxPoints(arr,que);
  for(auto i : result){
    cout<<i<<" ";
  }
  return 0;
}
