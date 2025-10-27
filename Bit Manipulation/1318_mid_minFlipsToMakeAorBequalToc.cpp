#include <bits/stdc++.h>
using namespace std;

// it work but i am sure better solutin exists

class Solution {
public:
  int minFlips(int a, int b, int c) {
    bitset<30> bt(a | b);
    bitset<30> comp(c);
    int count = 0;
    for (int i = 0; i <= 30; i++) {
      if (bt[i] != comp[i]) {
        if (comp[i] == 1) {
          count++;
        } else if (a & 1 << i && b & 1 << i) {
          count += 2;
        } else {
          count++;
        }
      }
    }
    return count;
  }
};

int main() { return 0; }
