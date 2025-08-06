#include <bits/stdc++.h>
using namespace std;

// brute force solution high time complexity

// double myPow(double x, int n) {
//   double result = 1;
//   for (int i = 0; i < abs(n); i++) {
//     result *= x;
//   }
//   return n > 0 ? result : 1 / result;
// }

// best solution
// time complexity : O(log(n))

double solve(double x, long long n) {
  if (n == 1)
    return x;
  double ans = solve(x, n / 2);
  return n % 2 == 0 ? ans * ans : x * ans * ans;
}

double myPow(double x, int n) {
  long long N = n;
  if (n == 0) {
    return 1;
  } else if (N < 0) {
    return 1 / solve(x, abs(N));
  }
  return solve(x, n);
}

int main() {
  double x;
  int n;
  cin >> x >> n;
  cout << myPow(x, n);
  return 0;
}
