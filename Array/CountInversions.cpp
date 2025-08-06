// https://www.naukri.com/code360/problems/count-inversions_615
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int n){
  set<int> st;
  int count=0;
  for(int i=0;i<n;i++){
    st.insert(arr[i]);
    count+=distance(st.find(arr[i]),st.end())-1;
  }
  return count;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back(x);
  }
  cout<<solve(arr,n);
  return 0;
}
