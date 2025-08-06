#include<bits/stdc++.h>
using namespace std;

void solveSudoku(vector<vector<char>>& board){

}

int main(){
  vector<vector<char>> arr;
  for(int i=0;i<9;i++){
    vector<char> temp;
    for(int j=0;j<9;j++){
      char c;
      cin>>c;
      temp.push_back(c); 
    }
    arr.push_back(temp);
  }
  cout<<solveSudoku(arr);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
