#include<bits/stdc++.h>
#include <numeric>
using namespace std;
int main(){
  unordered_set<int> st;
  vector<int> arr={1,3,10,5,2};
  int total=accumulate(arr.begin(),arr.end(),0);
  cout<<total;
  return 0;
}
