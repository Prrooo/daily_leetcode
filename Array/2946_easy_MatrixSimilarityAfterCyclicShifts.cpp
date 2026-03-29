#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool areSimilar(vector<vector<int>> &mat, int k) {
    int n = mat.size(), m = mat[0].size();
    for (int i = 0; i < n; i++) {
      int index = i == 0 || i % 2 == 0 ? m - (k % m) : k % m;
      for (int j = 0; j < m; j++) {
        if (mat[i][j] != mat[i][index % m])
          return false;
        index++;
      }
    }
    return true;
  }
};

int main() { return 0; }
