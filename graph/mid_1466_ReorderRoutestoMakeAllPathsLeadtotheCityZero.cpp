#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>& conn,int no){
  if(conn[no][0]!=no) return false;
  else if(no==0 || conn[no][1]==0) return true; 
  return isValid(conn, conn[no][1]);
}

void solve(int no,vector<vector<int>>& conn,int n){
  for(int i=0;i<n;i++){
    if(conn[i][1]==no){
      conn[n][0]=n;
      conn[n][1]=i;
      return; 
    }
  }
}

int minReorder(int n, vector<vector<int>> &connections) {
  int count=0;
  for(int i=0;i<n;i++){
    if(!isValid(connections,i)){
      count++;
      solve(i,connections,n);
    }
  }
  return count; 
}

int main() { return 0; }
