#include <bits/stdc++.h>
using namespace std;

long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs) {
  int totalSubArray = (n * (n + 1)) / 2;
  int ans = 0;
  for (auto i : conflictingPairs) {
    int a, b;
    if (i[0] > i[1]) {
      a = i[0], b = i[1];

    } else {
      a = i[1], b = i[0];
    }
    int preSubArray = (a * (a + 1)) / 2, afterSubArray = (b * (b + 1)) / 2;
    ans = max(ans, totalSubArray - (preSubArray + afterSubArray));
  }
  return ans;
}

int main() { return 0; }
