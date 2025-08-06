
#include<bits/stdc++.h>
using namespace std;

int valueKBit(int n,int k){
  return (n>>(k-1))&1 ? 1 : 0;
}

int main(){
  int n,k;
  cin>>n>>k;
  cout<<valueKBit(n,k);
  return 0;
}
