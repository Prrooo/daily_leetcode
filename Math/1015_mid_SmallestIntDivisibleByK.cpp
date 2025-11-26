#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int smallestRepunitDivByK(int k) {
    long long curr = 1;
    int count = 1;

    // if we continue after k time we for certina know that the remander repeat
    // itself therefore we return -1;

    while (count <= k) {
      if (curr % k == 0)
        return count;
      curr %= k;
      curr = curr * 10 + 1;
      count++;
    }
    return -1;
  }
};

int main() { return 0; }
