#include <bits/stdc++.h>
#include <queue>
using namespace std;

// another solution using priority queue

int findKthLargest(vector<int>& nums,int k){
  priority_queue<int> qu;
  int n=nums.size();
  for(int i=0;i<n;i++){
    qu.push(nums[i]);
  }
  while(!qu.empty() && k>0){
    if(k-1==0) return qu.top();
    k--;
    qu.pop();
  }
  return -1; 
}

// one solution 

/*int findKthLargest(vector<int> &nums, int k) {*/
/*  sort(nums.begin(),nums.end());*/
/*  int n=nums.size();*/
/*  return nums[n-k];*/
/*}*/

int main() { 
  int n,k;
  cin>>n>>k;
  vector<int> arr;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back(x);
  }
  findKthLargest(arr, k);
}
