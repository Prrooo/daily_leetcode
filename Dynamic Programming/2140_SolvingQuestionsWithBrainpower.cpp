#include <bits/stdc++.h>
using namespace std;

// best solution 

long long mostPoints(vector<vector<int>> &questions){
  int n=questions.size();
  vector<long long> dp(n+1,0);
  for(int i=n-1;i>=0;i--){
    int ans=questions[i][0];
    int next=i+questions[i][1]+1;
    long long take=ans+(next>n?0:dp[next]);
    dp[i]=max(take,dp[i+1]);
  }
  return dp[0];
}

// my solution not optimal not recommended 

// long long solve(vector<vector<int>> &arr,int start,int n ){
//   long long temp=0;
//   int i=start;
//   while(i<n){
//     temp+=arr[i][0];
//     i+=arr[i][1];
//   }
//   return temp;
// }
// 
// long long mostPoints(vector<vector<int>> &questions){
//   long long ans=0; 
//   int n=questions.size();
//   for(int i=0;i<n;i++){
//     ans=max(ans,solve(questions,i,n));
//   }
//   return ans;
// }

int main(){
  int n;
  cin>>n;
  vector<vector<int>> arr;
  for(int i=0;i<n;i++){
    vector<int> temp;
    for(int i=0;i<2;i++){
      int x;
      cin>>x;
      temp.push_back(x);
    }
    arr.push_back(temp);
  }
  cout<<mostPoints(arr);
  return 0;
}
