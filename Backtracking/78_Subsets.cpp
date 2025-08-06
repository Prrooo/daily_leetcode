#include <bits/stdc++.h>
#include <vector>
using namespace std;

void solve(vector<vector<int>> &result,vector<int> temp,vector<int> &arr,int index,int n){
  result.push_back(temp); 
  for(int i=index;i<n;i++){
    temp.push_back(arr[i]);
    solve(result,temp,arr,i+1,n);
    temp.pop_back();
  }
}

vector<vector<int>> subsets(vector<int> &arr) {
  vector<vector<int>> result;
  vector<int> temp;
  solve(result,temp,arr,0,arr.size());
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  vector<vector<int>> result = subsets(arr);
  for (auto i : result) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
