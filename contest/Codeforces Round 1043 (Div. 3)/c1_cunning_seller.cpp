#include <iostream>
using namespace std;

typedef unsigned long long ll;

ll p[50];
ll cost[50];

void precompute() {
  p[0] = 1;
  for (int i = 1; i < 50; i++) {
    p[i] = p[i - 1] * 3;
  }
  cost[0] = 3;
  for (int i = 1; i < 50; i++) {
    cost[i] = p[i + 1] + i * p[i - 1];
  }
}

int main() {
  precompute();
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll total_cost = 0;
    int index = 0;
    while (n > 0) {
      int digit = n % 3;
      total_cost += digit * cost[index];
      n /= 3;
      index++;
    }
    cout << total_cost << endl;
  }
  return 0;
}
