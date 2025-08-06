// solution
// https://leetcode.com/problems/pascals-triangle-ii/solutions/6280033/video-give-me-10-minutes-how-we-think-about-a-solution-python-javascript-java-c/

// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the
// Pascal's triangle.
//
// In Pascal's triangle, each number is the sum of the two numbers directly
// above it as shown:
//
// Example 1:
//
// Input: rowIndex = 3
// Output: [1,3,3,1]
// Example 2:
//
// Input: rowIndex = 0
// Output: [1]
// Example 3:
//
// Input: rowIndex = 1
// Output: [1,1]

#include <bits/stdc++.h>
using namespace std;

// best solution

vector<int> getRow(int rowIndex) {
  vector<int> res(1, 1);
  for (int i = 0; i < rowIndex; i++) {
    vector<int> newRow;
    newRow.push_back(1);
    for (int j = 1; j < res.size(); j++) {
      newRow.push_back(res[j - 1] + res[j]);
    }
    newRow.push_back(1);
    res = newRow;
  }
  return res;
}

// my solution take more space and time complexity
// -----------------------------------------

// vector<int> getRow(int rowIndex){
//   if(rowIndex==0) return {1};
//   vector<int> res={1};
//   for(int i=0;i<rowIndex;i++){
//     vector<int> first,second;
//     first.push_back(0);
//     for(int j=0;j<res.size();j++){
//       first.push_back(res[i]);
//       second.push_back(res[i]);
//     }
//     second.push_back(0);
//     res.clear();
//     for(int i=0;i<first.size();i++){
//       res.push_back(first[i]+second[i]);
//     }
//   }
//   return res;
// }

int main() {
  int n;
  cin >> n;
  vector<int> result = getRow(n);
  for (auto i : result) {
    cout << i << " ";
  }
  return 0;
}
