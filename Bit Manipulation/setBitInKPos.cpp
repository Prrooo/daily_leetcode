#include<bits/stdc++.h>
using namespace std;

void solve(int &n,int k){
  n=n|(1<<k);
}

int main(){
  int n,k;
  cin>>n>>k;
  solve(n,k);
  cout<<k;
  return 0;
}
