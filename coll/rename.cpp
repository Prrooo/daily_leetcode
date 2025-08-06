#include<bits/stdc++.h>
#include <queue>
using namespace std;

int solve(queue<int> &q1,queue<int> &q2){
  int ans=0;
  while(!q1.empty() && !q2.empty()){
    if(q1.front()==q2.front()){
      q1.pop();
      q2.pop();
      ans++;
    }
    else{
      q1.push(q1.front());
      q1.pop();
      ans++;
    }
  }
  return ans;
}

int main(){
  int n;
  cin>>n;
  queue<int> q1;
  queue<int> q2;
  for (int i=0;i<n;i++ ) {
    int x;
    cin>>x;
    q1.push(x);
  }
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    q2.push(x);
  }
  cout<<solve(q1,q2);
  return 0;
}
