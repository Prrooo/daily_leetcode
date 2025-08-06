#include <bits/stdc++.h>
#include <climits>
using namespace std;

bool isPrime(int n) {
  if (n == 0 || n == 1) {
    return false;
  }
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

// correct but time limit exceeded error 
// therefor not recommended

vector<int> closestPrimes(int left, int right) {
  int onePrime = -1, minRes = INT_MAX;
  vector<int> result(2, -1);
  for (int i = left; i <= right; i++) {
    if (isPrime(i)) {
      if (onePrime == -1)
        onePrime = i;
      else {
        if (minRes > abs(onePrime - i)) {
          result[0] = onePrime;
          result[1] = i;
          minRes = abs(onePrime - i);
        }
        onePrime = i;
      }
    }
  }
  return result;
}

int main() {
  int l, r;
  cin >> l >> r;
  vector<int> result = closestPrimes(l, r);
  cout << result[0] << " " << result[1];
  return 0;
}
