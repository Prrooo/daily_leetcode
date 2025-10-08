#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int totalBottle = numBottles;
    while (numBottles >= numExchange) {
      numBottles -= numExchange++;
      totalBottle++;
      numBottles++;
    }
    return totalBottle;
  }
};

int main() { return 0; }
