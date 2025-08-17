#include <bit>
#include <bits/stdc++.h>
#include <bitset>
using namespace std;

// using bit manipulation
class Solution {
public:
  bool isPowerOfFour(int n) {
    // popcount return no. of set bit in the number or you can use bitset
    // return n > 0 && popcount((unsigned)n) == 1 && (n - 1) % 3 == 0;

    bitset<31> x(n);
    if (x.count() != 1)
      return false;
    return n > 0 && (n - 1) % 3 == 0;
  }
};

// works but there is better solution to this problem
// using bit manipulation

bool isPowerOfFour(int n) {
  if (n <= 0)
    return false;
  while (n > 1) {
    if (n % 4 != 0)
      return false;
    n = n / 4;
  }
  return true;
}

int main() { return 0; }
