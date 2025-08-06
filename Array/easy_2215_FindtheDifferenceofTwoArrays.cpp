#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
  unordered_set<int> first;
  unordered_set<int> second;
  vector<vector<int>> ans;
  vector<int> temp; 
  int n=nums1.size(),m=nums2.size();
  for(int i=0;i<n;i++){
    first.insert(nums1[i]);
  }
  for(int i=0;i<m;i++){
    second.insert(nums2[i]);
  }
  for(auto i : first){
    if(second.find(i)==second.end()){
      temp.push_back(i);
    }
  }
  ans.push_back(temp);
  temp.clear();
  for(auto i : second){
    if(first.find(i)==first.end()){
      temp.push_back(i);
    }
  }
  ans.push_back(temp);
  return ans;
}

int main() { return 0; }
