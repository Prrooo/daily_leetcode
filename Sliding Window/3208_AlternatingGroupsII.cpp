#include <bits/stdc++.h>
using namespace std;

// as expected this method run into time limit exceeded

// int numberOfAlternatingGroups(vector<int> &colors, int k) {
//   int n=colors.size(),count=0;
//   if(k>n){
//     return 0;
//   }
//   for(int i=0;i<n;i++){
//     int j=i;
//     while(j-i<k){
//       if(j==i || colors[j%n]!=colors[(j-1)%n]){
//         j++;
//       }
//       else{
//         break;
//       }
//     }
//     if(j-i==k) count++;
//     else{
//       i=j;
//     }
//   }
//   return count;
// }

// my best solution to this problem using two pointer

int numberOfAlternatingGroups(vector<int> &colors, int k) {
  int n = colors.size(), count = 0;
  if (k > n) {
    return 0;
  }
  int i = 0, j = 0;
  while (i < n) {
    if (i == j) {
      j++;
    }
    // if the gap between the i and j pointer is less than k and the next tile
    // is of opposite color

    else if (j - i < k && colors[j % n] != colors[(j - 1) % n]) {
      j++;
    }
    // is the gap between i and j pointer is less than k but the next tile is of
    // same color than we move i equal to j

    else if (j - i < k && colors[j % n] == colors[(j - 1) % n]) {
      i = j;
    }
    // we get to else only and only if the gap is equal or larger than k between
    // the two pointer then we move i forward and increase the count that we
    // successfully find the group in which there are k continous alternative
    // tiles

    else {
      i++;
      count++;
    }
  }
  return count;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << numberOfAlternatingGroups(arr, k);
  return 0;
}
