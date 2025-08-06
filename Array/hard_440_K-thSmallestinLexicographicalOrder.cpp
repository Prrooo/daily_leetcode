#include <bits/stdc++.h>
using namespace std;

// correction soluton but TLE my solution 

int solve(int n, int k, int start, int &count) {
  if (start > n)
    return -1;
  count++;
  if (count == k)
    return start;
  for (int i = 0; i <= 9; i++) {
    int newStart = start * 10 + i;
    int temp = solve(n, k, newStart, count);
    if (temp != -1)
      return temp;
  }
  return -1;
}

int findKthNumber(int n, int k) {
  int count = 0;
  for (int i = 1; i <= 9; i++) {
    int temp = solve(n, k, i, count);
    if (temp != -1)
      return temp;
  }
  return -1;
}

int main() { return 0; }
