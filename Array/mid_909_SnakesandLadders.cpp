#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& board,int minDis,int row,int col,int n){
  if(((n-row)*n)+(n-col)>=n*n) return minDis;

}

int snakesAndLadders(vector<vector<int>>& board) {
  int minDis=0;
  int n=board.size();
  return solve(board,minDis,n-1,0,n);
}

int main(){
  return 0;
}
