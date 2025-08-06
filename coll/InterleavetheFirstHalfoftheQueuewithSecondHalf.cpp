// You are given a queue Q of N integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

// Note : Return the modified queue after the rearrangement as vector/ArrayList .

// Example 1:

// Input:
// N = 4
// Q = {2,4,3,1}
// Output:
// {2,3,4,1}
// Explanation:
// After the mentioned rearrangement of the first half
// and second half, our final queue will be {2,3,4,1}.

#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

vector<int> solve(queue<int> &q){
  queue<int> test;
  int n=q.size()/2;
  vector<int> result;
  while(n--){
    test.push(q.front());
    q.pop();
  }
  while(!(q.empty()) && !test.empty()){
    result.push_back(test.front());
    test.pop();

    result.push_back(q.front());
    q.pop();
  }
  return result;
}

int main(){
  int n;
  cin>>n;
  queue<int> q;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    q.push(x);
  }
  vector<int> result=solve(q);
  for (int i=0;i<result.size();i++) {
    cout<<result[i]<<" ";
  }
  return 0;
}
