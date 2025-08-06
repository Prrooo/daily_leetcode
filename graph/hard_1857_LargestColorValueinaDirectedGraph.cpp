// https://www.youtube.com/watch?v=KeSEjmpCaP8

// There is a directed graph of n colored nodes and m edges. The nodes are
// numbered from 0 to n - 1.
//
// You are given a string colors where colors[i] is a lowercase English letter
// representing the color of the ith node in this graph (0-indexed). You are
// also given a 2D array edges where edges[j] = [aj, bj] indicates that there is
// a directed edge from node aj to node bj.
//
// A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk
// such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The
// color value of the path is the number of nodes that are colored the most
// frequently occurring color along that path.
//
// Return the largest color value of any valid path in the given graph, or -1 if
// the graph contains a cycle.
//
// Example 1:
//
//
// Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
// Output: 3
// Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a"
// (red in the above image). Example 2:
//
//
//
// Input: colors = "a", edges = [[0,0]]
// Output: -1
// Explanation: There is a cycle from 0 to 0.
//

#include <bits/stdc++.h>
using namespace std;
// optimal solution

class Solution {
public:
  int solve(string &colors, vector<vector<int>> &ed,
            vector<vector<int>> &eleColor, vector<int> &visit, int index) {
    if (visit[index] == 0) {
      visit[index] = 1;
      for (auto i : ed[index]) {
        if (solve(colors, ed, eleColor, visit, i) == -1)
          return -1;
        for (int j = 0; j < 27; j++) {
          eleColor[index][j] = max(eleColor[index][j], eleColor[i][j]);
        }
      }
      eleColor[index][colors[index] - 'a']++;
      visit[index] = 2;
    }
    return visit[index] == 1 ? -1 : INT_MIN;
  }

  int largestPathValue(string colors, vector<vector<int>> &edges) {
    int n = colors.size();
    vector<vector<int>> ed(n), eleColor(n, vector<int>(27, 0));
    for (auto i : edges) {
      ed[i[0]].push_back(i[1]);
    }
    vector<int> visit(n, 0);
    for (int i = 0; i < n; i++) {
      if (solve(colors, ed, eleColor, visit, i) == -1) {
        return -1;
      }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 27; j++) {
        ans = max(ans, eleColor[i][j]);
      }
    }
    return ans;
  }
};

// correct solution but TLE

// int solve(string colors,vector<vector<int>> ed,vector<int>& visit,int
// index,int arr[],vector<int> tempVisit){
//   visit[index]=1;
//   if(ed[index].size()==0){
//     int temMax=0;
//     for(int i=0;i<27;i++){
//       if(arr[i]>temMax) temMax=arr[i];
//     }
//     return temMax;
//   }
//   else if(tempVisit[index]==1){
//     return -1;
//   }
//   tempVisit[index]=1;
//   arr[colors[index]-'a']++;
//   int tempSum=0;
//   for(auto i : ed[index]){
//     int temp=solve(colors,ed,visit,i,arr,tempVisit);
//     if(temp==-1) return temp;
//     tempSum=max(tempSum,temp);
//   }
//   return tempSum;
// }
//
// int largestPathValue(string colors, vector<vector<int>> &edges) {
//   int n=colors.size(),ans=0;
//   vector<vector<int>> ed(n);
//   for(auto i : edges){
//     ed[i[0]].push_back(i[1]);
//   }
//   vector<int> visit(n,0);
//   int arr[27]={0};
//   for(int i=0;i<n;i++){
//     if(visit[i]==0){
//       vector<int> tempVisit(n,0);
//       ans=max(ans,solve(colors,ed,visit,i,arr,tempVisit));
//     }
//   }
//   return ans;
// }

int main() { return 0; }
