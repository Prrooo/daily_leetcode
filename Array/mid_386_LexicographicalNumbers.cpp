// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
// 
// You must write an algorithm that runs in O(n) time and uses O(1) extra space. 
// 
//  
// 
// Example 1:
// 
// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
// Example 2:
// 
// Input: n = 2
// Output: [1,2]
//  


#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &ans, int start, int n) {
  if (start > n)
    return;
  ans.push_back(start);
  for (int i = 0; i <= 9; i++) {
    int temp = start * 10 + i;
    if (temp <= n) {
      solve(ans, temp, n);
    }
    else{
      break;
    }
  }
}

vector<int> lexicalOrder(int n) {
  vector<int> ans;
  for (int i = 1; i <= 9; i++) {
    solve(ans, i, n);
  }
  return ans;
}

int main() { return 0; }
