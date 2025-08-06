// Given an integer n, return the number of prime numbers that are strictly less
// than n.
//
// Example 1:
//
// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:
//
// Input: n = 0
// Output: 0
// Example 3:
//
// Input: n = 1
// Output: 0

#include <bits/stdc++.h>
using namespace std;

// again this code face the issue of TIME LIMIT EXCEEDED
// to solve this problem we first calculate all the prime number upto the given
// number then count the prime between the 0 to n
//
// https://www.youtube.com/watch?v=MJcckSfoYdI
// video solution to find prime effectively 

int countPrimes(int n) {
  if (n == 0 || n == 1) {
    return 0;
  }
  vector<bool> is_prime(n, true);
  is_prime[0]=is_prime[1]=false;
  for (int i = 2; i * i < n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j < n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (is_prime[i]) {
      count++;
    }
  }
  return count;
}

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

// int countPrimes(int n) {
//   int count = 0;
//   for (int i = 0; i < n; i++) {
//     if (isPrime(i)) {
//       count++;
//     }
//   }
//   return count;
// }

int main() {
  int n;
  cin >> n;
  cout << countPrimes(n);
  return 0;
}
