#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maximumHappinessSum(vector<int> &arr, int k) {
    int n = arr.size();
    long long ans = 0;
    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < n; i++) {
      if ((arr[i] - i) <= 0 || k <= 0)
        break;
      ans = ans + arr[i] - i;
      k--;
    }
    return ans;
  }
};

int main() { return 0; }
