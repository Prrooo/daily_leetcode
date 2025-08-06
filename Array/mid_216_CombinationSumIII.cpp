// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// 
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
// 
//  
// 
// Example 1:
// 
// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
// Example 2:
// 
// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.
// Example 3:
// 
// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
//  


#include <bits/stdc++.h>
using namespace std;

// my solution 

void solve(int k,int n,vector<int> res,vector<vector<int>>& mp,int index,int sum){
  if(res.size()==k && sum==n){
    mp.push_back(res);
    return;
  }
  if(index>=10) return;
  solve(k,n,res,mp,index+1,sum);
  if(sum+index<=n){
    sum+=index;
    res.push_back(index);
    solve(k,n,res,mp,index+1,sum);
  }
}

vector<vector<int>> combinationSum3(int k, int n) {
  vector<vector<int>> mp;
  solve(k,n,{},mp,1,0);
  return mp; 
}

int main() { return 0; }
