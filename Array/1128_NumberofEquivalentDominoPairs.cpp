// Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] =
// [c, d] if and only if either (a == c and b == d), or (a == d and b == c) -
// that is, one domino can be rotated to be equal to another domino.
//
// Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and
// dominoes[i] is equivalent to dominoes[j].
//
//
//
// Example 1:
//
// Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
// Output: 1
// Example 2:
//
// Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
// Output: 3
//

#include <bits/stdc++.h>
using namespace std;

int numEquivDominoPairs(vector<vector<int>> &di) {
  int n = di.size(), count = 0;
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    if (di[i][0] > di[i][1])
      swap(di[i][0], di[i][1]);
    count += mp[{di[i][0], di[i][1]}]++;
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> arr;
  for (int i = 0; i < n; i++) {
    vector<int> temp;
    for (int i = 0; i < 2; i++) {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    arr.push_back(temp);
  }
  cout << numEquivDominoPairs(arr);
  return 0;
}
