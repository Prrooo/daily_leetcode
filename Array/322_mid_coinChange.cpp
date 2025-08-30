#include <bits/stdc++.h>
using namespace std;

// review
// dp solutin for fine

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> minCoin(amount + 1, amount + 1);
    minCoin[0] = 0;
    int n = coins.size();
    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < n; j++) {
        if (i - coins[j] >= 0) {
          minCoin[i] = min(minCoin[i], 1 + minCoin[i - coins[j]]);
        }
      }
    }
    return minCoin[amount] != (amount + 1) ? minCoin[amount] : -1;
  }
};

// this is the greedy solution not work all the time
// brute force solution

int coinChange(vector<int> &coins, int amount) {
  sort(coins.begin(), coins.end());
  int n = coins.size();
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (coins[i] <= amount) {
      ans += amount / coins[i];
      amount %= coins[i];
    }
    if (amount == 0)
      return ans;
  }
  if (amount == 0)
    return ans;
  return -1;
}

int main() { return 0; }
